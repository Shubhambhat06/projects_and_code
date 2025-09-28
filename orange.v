module vending_machine(
    input clk,
    input reset,
    input [1:0] coin,   // 00 = no coin, 01 = 5₹, 10 = 10₹
    output reg dispense
);

    reg [1:0] state, next_state;

    // State encoding
    parameter S0 = 2'b00, S5 = 2'b01, S10 = 2'b10, S15 = 2'b11;

    // State register
    always @(posedge clk or posedge reset) begin
        if (reset)
            state <= S0;
        else
            state <= next_state;
    end

    // Next state logic
    always @(*) begin
        dispense = 0;
        case (state)
            S0: begin
                if (coin == 2'b01) next_state = S5;
                else if (coin == 2'b10) next_state = S10;
                else next_state = S0;
            end

            S5: begin
                if (coin == 2'b01) next_state = S10;
                else if (coin == 2'b10) begin
                    next_state = S0;
                    dispense = 1;
                end else next_state = S5;
            end

            S10: begin
                if (coin == 2'b01) begin
                    next_state = S0;
                    dispense = 1;
                end else if (coin == 2'b10) begin
                    next_state = S0;
                    dispense = 1;
                end else next_state = S10;
            end

            default: begin
                next_state = S0;
                dispense = 0;
            end
        endcase
    end

endmodule
