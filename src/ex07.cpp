#include "Matrix.hpp"

int main()
{
	try
	{
		Matrix u = {
			{1.0, 0.0},
			{0.0, 1.0}
		};
		Vector v = {4.0, 5.0};
		std::cout << "uv = ";
		u.mul_vec(v).print();

		Matrix m = {
			{3., -5.},
			{6., 8.}
		};
		Matrix n = {
			{2., 1.},
			{4., 2.}
		};
		std::cout << "mn = " << std::endl;
		m.mul_mat(n).print();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}