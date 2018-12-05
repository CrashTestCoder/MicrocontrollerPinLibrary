#ifndef _OUTPUT_PIN_H_P_P_
#define _OUTPUT_PIN_H_P_P_

#include "pin_base.hpp"

// let me know if there needs to be a hard divide between pwm and digital
class output_pin : public pin_base
{
public:
	constexpr output_pin(const uint8_t& pin_num) noexcept;
	constexpr output_pin(output_pin&&) noexcept;

	void digital_write(const bool&) noexcept;
	void analog_write(const double&) noexcept;
};

#endif /* _OUTPUT_PIN_H_P_P_ */
