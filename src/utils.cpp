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

// Float equality comparison
bool areFloatsEqual(float a, float b)
{
    const float EPSILON = 10 * std::numeric_limits<float>::epsilon();
    float diff = a - b;
    return (diff <= EPSILON && diff >= -EPSILON);
}
