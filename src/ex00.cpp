#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.cpp"

int main()
{
	try
	{
		// Testing Vector operations
		Vector<float> v1 = {2.0, 3.0};
		Vector<float> v2 = {5.0, 7.0};
		Vector<float> v3 = {1.0, 0.0, 0.0};
		Vector<float> expected(2);

		v1.add(v2);
		expected = {7.0, 10.0};
		assert(v1 == expected, "additioning vectors");

		bool exceptionCaught = false;
		try
		{
			v1.add(v3);
		}
		catch (const std::invalid_argument &e)
		{
			exceptionCaught = true;
		}
		assert(exceptionCaught, "additioning vectors of different sizes should fail");

		v1.sub(v2);
		expected = {2.0, 3.0};
		assert(v1 == expected, "substracting vectors");

		exceptionCaught = false;
		try
		{
			v1.sub(v3);
		}
		catch (const std::invalid_argument &e)
		{
			exceptionCaught = true;
		}
		assert(exceptionCaught, "additioning vectors of different sizes should fail");

		v1.scl(2.0);
		expected = {4.0, 6.0};
		assert(v1 == expected, "scaling a vector");

		// Testing Matrix operations
		Matrix<float> m1 = {
				{1, 2},
				{3, 4}};
		Matrix<float> m2 = {
				{5, 6},
				{7, 8}};
		Matrix<float> m3 = {
				{1, 2, 3},
				{4, 5, 6}};
		Matrix<float> expected_m(2, 2);

		m1.add(m2);
		expected_m = {
				{6, 8},
				{10, 12}};
		assert(m1 == expected_m, "additioning matrices");

		exceptionCaught = false;
		try
		{
			m1.add(m3);
		}
		catch (const std::invalid_argument &e)
		{
			exceptionCaught = true;
		}
		assert(exceptionCaught, "additioning matrices of different sizes should fail");

		m1.sub(m2);
		expected_m = {
				{1, 2},
				{3, 4}};
		assert(m1 == expected_m, "substracting matrices");

		exceptionCaught = false;
		try
		{
			m1.sub(m3);
		}
		catch (const std::invalid_argument &e)
		{
			exceptionCaught = true;
		}
		assert(exceptionCaught, "additioning matrices of different sizes should fail");

		m1.scl(2.0);
		expected_m = {
				{2, 4},
				{6, 8}};
		assert(m1 == expected_m, "Scaling matrices");
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
