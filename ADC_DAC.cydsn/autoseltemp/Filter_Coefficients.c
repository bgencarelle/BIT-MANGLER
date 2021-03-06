#include "Filter.h"
#include "Filter_PVT.h"


/*******************************************************************************
* ChannelA filter coefficients.
* Filter Type is FIR
*******************************************************************************/

/* Renamed array for backward compatibility.
*  Should not be used in new designs.
*/
#define ChannelAFirCoefficients Filter_ChannelAFirCoefficients

/* Number of FIR filter taps are: 67 */

const uint8 CYCODE Filter_ChannelAFirCoefficients[Filter_FIR_A_SIZE] = 
{
 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(0), 0 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(1), 0 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(2), 0 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(3), 0 */

 0x03u, 0x00u, 0x00u, 0x00u, /* Tap(4), 3.57627868652344E-07 */

 0x07u, 0x00u, 0x00u, 0x00u, /* Tap(5), 8.34465026855469E-07 */

 0xFBu, 0xFFu, 0xFFu, 0x00u, /* Tap(6), -5.96046447753906E-07 */

 0xDCu, 0xFFu, 0xFFu, 0x00u, /* Tap(7), -4.29153442382813E-06 */

 0xE8u, 0xFFu, 0xFFu, 0x00u, /* Tap(8), -2.86102294921875E-06 */

 0x70u, 0x00u, 0x00u, 0x00u, /* Tap(9), 1.33514404296875E-05 */

 0xECu, 0x00u, 0x00u, 0x00u, /* Tap(10), 2.81333923339844E-05 */

 0xC5u, 0xFFu, 0xFFu, 0x00u, /* Tap(11), -7.03334808349609E-06 */

 0xF8u, 0xFCu, 0xFFu, 0x00u, /* Tap(12), -9.25064086914063E-05 */

 0x12u, 0xFDu, 0xFFu, 0x00u, /* Tap(13), -8.94069671630859E-05 */

 0xD0u, 0x04u, 0x00u, 0x00u, /* Tap(14), 0.000146865844726563 */

 0x3Du, 0x0Du, 0x00u, 0x00u, /* Tap(15), 0.000404000282287598 */

 0x46u, 0x03u, 0x00u, 0x00u, /* Tap(16), 9.98973846435547E-05 */

 0x82u, 0xE3u, 0xFFu, 0x00u, /* Tap(17), -0.000869512557983398 */

 0xDDu, 0xD5u, 0xFFu, 0x00u, /* Tap(18), -0.00128591060638428 */

 0xEDu, 0x0Au, 0x00u, 0x00u, /* Tap(19), 0.000333428382873535 */

 0xC1u, 0x5Eu, 0x00u, 0x00u, /* Tap(20), 0.0028916597366333 */

 0x76u, 0x44u, 0x00u, 0x00u, /* Tap(21), 0.00208926200866699 */

 0x3Bu, 0x6Eu, 0xFFu, 0x00u, /* Tap(22), -0.0044485330581665 */

 0xE4u, 0xA1u, 0xFEu, 0x00u, /* Tap(23), -0.0106844902038574 */

 0x4Bu, 0x56u, 0xFFu, 0x00u, /* Tap(24), -0.00517904758453369 */

 0x70u, 0xC0u, 0x01u, 0x00u, /* Tap(25), 0.0136852264404297 */

 0x6Cu, 0x69u, 0x03u, 0x00u, /* Tap(26), 0.0266547203063965 */

 0x65u, 0x07u, 0x01u, 0x00u, /* Tap(27), 0.00803816318511963 */

 0x2Du, 0xFCu, 0xFAu, 0x00u, /* Tap(28), -0.0391792058944702 */

 0x63u, 0x8Cu, 0xF7u, 0x00u, /* Tap(29), -0.0660282373428345 */

 0x26u, 0x8Du, 0xFEu, 0x00u, /* Tap(30), -0.0113174915313721 */

 0xA5u, 0x18u, 0x11u, 0x00u, /* Tap(31), 0.133564591407776 */

 0x0Cu, 0xC3u, 0x25u, 0x00u, /* Tap(32), 0.29501485824585 */

 0x82u, 0xD1u, 0x2Eu, 0x00u, /* Tap(33), 0.365768671035767 */

 0x0Cu, 0xC3u, 0x25u, 0x00u, /* Tap(34), 0.29501485824585 */

 0xA5u, 0x18u, 0x11u, 0x00u, /* Tap(35), 0.133564591407776 */

 0x26u, 0x8Du, 0xFEu, 0x00u, /* Tap(36), -0.0113174915313721 */

 0x63u, 0x8Cu, 0xF7u, 0x00u, /* Tap(37), -0.0660282373428345 */

 0x2Du, 0xFCu, 0xFAu, 0x00u, /* Tap(38), -0.0391792058944702 */

 0x65u, 0x07u, 0x01u, 0x00u, /* Tap(39), 0.00803816318511963 */

 0x6Cu, 0x69u, 0x03u, 0x00u, /* Tap(40), 0.0266547203063965 */

 0x70u, 0xC0u, 0x01u, 0x00u, /* Tap(41), 0.0136852264404297 */

 0x4Bu, 0x56u, 0xFFu, 0x00u, /* Tap(42), -0.00517904758453369 */

 0xE4u, 0xA1u, 0xFEu, 0x00u, /* Tap(43), -0.0106844902038574 */

 0x3Bu, 0x6Eu, 0xFFu, 0x00u, /* Tap(44), -0.0044485330581665 */

 0x76u, 0x44u, 0x00u, 0x00u, /* Tap(45), 0.00208926200866699 */

 0xC1u, 0x5Eu, 0x00u, 0x00u, /* Tap(46), 0.0028916597366333 */

 0xEDu, 0x0Au, 0x00u, 0x00u, /* Tap(47), 0.000333428382873535 */

 0xDDu, 0xD5u, 0xFFu, 0x00u, /* Tap(48), -0.00128591060638428 */

 0x82u, 0xE3u, 0xFFu, 0x00u, /* Tap(49), -0.000869512557983398 */

 0x46u, 0x03u, 0x00u, 0x00u, /* Tap(50), 9.98973846435547E-05 */

 0x3Du, 0x0Du, 0x00u, 0x00u, /* Tap(51), 0.000404000282287598 */

 0xD0u, 0x04u, 0x00u, 0x00u, /* Tap(52), 0.000146865844726563 */

 0x12u, 0xFDu, 0xFFu, 0x00u, /* Tap(53), -8.94069671630859E-05 */

 0xF8u, 0xFCu, 0xFFu, 0x00u, /* Tap(54), -9.25064086914063E-05 */

 0xC5u, 0xFFu, 0xFFu, 0x00u, /* Tap(55), -7.03334808349609E-06 */

 0xECu, 0x00u, 0x00u, 0x00u, /* Tap(56), 2.81333923339844E-05 */

 0x70u, 0x00u, 0x00u, 0x00u, /* Tap(57), 1.33514404296875E-05 */

 0xE8u, 0xFFu, 0xFFu, 0x00u, /* Tap(58), -2.86102294921875E-06 */

 0xDCu, 0xFFu, 0xFFu, 0x00u, /* Tap(59), -4.29153442382813E-06 */

 0xFBu, 0xFFu, 0xFFu, 0x00u, /* Tap(60), -5.96046447753906E-07 */

 0x07u, 0x00u, 0x00u, 0x00u, /* Tap(61), 8.34465026855469E-07 */

 0x03u, 0x00u, 0x00u, 0x00u, /* Tap(62), 3.57627868652344E-07 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(63), 0 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(64), 0 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(65), 0 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(66), 0 */
};


