#include "../headers/pin_base.hpp"

constexpr pin_base::pin_base(const uint8_t& _pin_num) noexcept
{
	static_assert(_pin_num < pin_available.size(), "Pin index out of range: "s + _pin_num);
	static_assert(pin_available[_pin_num], "Pin "s + _pin_num + " is already in use or is not useable for some other reason");
	pin_available[_pin_num] = false;

	pin_num = _pin_num;
}

constexpr pin_base::~pin_base() noexcept
{
	if (pin != -1)
	{
		pin_availible[pin] = true;

		// TODO: impliment whatever needs to be done to stop using a pin

	}
}