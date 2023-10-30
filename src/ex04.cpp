#include "Vector.hpp"

int main()
{
	try
	{
		Vector v1 = {1.0, -2.0};

		std::cout << "||v1||_1 = " << v1.norm_1() << std::endl;
		std::cout << "||v1||_2 = " << v1.norm_2() << std::endl;
		std::cout << "||v1||_inf = " << v1.norm_inf() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}