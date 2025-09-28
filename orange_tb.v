`timescale 1ns/1ps

module tb;

    reg clk;
    reg reset;
    reg [1:0] coin;
    wire dispense;

    // Instantiate vending machine
    vending_machine uut (
        .clk(clk),
        .reset(reset),
        .coin(coin),
        .dispense(dispense)
    );

    integer infile;
    integer cval;
    integer status;

    // Clock generation
    initial begin
        clk = 0;
        forever #5 clk = ~clk; // 10ns period
    end

    initial begin
        // Open input file
        infile = $fopen("coins_input.txt", "r");
        if (infile == 0) begin
            $display("ERROR: Could not open coins_input.txt");
            $finish;
        end

        // Initialize
        reset = 1; coin = 2'b00;
        #10 reset = 0;

        // Read coins one by one
        while (!$feof(infile)) begin
            status = $fscanf(infile, "%d\n", cval);
            if (status == 1) begin
                if (cval == 5) coin = 2'b01;
                else if (cval == 10) coin = 2'b10;
                else coin = 2'b00;

                // One clock cycle
                @(posedge clk);
                $display("%d", dispense); // print result for Python to parse

                // Clear coin input (no coin next cycle)
                coin = 2'b00;
                @(posedge clk);
            end
        end

        $fclose(infile);
        $finish;
    end
endmodule
