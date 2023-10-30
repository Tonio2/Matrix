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
			{4., 2.},
			{1., 3.}
		};
		std::cout << "transpose(m):" << std::endl;
		m.transpose().print(); 
		std::cout << "transpose(n):" << std::endl;
		n.transpose().print();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}