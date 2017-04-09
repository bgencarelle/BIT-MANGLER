# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\ben\Documents\PSoC Creator\New Pedal Thingz\PSOC_BIT_MANGLER\ADC_DAC.cydsn\ADC_DAC.cyprj
# Date: Sun, 09 Apr 2017 12:56:06 GMT
#set_units -time ns
create_clock -name {ADC_REG_CLOCK(routed)} -period 770.83333333333326 -waveform {0 385.416666666667} [list [get_pins {ClockBlock/dclk_2}]]
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_generated_clock -name {SPI_DAC_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 3 5} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {Clock_2} -source [get_pins {ClockBlock/clk_sync}] -edges {1 5 9} [list [get_pins {ClockBlock/dclk_glb_1}]]
create_generated_clock -name {ADC_REG_CLOCK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 37 75} -nominal_period 770.83333333333326 [list [get_pins {ClockBlock/dclk_glb_2}]]
create_clock -name {ADC_REG_CLOCK(fixed-function)} -period 770.83333333333326 -waveform {0 20.8333333333333} -nominal_period 770.83333333333326 [get_pins {ClockBlock/dclk_glb_ff_2}]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for C:\Users\ben\Documents\PSoC Creator\New Pedal Thingz\PSOC_BIT_MANGLER\ADC_DAC.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\ben\Documents\PSoC Creator\New Pedal Thingz\PSOC_BIT_MANGLER\ADC_DAC.cydsn\ADC_DAC.cyprj
# Date: Sun, 09 Apr 2017 12:55:37 GMT
