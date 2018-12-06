#ifndef _PIN_H_P_P_
#define _PIN_H_P_P_

#include <array>
#include <type_traits>

typedef unsigned char uint8_t; //#include <cstdint> // doesnt seem to exist for some reason...

// Note: dispite what it sounds like, constexpr does not mean that the variables value is constant

// Microcontroller data defined in the microcontroller specific file
//extern const auto analog_read_capable;
//extern const auto analog_write_capable;
//extern auto pin_available;

template<unsigned PIN_NUM>
class make_pin_base
{
private:
	friend class pin_base;
	unsigned pin_num = PIN_NUM;
public:
	constexpr make_pin_base() noexcept
	{
		static_assert(PIN_NUM < pin_available.size(), "Invalad Pin Number");
		static_assert(pin_available[PIN_NUM], "Pin is already in use or is not a valid pin");
	}
};

class pin_base
{
protected:
	unsigned pin_num;
public:
	//constexpr pin_base(const unsigned& _pin_num) noexcept;
	pin_base(const pin_base&) = delete; // A disaster waiting to happen
	template<unsigned PIN_NUM> constexpr pin_base(make_pin_base<PIN_NUM>&& pin) noexcept :
		pin_num { pin.pin_num }
	{

	}

	~pin_base() noexcept;
};


#endif /* _PIN_H_P_P_ */
