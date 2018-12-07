#define MSP430_x53
#include "../headers/pinlib.hpp"

#include <iostream>

using namespace std;


int main()
{
	output_pin p1 = make_output_pin<5>();
	output_pin p3 = make_output_pin<5>();
	input_pin p2 = make_input_pin<6>(pullup);

	//auto p4{ std::move(p3) };
	p1.digital_write(1);
	
	for(size_t i = 0; i < pin_available.size(); i++)
		cout << "pin " << i << ":\t" << pin_available[i] << '\n';
}