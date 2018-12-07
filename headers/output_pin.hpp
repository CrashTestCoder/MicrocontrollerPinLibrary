#ifndef _OUTPUT_PIN_H_P_P_
#define _OUTPUT_PIN_H_P_P_

#include "pin_base.hpp"

// let me know if there needs to be a hard divide between pwm and digital

class output_pin;
template<unsigned PIN_NUM> constexpr output_pin&& make_output_pin() noexcept
{
	// TODO: Initialize output_pin

	return static_cast<output_pin&&>(make_pin_base<PIN_NUM>());
}

class output_pin : public pin_base
{
public:
	constexpr output_pin(output_pin&& pin) noexcept
	{
		pin_num = pin.pin_num;
		pin.pin_num = -1;

		// TODO: Fully disable parameter pin and move all of its data to this pin
		// Will probably require more explaination as to what this is for...
	}

	void digital_write(const bool& value) noexcept
	{
		// TODO: write this function
	}

	void analog_write(const double& value) noexcept
	{
		if (value == 0 || value == 1) return digital_write(value);

		// TODO: Write code to ouput a PWM signal
	}
};

#endif /* _OUTPUT_PIN_H_P_P_ */
