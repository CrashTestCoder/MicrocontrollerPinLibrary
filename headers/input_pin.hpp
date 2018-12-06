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
/*                            Helper Classes                              */
/**************************************************************************/

template<unsigned PIN_NUM, InputMode IM> struct make_input_pin : public make_pin_base<PIN_NUM>
{
	constexpr make_input_pin() noexcept;
};

template<unsigned PIN_NUM> struct make_input_pin<PIN_NUM, pullup> : public make_pin_base<PIN_NUM>
{
	constexpr make_input_pin() noexcept :
		make_pin_base<PIN_NUM>()
	{
		// TODO: Initialize input pin with pullup resistor
	}
};

template<unsigned PIN_NUM> struct make_input_pin<PIN_NUM, pulldown> : public make_pin_base<PIN_NUM>
{
	constexpr make_input_pin() noexcept :
		make_pin_base<PIN_NUM>()
	{
		// TODO: Initialize input pin with pulldown resistor
	}
};

template<unsigned PIN_NUM> struct make_input_pin<PIN_NUM, no_bias> : public make_pin_base<PIN_NUM>
{
	constexpr make_input_pin() noexcept :
		make_pin_base<PIN_NUM>()
	{
		// TODO: Initialize input pin without a bias resistor
	}
};



/**************************************************************************/
/*                            Class Definition                            */
/**************************************************************************/

class input_pin : public pin_base
{
public:
	constexpr input_pin(input_pin&& pin) noexcept // may not be able to be constexpr, depends on backend
	{
		pin_num = pin.pin_num;

		// TODO: Whatever needs to happen to change ownership of the pin, probably nothing
	}

	template<unsigned PIN_NUM, InputMode IM> constexpr input_pin(make_input_pin<PIN_NUM, IM>&& pin_init) noexcept // may not be able to be constexpr, depends on backend
	{
		pin_num = pin_init.pin_num;

		// TODO: Whatever needs to happen to change ownership of the initialized pin, probably nothing
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

#endif /* _READ_PIN_H_P_P_ */
