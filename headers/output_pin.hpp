#ifndef _OUTPUT_PIN_H_P_P_
#define _OUTPUT_PIN_H_P_P_

// let me know if there needs to be a hard divide between pwm and digital
class output_pin : public pin_base
{
public:
	output_pin(const char& pin_num) noexcept;
	output_pin(output_pin&&) noexcept;

	void set(const bool&) noexcept;
	void set(const double&) noexcept;
};

#endif /* _OUTPUT_PIN_H_P_P_ */
