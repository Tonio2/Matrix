#include "Vector.hpp"

int main()
{
	try
	{
		Vector i = {1.0, 0.0};
		Vector j = {0.0, 1.0};
		std::cout << "cos(i, j) = " << Vector::angle_cos(i, j) << std::endl;

		Vector u = {1.0, 2.0, 3.0};
		Vector v = {4.0, 5.0, 6.0};
		std::cout << "cos(u, v) = " << Vector::angle_cos(u, v) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}