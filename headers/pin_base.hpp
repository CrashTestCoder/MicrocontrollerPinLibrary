#ifndef _PIN_H_P_P_
#define _PIN_H_P_P_

class pin_base
{
  const uint8_t pin;
public:
  virtual pin(const char& pin_num) = 0;
  pin(const pin&) = delete; // A disaster waiting to happen
  virtual pin(pin&&) = 0;
};

#endif /* _PIN_H_P_P_ */
