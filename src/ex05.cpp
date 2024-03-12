#include "Vector.hpp"
#include "utils.hpp"

int main()
{
	try
	{
		Vector<float> i = {1.0, 0.0};
		Vector<float> j = {0.0, 1.0};
        float res = Vector<float>::angle_cos(i, j);
        assert(areFloatsEqual(res, 0.0), "cosine of angle between i and j");

		Vector<float> u = {1.0, 2.0, 3.0};
		Vector<float> v = {4.0, 5.0, 6.0};
        res = Vector<float>::angle_cos(u, v);
		assert(areFloatsEqual(res, 0.974631), "cosine of angle between u and v");
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

// Test with wolfram alpha
// cos(VectorAngle[{1, 2, 3}, {4, 5, 6}])