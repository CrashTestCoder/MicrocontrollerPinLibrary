#ifndef _PIN_H_P_P_
#define _PIN_H_P_P_

#include <array>
#include <type_traits>

#ifdef MSP430_x53
#include "../microcontrollers/pin_msp430x53.hpp"
#else // elif for other supported microcontroller libraries
static_assert(false, "No microcontroller specified");
#endif

template<unsigned PIN_NUM>
struct make_pin_base
{
	unsigned const pin_num = PIN_NUM;
	constexpr make_pin_base() noexcept
	{
		static_assert(PIN_NUM < pin_available.size(), "Invalad Pin Number");
		static_assert(pin_available[PIN_NUM], "Pin is already in use or is not a valid pin");
	}
};

class pin_base
{
protected:
	unsigned pin_num = -1;
	constexpr pin_base(unsigned const& _pin_num) noexcept :
		pin_num{ _pin_num }
	{

	}
public:
	constexpr pin_base() noexcept {}
	pin_base(pin_base const&) = delete; // A disaster waiting to happen
	template<unsigned PIN_NUM> constexpr pin_base(make_pin_base<PIN_NUM>&& pin) noexcept :
		pin_num { pin.pin_num }
	{

	}

	~pin_base() noexcept
	{
		if (pin_num != (unsigned)-1)
		{
			pin_available[pin_num] = true;

			// TODO: impliment whatever needs to be done to stop using a pin

		}
	}
};


#endif /* _PIN_H_P_P_ */
