#define MSP430_x53
#include "../headers/pinlib.hpp"

#include <iostream>

using namespace std;

int main()
{
	auto p1 = make_output_pin<5>();
	auto p2 = make_input_pin<6, pullup>();
}