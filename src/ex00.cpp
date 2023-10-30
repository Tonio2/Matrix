#include "Vector.hpp"
#include "Matrix.hpp"

int main()
{
	try
	{
		// Testing Vector operations
		Vector v1 = {2.0, 3.0};
		Vector v2 = {5.0, 7.0};

		std::cout << "Original v1: ";
		v1.print();

		std::cout << "Original v2: ";
		v2.print();

		v1.add(v2);
		std::cout << "After addition, v1: ";
		v1.print();

		v1.sub(v2);
		std::cout << "After subtraction, v1: ";
		v1.print();

		v1.scl(2.0);
		std::cout << "After scaling, v1: ";
		v1.print();

		// Testing Matrix operations
		Matrix m1 = {
				{1, 2},
				{3, 4}};
		Matrix m2 = {
				{5, 6},
				{7, 8}};

		std::cout << "\nOriginal m1:" << std::endl;
		m1.print();

		std::cout << "Original m2:" << std::endl;
		m2.print();

		m1.add(m2);
		std::cout << "After addition, m1:" << std::endl;
		m1.print();

		m1.sub(m2);
		std::cout << "After subtraction, m1:" << std::endl;
		m1.print();

		m1.scl(2.0);
		std::cout << "After scaling, m1:" << std::endl;
		m1.print();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
