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
        float res = m.trace();
        assert(areFloatsEqual(res, 11.0), "trace of Matrix");

        // Should not work if matrix is not square
		Matrix<float> n = {
			{2., 1., 3.},
            {4., 2., 5.}
		};
        bool exceptionCaught = false;
        try
        {
            float o = n.trace();
        }
        catch (const std::invalid_argument &e)
        {
            exceptionCaught = true;
        }
        assert(exceptionCaught, "trace of non-square Matrix should fail");
		
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}