#include "Vector.hpp"
#include "utils.hpp"

int main()
{
	try
	{
		Vector<float> v1 = {1.0, -2.0};

        // Test norm_1
        float norm_1 = v1.norm_1();
        float expected_norm_1 = 3.0;
        assert(areFloatsEqual(norm_1, expected_norm_1), "norm_1 of Vector");

        // Test norm_2
        float norm_2 = v1.norm_2();
        float expected_norm_2 = 2.236068;
        bool test = areFloatsEqual(norm_2, expected_norm_2);
        assert(areFloatsEqual(norm_2, expected_norm_2), "norm_2 of Vector");

        // Test norm_inf
        float norm_inf = v1.norm_inf();
        float expected_norm_inf = 2.0;
        assert(areFloatsEqual(norm_inf, expected_norm_inf), "norm_inf of Vector");
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}