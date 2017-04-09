#include "Filter_1.h"
#include "Filter_1_PVT.h"


/*******************************************************************************
* ChannelA filter coefficients.
* Filter Type is: Biquad
*******************************************************************************/

/* Renamed array for backward compatibility.
*  Should not be used in new designs.
*/
#define ChannelABiquadCoefficients Filter_1_ChannelABiquadCoefficients

/* Number of Biquad sections are: 8 */

const uint8 CYCODE Filter_1_ChannelABiquadCoefficients[Filter_1_BIQUAD_A_SIZE] = 
{
 /* Coefficients of Section 0 */
 0xB8u, 0x67u, 0x06u, 0x00u, /* Section(0)_A0, 0.100080490112305 */

 0x70u, 0xCFu, 0x0Cu, 0x00u, /* Section(0)_A1, 0.200160980224609 */

 0xB8u, 0x67u, 0x06u, 0x00u, /* Section(0)_A2, 0.100080490112305 */

 0x9Bu, 0x20u, 0xE7u, 0x00u, /* Section(0)_B1, 0.388634920120239 */

 0x02u, 0x57u, 0xEFu, 0x00u, /* Section(0)_B2, 0.260314464569092 */

 /* Coefficients of Section 1 */
 0xB8u, 0x35u, 0x18u, 0x00u, /* Section(1)_A0, 0.378278732299805 */

 0x6Fu, 0x6Bu, 0x30u, 0x00u, /* Section(1)_A1, 0.75655722618103 */

 0xB8u, 0x35u, 0x18u, 0x00u, /* Section(1)_A2, 0.378278732299805 */

 0x5Du, 0x26u, 0xECu, 0x00u, /* Section(1)_B1, 0.310158491134644 */

 0xA8u, 0x7Cu, 0xF5u, 0x00u, /* Section(1)_B2, 0.164266586303711 */

 /* Coefficients of Section 2 */
 0x54u, 0x3Cu, 0x1Cu, 0x00u, /* Section(2)_A0, 0.441182136535645 */

 0xA7u, 0x78u, 0x38u, 0x00u, /* Section(2)_A1, 0.88236403465271 */

 0x54u, 0x3Cu, 0x1Cu, 0x00u, /* Section(2)_A2, 0.441182136535645 */

 0x33u, 0x7Au, 0xDFu, 0x00u, /* Section(2)_B1, 0.508166551589966 */

 0x84u, 0x5Au, 0xE6u, 0x00u, /* Section(2)_B2, 0.400725364685059 */

 /* Coefficients of Section 3 */
 0xB5u, 0x78u, 0x17u, 0x00u, /* Section(3)_A0, 0.366742372512817 */

 0x6Au, 0xF1u, 0x2Eu, 0x00u, /* Section(3)_A1, 0.733484745025635 */

 0xB5u, 0x78u, 0x17u, 0x00u, /* Section(3)_A2, 0.366742372512817 */

 0xB9u, 0x87u, 0xEFu, 0x00u, /* Section(3)_B1, 0.257341146469116 */

 0xB9u, 0xC1u, 0xF9u, 0x00u, /* Section(3)_B2, 0.0975511074066162 */

 /* Coefficients of Section 4 */
 0x27u, 0x72u, 0x14u, 0x00u, /* Section(4)_A0, 0.319467306137085 */

 0x4Eu, 0xE4u, 0x28u, 0x00u, /* Section(4)_A1, 0.63893461227417 */

 0x27u, 0x72u, 0x14u, 0x00u, /* Section(4)_A2, 0.319467306137085 */

 0x90u, 0xC4u, 0xF1u, 0x00u, /* Section(4)_B1, 0.222377777099609 */

 0xABu, 0xA6u, 0xFCu, 0x00u, /* Section(4)_B2, 0.0523273944854736 */

 /* Coefficients of Section 5 */
 0x34u, 0x9Au, 0x13u, 0x00u, /* Section(5)_A0, 0.306286811828613 */

 0x69u, 0x34u, 0x27u, 0x00u, /* Section(5)_A1, 0.612573862075806 */

 0x34u, 0x9Au, 0x13u, 0x00u, /* Section(5)_A2, 0.306286811828613 */

 0x49u, 0x23u, 0xF3u, 0x00u, /* Section(5)_B1, 0.200971364974976 */

 0xEDu, 0x73u, 0xFEu, 0x00u, /* Section(5)_B2, 0.0241744518280029 */

 /* Coefficients of Section 6 */
 0x15u, 0x39u, 0x13u, 0x00u, /* Section(6)_A0, 0.300359010696411 */

 0x2Bu, 0x72u, 0x26u, 0x00u, /* Section(6)_A1, 0.600718259811401 */

 0x15u, 0x39u, 0x13u, 0x00u, /* Section(6)_A2, 0.300359010696411 */

 0x25u, 0xCAu, 0xF3u, 0x00u, /* Section(6)_B1, 0.190787076950073 */

 0x8Eu, 0x51u, 0xFFu, 0x00u, /* Section(6)_B2, 0.0106472969055176 */

 /* Coefficients of Section 7 */
 0x8Bu, 0x7Du, 0x01u, 0x00u, /* Section(7)_A0, 0.0232875347137451 */

 0x17u, 0xFBu, 0x02u, 0x00u, /* Section(7)_A1, 0.0465753078460693 */

 0x8Bu, 0x7Du, 0x01u, 0x00u, /* Section(7)_A2, 0.0232875347137451 */

 0x34u, 0xC0u, 0xD2u, 0x00u, /* Section(7)_B1, 0.707018852233887 */

 0x55u, 0x35u, 0xD8u, 0x00u, /* Section(7)_B2, 0.621744871139526 */
};


