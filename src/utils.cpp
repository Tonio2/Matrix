#include "utils.hpp"

float linear_interpolation(float u, float v, float t)
{
	return std::fma(t, v - u, u);
}

void assert(bool condition, const std::string &name)
{
	std::cout << "Testing " << name << "... ";
	if (!condition)
	{
		std::cout << "NOK" << std::endl;
	}
	else
	{
		std::cout << "OK" << std::endl;
	}
}