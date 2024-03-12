#include "Vector.hpp"
#include "utils.hpp"

int main()
{
	try
	{
		Vector<float> e1 = {1.0, 0.0, 0.0};
		Vector<float> e2 = {0.0, 1.0, 0.0};
		Vector<float> e3 = {0.0, 0.0, 1.0};
		std::vector<Vector<float>> vecs = {e1, e2, e3};

		Vector<float> res = Vector<float>::linear_combination(vecs, {10., 0.5, -2.});
		Vector<float> expected = {10., 0.5, -2.};
		assert(res == expected, "linear combination of Vectors");

		Vector<float> v1 = {2.0, 3.0, 4.0};
		Vector<float> v2 = {5.0, 7.0, 9.0};
		std::vector<Vector<float>> vecs2 = {v1, v2};

		Vector<float> res2 = Vector<float>::linear_combination(vecs2, {10., -2.});
		Vector<float> expected2 = {10., 16., 22.};
		assert(res2 == expected2, "linear combination of Vectors");

		bool exceptionCaught = false;
		try
		{
			Vector<float>::linear_combination(vecs, {10., 0.5});
		}
		catch (const std::invalid_argument &e)
		{
			exceptionCaught = true;
		}
		assert(exceptionCaught, "linear combination of Vectors and coefficients of different sizes should fail");

		Vector<float> u = {1.0, 2.0, 3.0, 4.0};
		std::vector<Vector<float>> vecs3 = {u, v1, v2};
		exceptionCaught = false;
		try
		{
			Vector<float>::linear_combination(vecs3, {10., 0.5, -2.});
		}
		catch (const std::invalid_argument &e)
		{
			exceptionCaught = true;
		}
		assert(exceptionCaught, "linear combination of Vectors of different sizes should fail");
	}

	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}