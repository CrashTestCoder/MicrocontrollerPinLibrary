#ifndef _READ_PIN_H_P_P_
#define _READ_PIN_H_P_P_

constexpr enum class InputMode {
  pullup,
  pulldown,
  no_bias
};

template<InputMode IM>
class input_pin : public pin_base
{

};

templat<char pin>
input_pin(pin) -> input_pin<no_bias>(pin);    // default to no_bias

#endif /* _READ_PIN_H_P_P_ */
