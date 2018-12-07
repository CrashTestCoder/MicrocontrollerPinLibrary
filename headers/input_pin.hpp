#ifndef _READ_PIN_H_P_P_
#define _READ_PIN_H_P_P_

#include <vector>
#include <string>
#include <type_traits>

#include "pin_base.hpp"

typedef enum InputMode {
	pullup,
	pulldown,
	no_bias
} im;



/**************************************************************************/
/*                            Class Definition                            */
/**************************************************************************/

class input_pin : public pin_base
{
public:
	constexpr input_pin(input_pin&& pin) noexcept // may not be able to be constexpr, depends on backend
	{
		pin_num = pin.pin_num;

		// TODO: Whatever needs to happen to change ownership of the pin, probably nothing, remove this comment if so
	}

	double analog_read() const noexcept	// [0,1]
	{
		// TODO: Read value from non-analog pin
		// Can be divided into more specific operations if necisary
		return 0;
	}

	bool digital_read() const noexcept
	{
		// TODO: Read value from non-analog pin
		// Can be divided into more specific operations if necisary
		return false;
	}
};

/**************************************************************************/
/*                           Helper Functions                             */
/**************************************************************************/

template<unsigned PIN_NUM> constexpr input_pin&& make_input_pin(InputMode in_mode = no_bias) noexcept
{
	switch (in_mode)
	{
	case pullup:
		// TODO: Initialize input pin with pullup resistor
		break;
	case pulldown:
		// TODO: Initialize input pin with pulldown resistor
		break;
	case no_bias:
		// TODO: Initialize input pin without a bias resistor
		break;
	default:;	// Invalid Mode
#pragma message("Invalid Input Mode")
//#warning Invalid Input Mode
	}

	return static_cast<input_pin&&>(make_pin_base<PIN_NUM>());
}

#endif /* _READ_PIN_H_P_P_ */
