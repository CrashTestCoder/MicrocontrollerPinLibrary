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
	constexpr input_pin(const uint8_t&) noexcept; // may not be able to be constexpr, depends on backend
	constexpr input_pin(input_pin&&) noexcept; // may not be able to be constexpr, depends on backend

	double analog_read() const noexcept;	// [0,1]
	bool digital_read() const noexcept;
};


/**************************************************************************/
/*                   Constructors / Initializers                          */
/**************************************************************************/

template<char pin>
input_pin(pin) -> input_pin<no_bias>(pin);    // default to no_bias

template<> constexpr input_pin<pullup>::input_pin(const uint8_t& _pin_num) noexcept :
	pin_base(_pin_num)
{
	// TODO: Initialize pin with pullup resistor
}

template<> constexpr input_pin<pulldown>::input_pin(const uint8_t& _pin_num) noexcept :
	pin_base(_pin_num)
{
	// TODO: Initialize pin with pulldown resistor
}

template<> constexpr input_pin<no_bias>::input_pin(const uint8_t& _pin_num) noexcept :
	pin_base(_pin_num)
{
	// TODO: Initialize pin without bias resistor
}

template<InputMode IM> constexpr input_pin<IM>::input_pin(input_pin<IM>&& pin) noexcept
{
	pin_num = pin.pin_num;

	// TODO: Fully disable parameter pin and move all of its data to this pin
	// Will probably require more explaination as to what this is for...
}



/**************************************************************************/
/*                            Member Functions                            */
/**************************************************************************/

template<InputMode IM> double input_pin<IM>::analog_read() const noexcept
{
	static_assert(analog_read_capable[pin], "Pin "s + pin + " is not capable of reading analog values"s);

	// TODO: Read value from non-analog pin
	// Can be divided into more specific operations if necisary
	return 0;
}

template<InputMode IM> bool input_pin<IM>::digital_read() const noexcept
{
	// TODO: Read value from non-analog pin
	// Can be divided into more specific operations if necisary
	return false;
}


#endif /* _READ_PIN_H_P_P_ */
