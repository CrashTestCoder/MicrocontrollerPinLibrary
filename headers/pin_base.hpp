#ifndef _PIN_H_P_P_
#define _PIN_H_P_P_

#include<cstddef>

// Microcontroller data defined in the microcontroller specific file
extern constexpr const std::vector<bool> analog_read_capable;
extern constexpr const std::vector<bool> analog_write_capable;
extern constexpr std::vector<bool> pin_available;

class pin_base
{
	const std::byte pin;
public:
	virtual pin(const std::byte& pin_num) noexcept = 0;
	pin(const pin&) = delete; // A disaster waiting to happen
	virtual pin(pin&&) noexcept = 0;
};

#endif /* _PIN_H_P_P_ */
