#include "Vector.hpp"

int main()
{
	try
	{
		Vector e1 = {1.0, 0.0, 0.0};
		Vector e2 = {0.0, 1.0, 0.0};
		Vector e3 = {0.0, 0.0, 1.0};

		Vector v1 = {2.0, 3.0, 4.0};
		Vector v2 = {5.0, 7.0, 9.0};

		std::vector<Vector> vecs = {e1, e2, e3};
		std::vector<Vector> vecs2 = {v1, v2};
		Vector::linear_combination(vecs, {10., 0.5, -2.}).print();
		Vector::linear_combination(vecs2, {10., -2.}).print();
	}

	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}