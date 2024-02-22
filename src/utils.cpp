#include <stdexcept>

float linear_interpolation(float u, float v, float t)
{
	return std::fma(t, v - u, u);
}

void assert(bool condition, const std::string &name, const std::string &message)
{
	std::cout << "Testing " << name << "... ";
	if (!condition)
	{
		throw std::runtime_error(message);
	}
	std::cout << "OK" << std::endl;
}