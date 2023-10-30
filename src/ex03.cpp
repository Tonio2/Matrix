#include "Vector.hpp"

int main()
{
	try
	{
		Vector u = {1.0, 2.0, 3.0};
		Vector v = {4.0, 5.0};

		std::cout << "u.v = " << u.dot(v) << std::endl;
	}

	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}