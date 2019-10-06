#define F_CPU 8000000ULL

#include <iostream>
#include "pin.hpp"
//#include "delay.hpp"

int main()
{
    Pin<1, B, OUTPUT> p;

    p.set(HIGH);
    std::cout << p.get() << '\n';

    p.set(LOW);
    std::cout << p.get() << '\n';
}