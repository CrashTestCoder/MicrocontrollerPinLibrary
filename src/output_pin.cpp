#include "../headers/output_pin.hpp"

constexpr output_pin::output_pin(const uint8_t& pin_num) noexcept:
	pin_base(pin_num)
{
	// TODO: Initialize output_pin
}

constexpr output_pin::output_pin(output_pin&& pin) noexcept
{
	pin_num = pin.pin_num;

	// TODO: Fully disable parameter pin and move all of its data to this pin
	// Will probably require more explaination as to what this is for...
}

void output_pin::digital_write(const bool& value) noexcept
{
	// TODO: write this function
}

void output_pin::analog_write(const double& value) noexcept
{
	if (value == 0 || value == 1) return digital_write(value);

	// TODO: Write code to ouput a PWM signal
}