/*******************************************************************************
* ChannelB filter coefficients.
* Filter Type is FIR
*******************************************************************************/

/* Renamed array for backward compatibility.
*  Should not be used in new designs.
*/
#define ChannelBFirCoefficients Filter_ChannelBFirCoefficients

/* Number of FIR filter taps are: 37 */

const uint8 CYCODE Filter_ChannelBFirCoefficients[Filter_FIR_B_SIZE] = 
{
 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(0), 0 */

 0xFFu, 0xFFu, 0xFFu, 0x00u, /* Tap(1), -1.19209289550781E-07 */

 0xF5u, 0xFFu, 0xFFu, 0x00u, /* Tap(2), -1.31130218505859E-06 */

 0x14u, 0x00u, 0x00u, 0x00u, /* Tap(3), 2.38418579101563E-06 */

 0x8Au, 0x00u, 0x00u, 0x00u, /* Tap(4), 1.64508819580078E-05 */

 0x1Bu, 0xFFu, 0xFFu, 0x00u, /* Tap(5), -2.72989273071289E-05 */

 0x7Fu, 0xFBu, 0xFFu, 0x00u, /* Tap(6), -0.000137448310852051 */

 0x7Bu, 0x05u, 0x00u, 0x00u, /* Tap(7), 0.000167250633239746 */

 0x68u, 0x1Cu, 0x00u, 0x00u, /* Tap(8), 0.000866889953613281 */

 0x01u, 0xECu, 0xFFu, 0x00u, /* Tap(9), -0.000610232353210449 */

 0x2Fu, 0x68u, 0xFFu, 0x00u, /* Tap(10), -0.00463306903839111 */

 0x09u, 0xDEu, 0xFFu, 0x00u, /* Tap(11), -0.00103652477264404 */

 0x5Fu, 0xDAu, 0x01u, 0x00u, /* Tap(12), 0.0144766569137573 */

 0x7Au, 0x51u, 0x01u, 0x00u, /* Tap(13), 0.0102989673614502 */

 0x86u, 0xD6u, 0xFAu, 0x00u, /* Tap(14), -0.0403282642364502 */

 0x88u, 0x05u, 0xF8u, 0x00u, /* Tap(15), -0.0623311996459961 */

 0xF0u, 0x7Fu, 0x09u, 0x00u, /* Tap(16), 0.0742168426513672 */

 0xD8u, 0xB3u, 0x2Au, 0x00u, /* Tap(17), 0.333613395690918 */

 0x4Bu, 0x50u, 0x3Cu, 0x00u, /* Tap(18), 0.471200346946716 */

 0xD8u, 0xB3u, 0x2Au, 0x00u, /* Tap(19), 0.333613395690918 */

 0xF0u, 0x7Fu, 0x09u, 0x00u, /* Tap(20), 0.0742168426513672 */

 0x88u, 0x05u, 0xF8u, 0x00u, /* Tap(21), -0.0623311996459961 */

 0x86u, 0xD6u, 0xFAu, 0x00u, /* Tap(22), -0.0403282642364502 */

 0x7Au, 0x51u, 0x01u, 0x00u, /* Tap(23), 0.0102989673614502 */

 0x5Fu, 0xDAu, 0x01u, 0x00u, /* Tap(24), 0.0144766569137573 */

 0x09u, 0xDEu, 0xFFu, 0x00u, /* Tap(25), -0.00103652477264404 */

 0x2Fu, 0x68u, 0xFFu, 0x00u, /* Tap(26), -0.00463306903839111 */

 0x01u, 0xECu, 0xFFu, 0x00u, /* Tap(27), -0.000610232353210449 */

 0x68u, 0x1Cu, 0x00u, 0x00u, /* Tap(28), 0.000866889953613281 */

 0x7Bu, 0x05u, 0x00u, 0x00u, /* Tap(29), 0.000167250633239746 */

 0x7Fu, 0xFBu, 0xFFu, 0x00u, /* Tap(30), -0.000137448310852051 */

 0x1Bu, 0xFFu, 0xFFu, 0x00u, /* Tap(31), -2.72989273071289E-05 */

 0x8Au, 0x00u, 0x00u, 0x00u, /* Tap(32), 1.64508819580078E-05 */

 0x14u, 0x00u, 0x00u, 0x00u, /* Tap(33), 2.38418579101563E-06 */

 0xF5u, 0xFFu, 0xFFu, 0x00u, /* Tap(34), -1.31130218505859E-06 */

 0xFFu, 0xFFu, 0xFFu, 0x00u, /* Tap(35), -1.19209289550781E-07 */

 0x00u, 0x00u, 0x00u, 0x00u, /* Tap(36), 0 */
};

