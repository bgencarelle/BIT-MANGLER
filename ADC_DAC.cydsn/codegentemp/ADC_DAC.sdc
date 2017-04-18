# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\ben\Documents\PSoC Creator\New Pedal Thingz\PSOC_BIT_MANGLER\BIT-MANGLER\ADC_DAC.cydsn\ADC_DAC.cyprj
# Date: Mon, 17 Apr 2017 20:17:59 GMT
#set_units -time ns
create_clock -name {ADC_REG_CLOCK(routed)} -period 312.5 -waveform {0 156.25} [list [get_pins {ClockBlock/dclk_1}]]
create_clock -name {ADC_SAR_Seq_IntClock(routed)} -period 1000 -waveform {0 500} [list [get_pins {ClockBlock/dclk_2}]]
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_generated_clock -name {SPI_DAC_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 3 7} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {ADC_REG_CLOCK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 15 31} [list [get_pins {ClockBlock/dclk_glb_1}]]
create_clock -name {ADC_REG_CLOCK(fixed-function)} -period 312.5 -waveform {0 20.8333333333333} [get_pins {ClockBlock/dclk_glb_ff_1}]
create_generated_clock -name {ADC_SAR_Seq_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 49 97} [list [get_pins {ClockBlock/dclk_glb_2}]]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for C:\Users\ben\Documents\PSoC Creator\New Pedal Thingz\PSOC_BIT_MANGLER\BIT-MANGLER\ADC_DAC.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\ben\Documents\PSoC Creator\New Pedal Thingz\PSOC_BIT_MANGLER\BIT-MANGLER\ADC_DAC.cydsn\ADC_DAC.cyprj
# Date: Mon, 17 Apr 2017 20:17:38 GMT
