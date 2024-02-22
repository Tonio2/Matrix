#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.cpp"

int main()
{
	try
	{
		// Testing Vector operations
		Vector v1 = {2.0, 3.0};
		Vector v2 = {5.0, 7.0};
		Vector expected(2);

		v1.add(v2);
		expected = {7.0, 10.0};
		assert(v1 == expected, "additioning vectors", "Addition failed");

		v1.sub(v2);
		expected = {2.0, 3.0};
		assert(v1 == expected, "substracting vectors", "Subtraction failed");

		v1.scl(2.0);
		expected = {4.0, 6.0};
		assert(v1 == expected, "scaling a vector", "Scaling failed");

		// Testing Matrix operations
		Matrix m1 = {
				{1, 2},
				{3, 4}};
		Matrix m2 = {
				{5, 6},
				{7, 8}};
		Matrix expected_m(2, 2);

		m1.add(m2);
		expected_m = {
				{6, 8},
				{10, 12}};
		assert(m1 == expected_m, "additioning matrices", "Addition failed");

		m1.sub(m2);
		expected_m = {
				{1, 2},
				{3, 4}};
		assert(m1 == expected_m, "substracting matrices", "Subtraction failed");

		m1.scl(2.0);
		expected_m = {
				{2, 4},
				{6, 8}};
		assert(m1 == expected_m, "Scaling matrices", "Scaling failed");
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
