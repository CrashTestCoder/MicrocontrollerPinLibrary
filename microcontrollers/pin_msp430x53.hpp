#ifndef _MSP430_X53_PIN_LIB_H_P_P_
#define _MSP430_X53_PIN_LIB_H_P_P_

#include<msp430.h> // Comes with compiler
#include<vector>

/*******************************************************/
/*          Microcontroller Specific Data              */
/*******************************************************/

constexpr const std::vector<bool> analog_read_capable
{{
	0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0
}};

constexpr const std::vector<bool> analog_write_capable
{{
	0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
}};

constexpr std::vector<bool> pin_available
{{
	0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0
}};

// ...

#include "../headers/output_pin.hpp"
#include "../headers/input_pin.hpp"

#endif /* _MSP430_X53_PIN_LIB_H_P_P_ */
