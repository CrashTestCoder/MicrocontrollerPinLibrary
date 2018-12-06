#include "../headers/pin_base.hpp"


pin_base::~pin_base() noexcept
{
	if (pin_num != -1)
	{
		pin_available[pin_num] = true;

		// TODO: impliment whatever needs to be done to stop using a pin

	}
}
