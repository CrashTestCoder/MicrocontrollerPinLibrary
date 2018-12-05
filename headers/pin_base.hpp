#ifndef _PIN_H_P_P_
#define _PIN_H_P_P_

enum class uint8_t : unsigned char {} //#include <cstdint> // doesnt seem to exist for some reason...

// Note: dispite what it sounds like, constexpr does not mean that the variables value is constant

// Microcontroller data defined in the microcontroller specific file
extern constexpr const std::vector<bool> analog_read_capable;
extern constexpr const std::vector<bool> analog_write_capable;
extern constexpr std::vector<bool> pin_available;

class pin_base
{
	std::byte pin_num;
public:
	constexpr virtual pin_base(const uint8_t& _pin_num) noexcept;	// pretty sure constexpr virtual cant happen for some reason...
																	// sticking with it anyway until it gives me an error,
																	// prioritize constexpr if possible
	pin_base(const pin_base&) = delete; // A disaster waiting to happen
	constexpr virtual pin_base(pin_base&&) noexcept = 0;

	constexpr virtual ~pin_base() noexcept;
};

#endif /* _PIN_H_P_P_ */
