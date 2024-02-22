#include "Vector.hpp"
#include "utils.cpp"

int main()
{
	try
	{
		Vector e1 = {1.0, 0.0, 0.0};
		Vector e2 = {0.0, 1.0, 0.0};
		Vector e3 = {0.0, 0.0, 1.0};
		std::vector<Vector> vecs = {e1, e2, e3};

		Vector res = Vector::linear_combination(vecs, {10., 0.5, -2.});
		Vector expected = {10., 0.5, -2.};
		assert(res == expected, "linear combination of vectors");

		Vector v1 = {2.0, 3.0, 4.0};
		Vector v2 = {5.0, 7.0, 9.0};
		std::vector<Vector> vecs2 = {v1, v2};

		Vector res2 = Vector::linear_combination(vecs2, {10., -2.});
		Vector expected2 = {10., 16., 22.};
		assert(res2 == expected2, "linear combination of vectors");

		bool exceptionCaught = false;
		try
		{
			Vector::linear_combination(vecs, {10., 0.5});
		}
		catch (const std::invalid_argument &e)
		{
			exceptionCaught = true;
		}
		assert(exceptionCaught, "linear combination of vectors and coefficients of different sizes should fail");

		Vector u = {1.0, 2.0, 3.0, 4.0};
		std::vector<Vector> vecs3 = {u, v1, v2};
		exceptionCaught = false;
		try
		{
			Vector::linear_combination(vecs3, {10., 0.5, -2.});
		}
		catch (const std::invalid_argument &e)
		{
			exceptionCaught = true;
		}
		assert(exceptionCaught, "linear combination of vectors of different sizes should fail");
	}

	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}