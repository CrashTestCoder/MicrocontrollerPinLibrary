#ifndef _PIN_H_P_P_
#define _PIN_H_P_P_

constexpr enum class PinMode {
  dig_out,
  pwm_out,
  read_analog,
  read_pullup,
  read_pulldown,
  read
};

template<PinMode PM>
class pin
{
  const uint8_t pin;
public:
  pin(const char& pin_num);
  pin(const pin&) = delete; // A disaster waiting to happen
  pin(pin&&);
  
  void set(const bool& state);
  void set(const double& value);
  
  auto read();
};

#endif /* _PIN_H_P_P_ */
