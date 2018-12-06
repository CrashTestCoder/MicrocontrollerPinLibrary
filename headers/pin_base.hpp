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

class pin_base
{
protected:
	unsigned pin_num;
public:
	pin_base() = default;
	template<unsigned _pin_num> constexpr pin_base() noexcept :
		pin_num{_pin_num}
	{
		static_assert(_pin_num < pin_available.size(), "Pin index out of range");
		static_assert(pin_available[_pin_num], "Pin is already in use or is not useable for some other reason");
		pin_available[_pin_num] = false;
	}
	
	pin_base(const pin_base&) = delete; // A disaster waiting to happen

	~pin_base() noexcept;
};


#endif /* _PIN_H_P_P_ */
