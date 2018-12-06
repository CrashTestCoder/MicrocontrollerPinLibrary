#include "../headers/output_pin.hpp"

void output_pin::digital_write(const bool& value) noexcept
{
	// TODO: write this function
}

void output_pin::analog_write(const double& value) noexcept
{
	if (value == 0 || value == 1) return digital_write(value);

	// TODO: Write code to ouput a PWM signal
}
