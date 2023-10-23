module sim(
    input clk
);

reg rstn = 0;

// always #(1) clk = ~clk;

single_cycle_cpu  u_single_cycle_cpu (  
    .clk                     ( clk    ),
    .rstn                    ( rstn   ) 
);

initial begin
    repeat(1) @(posedge clk);
    rstn = 1;
    #(10000);
    $display("Time Out!!!");
    $finish;
end

initial begin
    $dumpfile("wave.vcd");
    $dumpvars;
end

endmodule //sim