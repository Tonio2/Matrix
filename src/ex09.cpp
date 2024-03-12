#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
	try
	{
		Matrix<float> m = {
			{3., -5.},
			{6., 8.}
		};
        Matrix<float> res = m.transpose();
        Matrix<float> expected = {
            {3., 6.},
            {-5., 8.}
        };
        assert(res == expected, "transpose of Matrix");

		Matrix<float> n = {
			{2., 1.},
			{4., 2.},
			{1., 3.}
		};
        res = n.transpose();
        expected = {
            {2., 4., 1.},
            {1., 2., 3.}
        };
        assert(res == expected, "transpose of Matrix");
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}