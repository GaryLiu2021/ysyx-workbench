// `define __DEBUG
import "DPI-C" function void set_inst_ptr(input logic [31:0] inst []);
import "DPI-C" function void call_ebreak();

module single_cycle_cpu (
    input           clk,
    input           rstn
);

// reg_pc Outputs
wire  [31:0]  pc_out;

// stage_decode Outputs
wire  [6:0]  opcode;
wire  [5:0]  op_type;
wire  [2:0]  func3;
wire  func7;
wire  [4:0]  reg_addr_rs1;
wire  [4:0]  reg_addr_rs2;
wire  [4:0]  reg_addr_rd;
wire  [31:0]  imme;

// regs Outputs
wire  [31:0]  reg_data_rs1;
wire  [31:0]  reg_data_rs2;

// stage_execute Outputs   
wire  [31:0]  alu_data_out;
wire  [31:0]  alu_pc_out;
wire  [31:0]  alu_pc_seq;

// stage_loadstore Outputs
wire  [31:0]  mem_data_in;
wire  [31:0]  mem_data_addr;        
wire  mem_data_wr_en;

// mem_ddr Outputs
wire  [31:0]  mem_data_out;
wire  [31:0]  mem_inst_out;

wire  [31:0] csr_rd_data;

reg_pc  u_reg_pc (
    .clk                     ( clk          ),
    .rstn                    ( rstn         ),
    .op_type                 ( op_type      ),
    .alu_data_out            ( alu_data_out ),
    .alu_pc_out              ( alu_pc_out   ),
    .alu_pc_seq              ( alu_pc_seq   ),

    .pc_out                  ( pc_out       )
);

stage_decode  u_stage_decode (
    .inst                    ( mem_inst_out   ),

    .opcode                  ( opcode         ),
    .func3                   ( func3          ),
    .func7                   ( func7          ),
    .reg_addr_rs1            ( reg_addr_rs1   ),
    .reg_addr_rs2            ( reg_addr_rs2   ),
    .reg_addr_rd             ( reg_addr_rd    ),
    .op_type                 ( op_type        ),
    .imme                    ( imme           )
);


regs  u_regs (
    .clk                     ( clk            ),
    .rstn                    ( rstn           ),
    .reg_addr_rs1            ( reg_addr_rs1   ),
    .reg_addr_rs2            ( reg_addr_rs2   ),
    .reg_addr_rd             ( reg_addr_rd    ),
    .alu_data_out            ( alu_data_out   ),
    .alu_pc_out              ( alu_pc_out     ),
    .imme                    ( imme           ),
    .alu_pc_seq              ( alu_pc_seq     ),
    .mem_data_out            ( mem_data_out   ),
    .csr_data_out            ( csr_rd_data    ),
    .op_type                 ( op_type        ),
    .opcode                  ( opcode         ),

    .reg_data_rs1            ( reg_data_rs1   ),
    .reg_data_rs2            ( reg_data_rs2   )
);

csrs_csr u_regs_csr (
    .clk                (clk),
    .rstn               (rstn),
    .csr_rd_data        (csr_rd_data),
    .reg_data_rs1       (reg_data_rs1),
    .imme               (imme),

    .op_type            (op_type),
    .opcode             (opcode)
);

 
stage_execute  u_stage_execute (
    .opcode                  ( opcode         ),
    .imme                    ( imme           ),
    .reg_data_rs1            ( reg_data_rs1   ),
    .reg_data_rs2            ( reg_data_rs2   ),
    .reg_data_pc             ( pc_out         ),
    .op_type                 ( op_type        ),

    .alu_data_out            ( alu_data_out   ),
    .alu_pc_out              ( alu_pc_out     ),
    .alu_pc_seq              ( alu_pc_seq     )
);

     
stage_loadstore  u_stage_loadstore (
    .alu_data_out            ( alu_data_out       ),
    .op_type                 ( op_type            ),
    .reg_data_rs2            ( reg_data_rs2       ),

    .mem_data_in             ( mem_data_in        ),
    .mem_data_addr           ( mem_data_addr      ),
    .mem_data_wr_en          ( mem_data_wr_en     )
);


