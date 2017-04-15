
//`#start header` -- edit after this line, do not edit this line
// ========================================
//
// Copyright YOUR COMPANY, THE YEAR
// All Rights Reserved
// UNPUBLISHED, LICENSED SOFTWARE.
//
// CONFIDENTIAL AND PROPRIETARY INFORMATION
// WHICH IS THE PROPERTY OF your company.
//
// ========================================
`include "cypress.v"
//`#end` -- edit above this line, do not edit this line
// Generated on 04/14/2017 at 13:36
// Component: Cheap_PWM
module Cheap_PWM (
	output  reg pwm_out,
    input   wire clk,
	input   wire bit_input,
	input  wire [3:0] period
);

//`#start body` -- edit after this line, do not edit this line
    
    reg   [4:0] period_counter;
    reg   [3:0] duty;
    reg  [3:0] in_period;
    
       always@(posedge bit_input)
       begin
                period_counter <= period_counter + 1'b1;
                in_period <= period;
                duty <= in_period/2;
        
        end
        wire pwm;
        assign pwm = (period == 4'b0)? bit_input : (period_counter <= duty ) ? 1'b0: 1'b1;
       
// synchronuous pwm output to ...
        always@(pwm)
            pwm_out <= pwm;
            
             
//        Your code goes here

//`#end` -- edit above this line, do not edit this line
endmodule
//`#start footer` -- edit after this line, do not edit this line
//`#end` -- edit above this line, do not edit this line
