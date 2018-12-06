#ifndef _MSP430_X53_PIN_LIB_H_P_P_
#define _MSP430_X53_PIN_LIB_H_P_P_

//#include<msp430.h> // Comes with compiler
#include<array>

/*******************************************************/
/*          Microcontroller Specific Data              */
/*******************************************************/

constexpr const std::array<bool,20> analog_read_capable
{{
	
	0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0
}};

constexpr const std::array<bool,20> analog_write_capable
{{
	0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
}};

inline std::array<bool,20> pin_available
{{
	0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0
}};


#endif /* _MSP430_X53_PIN_LIB_H_P_P_ */