mem_ddr  u_mem_ddr (
    .clk                     ( clk             ),
    .rstn                    ( rstn            ),
    .mem_wr_en               ( mem_data_wr_en  ),
    .mem_rw_type             ( func3           ),
    .mem_data_addr           ( mem_data_addr   ),
    .mem_data_in             ( mem_data_in     ),
    .mem_inst_addr           ( pc_out          ),

    .mem_inst_out            ( mem_inst_out    ),
    .mem_data_out            ( mem_data_out    )
);


    always @(posedge clk) begin
        if(mem_inst_out == 32'b00000000000100000000000001110011)
            call_ebreak();
        if(mem_inst_out == 32'b00000000000000000000000001110011)
            call_ecall();
    end

`ifdef ___DEBUG

    reg [63:0] counter;
    initial begin
        counter = 'd0;
    end

`include "./util"

    always @(posedge clk or negedge rstn) begin
        if(!rstn)
            counter <= 'd1;
        else begin
            counter <= counter + 1'b1;
            $display("\n\t\t\tCycle %0d\n", counter);
            case(opcode)
                `system:
                    case(op_type)
                        `op_type_csrrc,`op_type_csrrs,`op_type_csrrw:
                            $display("Addr: %h Inst: %b, %0s %0s,%0d,%0s\n%0s:%0d", pc_out, mem_inst_out, inst_str[op_type], reg_name[reg_addr_rd], $signed(imme[16:5]), reg_name[reg_addr_rs1], reg_name[reg_addr_rs1], reg_data_rs1);
                        `op_type_csrrci,`op_type_csrrsi,`op_type_csrrwi:
                            $display("Addr: %h Inst: %b, %0s %0s,%0d,%0d", pc_out, mem_inst_out, inst_str[op_type], reg_name[reg_addr_rd], $signed(imme[16:5]), $signed(imme[4:0]));
                        default:
                            $display("Addr: %h Inst: %b, %0s", pc_out, mem_inst_out, inst_str[op_type]);
                    endcase
                `alur:
                    $display("Addr: %h Inst: %b, %0s %0s,%0s,%0s", pc_out, mem_inst_out, inst_str[op_type], reg_name[reg_addr_rd], reg_name[reg_addr_rs1], reg_name[reg_addr_rs2]);
                `jalr, `load, `fence:
                    $display("Addr: %h Inst: %b, %0s %0s,%0d(%0s)", pc_out, mem_inst_out, inst_str[op_type], reg_name[reg_addr_rd], $signed(imme), reg_name[reg_addr_rs1]);
                `branch:
                    $display("Addr: %h Inst: %b, %0s %0s,%0s,%0d", pc_out, mem_inst_out, inst_str[op_type], reg_name[reg_addr_rs1], reg_name[reg_addr_rs2], $signed(imme));
                `store:
                    $display("Addr: %h Inst: %b, %0s %0s,%0d(%0s)", pc_out, mem_inst_out, inst_str[op_type], reg_name[reg_addr_rs2], $signed(imme), reg_name[reg_addr_rs1]);
                `jal, `auipc, `lui:
                    $display("Addr: %h Inst: %b, %0s %0s,%0d", pc_out, mem_inst_out, inst_str[op_type], reg_name[reg_addr_rd], $signed(imme));
                `alui:
                    $display("Addr: %h Inst: %b, %0s %0s,%0s,%0d", pc_out, mem_inst_out, inst_str[op_type], reg_name[reg_addr_rd], reg_name[reg_addr_rs1], $signed(imme));
                default:
                    $display("Addr: %h Inst: %b\nUnkwown Type!\n", pc_out, mem_inst_out);
            endcase
            if(opcode == `store)
                $display("mem_addr: %d, mem_data_in: %d, mem_data_out: %d", mem_data_addr, mem_data_in, mem_data_out);
            else if(opcode == `load)
                $display("mem_addr: %d, mem_data_out: %d", mem_data_addr, mem_data_out);
        end
    end

`endif

    initial set_inst_ptr(mem_inst_out);

endmodule //single_cycle_cpu