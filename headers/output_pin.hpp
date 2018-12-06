#ifndef _OUTPUT_PIN_H_P_P_
#define _OUTPUT_PIN_H_P_P_

#include "pin_base.hpp"

// let me know if there needs to be a hard divide between pwm and digital

class output_pin : public pin_base
{
public:
	constexpr output_pin(const unsigned& _pin_num) noexcept 		
	{
		pin_base::pin_base<_pin_num>();
		// TODO: Initialize output_pin
	}
	
	constexpr output_pin(output_pin&& pin) noexcept
	{
		pin_num = pin.pin_num;
		pin.pin_num = -1;
		
		// TODO: Fully disable parameter pin and move all of its data to this pin
		// Will probably require more explaination as to what this is for...
	}

	void digital_write(const bool&) noexcept;
	void analog_write(const double&) noexcept;
};

#endif /* _OUTPUT_PIN_H_P_P_ */
