#ifndef _READ_PIN_H_P_P_
#define _READ_PIN_H_P_P_

#include <vector>
#include <string>
#include <type_traits>

#include "pin_base.hpp"

typedef enum InputMode {
	analog,
	pullup,
	pulldown,
	no_bias
} im;

/**************************************************************************/
/*                            Helper Classes                              */
/**************************************************************************/

template<unsigned PIN_NUM, InputMode IM, typename = std::enable_if_t<false>>
class make_input_pin : public make_pin_base<PIN_NUM>
{
private:
	friend class input_pin; // might not be necissary
public:
	constexpr make_input_pin() noexcept;
};

template<unsigned PIN_NUM> class make_input_pin<PIN_NUM, pullup> : public make_pin_base<PIN_NUM>
{
private:
	friend class input_pin; // might not be necissary
public:
	constexpr make_input_pin::make_input_pin() noexcept
	{
		// TODO: Initialize input pin with pullup resistor
	}
};

template<unsigned PIN_NUM> class make_input_pin<PIN_NUM, pulldown> : public make_pin_base<PIN_NUM>
{
private:
	friend class input_pin; // might not be necissary
public:
	constexpr make_input_pin::make_input_pin() noexcept
	{
		// TODO: Initialize input pin with pulldown resistor
	}
};

template<unsigned PIN_NUM> class make_input_pin<PIN_NUM, no_bias> : public make_pin_base<PIN_NUM>
{
private:
	friend class input_pin; // might not be necissary
public:
	constexpr make_input_pin::make_input_pin() noexcept
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
	//constexpr input_pin(const unsigned&) noexcept; // may not be able to be constexpr, depends on backend

	constexpr input_pin(input_pin&&) noexcept; // may not be able to be constexpr, depends on backend
	template<unsigned PIN_NUM, InputMode IM> constexpr input_pin(make_input_pin<PIN_NUM, IM>&&) noexcept; // may not be able to be constexpr, depends on backend

	double analog_read() const noexcept;	// [0,1]
	bool digital_read() const noexcept;
};

#endif /* _READ_PIN_H_P_P_ */
