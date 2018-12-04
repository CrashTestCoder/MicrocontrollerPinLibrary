#ifndef _READ_PIN_H_P_P_
#define _READ_PIN_H_P_P_

#include<vector>
#include<string>
#include<type_traits>
#include "pin_base.hpp"


typedef enum InputMode {
	analog,
	pullup,
	pulldown,
	no_bias
} im;

template<InputMode IM, typename = std::enable_if_t<IM <= no_bias>::value>
class input_pin : public pin_base
{
public:
	constexpr input_pin(const char&) noexcept; // may not be able to be constexpr, depends on backend
	constexpr input_pin(input_pin&&) noexcept; // may not be able to be constexpr, depends on backend

	double analog_read() const noexcept;	// [0,1]
	bool digital_read() const noexcept;
};


/**************************************************************************/
/*                   Constructors / Initializers                          */
/**************************************************************************/

template<char pin>
input_pin(pin) -> input_pin<no_bias>(pin);    // default to no_bias

template<> constexpr input_pin<pullup>::input_pin(const char& pin_num)
{
	static_assert(pin_available[pin_num], "Pin "s + pin_num + " is already in use");
	pin_available[pin_num] = false;

	// TODO: Initialize pin with pullup resistor
}

template<> constexpr input_pin<pulldown>::input_pin(const char& pin_num)
{
	static_assert(pin_available[pin_num], "Pin "s + pin_num + " is already in use");
	pin_available[pin_num] = false;

	// TODO: Initialize pin with pulldown resistor
}

template<> constexpr input_pin<no_bias>::input_pin(const char& pin_num)
{
	static_assert(pin_available[pin_num], "Pin "s + pin_num + " is already in use");
	pin_available[pin_num] = false;

	// TODO: Initialize pin without bias resistor
}

template<InputMode IM> constexpr input_pin<IM>::input_pin(input_pin<IM>&& pin)
{
	// TODO: Fully disable parameter pin and move all of its data to this pin
}



/**************************************************************************/
/*                            Member Functions                            */
/**************************************************************************/

template<InputMode IM> double input_pin<IM>::analog_read() // returns bool
{
	static_assert(analog_read_capable[pin], "Pin "s + pin + " is not capable of reading analog values"s);

	// TODO: Read value from non-analog pin
	// Can be divided into more specific operations if necisary
	return 0;
}

template<InputMode IM> bool input_pin<IM>::digital_read() // returns bool
{
	// TODO: Read value from non-analog pin
	// Can be divided into more specific operations if necisary
	return false;
}


#endif /* _READ_PIN_H_P_P_ */
