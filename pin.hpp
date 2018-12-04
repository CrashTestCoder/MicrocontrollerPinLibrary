#ifndef _PIN_H_P_P_
#define _PIN_H_P_P_

class pin_base
{
  const uint8_t pin;
public:
  pin(const char& pin_num);
  pin(const pin&) = delete; // A disaster waiting to happen
  pin(pin&&);
};

#endif /* _PIN_H_P_P_ */
