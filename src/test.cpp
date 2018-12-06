#pragma once
#define MSP430_x53
#include "../headers/pinlib.hpp"

#include <iostream>

using namespace std;

int main()
{
	output_pin p1 = make_output_pin<5>();
}