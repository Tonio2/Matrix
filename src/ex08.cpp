#include "Matrix.hpp"

int main()
{
	try
	{
		Matrix m = {
			{3., -5.},
			{6., 8.}
		};
		Matrix n = {
			{2., 1.},
			{4., 2.}
		};
		std::cout << "trace(m) = " << m.trace() << std::endl;
		std::cout << "trace(n) = " << n.trace() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}