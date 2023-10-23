module mem_ddr (
    input               clk,
    input               rstn,
    input               mem_wr_en,
    input       [2:0]   mem_rw_type,

    input       [31:0]  mem_data_addr,
    input       [31:0]  mem_data_in,
    output      [31:0]  mem_data_out,

    input       [31:0]  mem_inst_addr,
    output      [31:0]  mem_inst_out
);

    localparam MEM_WIDTH = 1 << 13;

    reg [31:0] ram [MEM_WIDTH-1:0];

    initial begin
        $readmemb("/home/sgap/ysyx-workbench/npc/vsrc/mem.init", ram);
    end
    
    wire    [31:0] rd_data;
    reg     [31:0] wr_data_byte;
    wire    [31:0] wr_data_half_word;
    wire    [31:0] wr_data;

    assign rd_data = ram[mem_data_addr[31:2]];

    always @(*) begin
        case(mem_data_addr[1:0])
            2'b00:  wr_data_byte = {rd_data[31:8], mem_data_in[7:0]};
            2'b01:  wr_data_byte = {rd_data[31:16], mem_data_in[7:0], rd_data[7:0]};
            2'b10:  wr_data_byte = {rd_data[31:24], mem_data_in[7:0], rd_data[15:0]};
            2'b11:  wr_data_byte = {mem_data_in[7:0], rd_data[23:0]};
        endcase
    end

    assign wr_data_half_word = (mem_data_addr[1]) ? {mem_data_in[15:0], rd_data[15:0]} : {rd_data[31:16], mem_data_in[15:0]};

    assign wr_data = (mem_rw_type[1:0] == 2'b00) ? wr_data_byte :
                     (mem_rw_type[1:0] == 2'b01) ? wr_data_half_word :
                     mem_data_in;

    always @(posedge clk) begin
        if(mem_wr_en)
            ram[mem_data_addr[31:2]] <= wr_data;
    end

    reg     [7:0] rd_data_byte;
    wire    [15:0] rd_data_half_word;

    // extended read data
    wire    [31:0] rd_data_byte_ext;
    wire    [31:0] rd_data_half_word_ext;

    always @(*) begin
        case(mem_data_addr[1:0])
            2'b00:  rd_data_byte = rd_data[7:0];
            2'b01:  rd_data_byte = rd_data[15:8];
            2'b10:  rd_data_byte = rd_data[23:16];
            2'b11:  rd_data_byte = rd_data[31:24];
        endcase
    end

    assign rd_data_half_word = (mem_data_addr[1]) ? rd_data[31:16] : rd_data[15:0];

    assign rd_data_byte_ext = (mem_rw_type[2]) ? {24'd0, rd_data_byte} : {{24{rd_data_byte[7]}}, rd_data_byte};
    assign rd_data_half_word_ext = (mem_rw_type[2]) ? {16'd0, rd_data_half_word} : {{16{rd_data_half_word[15]}}, rd_data_half_word};

    assign mem_data_out = (mem_rw_type[1:0] == 2'b00) ? rd_data_byte_ext :
                          (mem_rw_type[1:0] == 2'b01) ? rd_data_half_word_ext :
                          rd_data;

    assign mem_inst_out = ram[mem_inst_addr[31:2]];

endmodule //mem_ddr