/*******************************************************************************
* ChannelB filter coefficients.
* Filter Type is FIR
*******************************************************************************/

/* Renamed array for backward compatibility.
*  Should not be used in new designs.
*/
#define ChannelBFirCoefficients Filter_1_ChannelBFirCoefficients

/* Number of FIR filter taps are: 16 */

const uint8 CYCODE Filter_1_ChannelBFirCoefficients[Filter_1_FIR_B_SIZE] = 
{
 0x2Bu, 0x54u, 0x00u, 0x00u, /* Tap(0), 0.00256860256195068 */

 0x36u, 0xD9u, 0xFFu, 0x00u, /* Tap(1), -0.00118374824523926 */

 0xB0u, 0x23u, 0xFEu, 0x00u, /* Tap(2), -0.0145359039306641 */

 0x29u, 0x62u, 0xFCu, 0x00u, /* Tap(3), -0.0282543897628784 */

 0x09u, 0xDBu, 0xFEu, 0x00u, /* Tap(4), -0.00894057750701904 */

 0xE2u, 0x28u, 0x09u, 0x00u, /* Tap(5), 0.0715601444244385 */

 0xA5u, 0xBDu, 0x18u, 0x00u, /* Tap(6), 0.193287491798401 */

 0x94u, 0xAAu, 0x24u, 0x00u, /* Tap(7), 0.286455631256104 */

 0x94u, 0xAAu, 0x24u, 0x00u, /* Tap(8), 0.286455631256104 */

 0xA5u, 0xBDu, 0x18u, 0x00u, /* Tap(9), 0.193287491798401 */

 0xE2u, 0x28u, 0x09u, 0x00u, /* Tap(10), 0.0715601444244385 */

 0x09u, 0xDBu, 0xFEu, 0x00u, /* Tap(11), -0.00894057750701904 */

 0x29u, 0x62u, 0xFCu, 0x00u, /* Tap(12), -0.0282543897628784 */

 0xB0u, 0x23u, 0xFEu, 0x00u, /* Tap(13), -0.0145359039306641 */

 0x36u, 0xD9u, 0xFFu, 0x00u, /* Tap(14), -0.00118374824523926 */

 0x2Bu, 0x54u, 0x00u, 0x00u, /* Tap(15), 0.00256860256195068 */
};

