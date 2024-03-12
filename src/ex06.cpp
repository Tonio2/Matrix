#include "Vector.hpp"
#include "utils.hpp"

int main()
{
	try
	{
		Vector<float> u = {1.0, 2.0, 3.0};
		Vector<float> v = {4.0, 5.0, 6.0};
		Vector<float> w = Vector<float>::cross_product(u, v);
        Vector<float> expected = {-3.0, 6.0, -3.0};
        assert(w == expected, "cross product of Vectors");

        // Should not work if vector are not of size 3
        Vector<float> x = {1.0, 2.0};
        bool exceptionCaught = false;
        try
        {
            Vector<float> y = Vector<float>::cross_product(u, x);
        }
        catch (const std::invalid_argument &e)
        {
            exceptionCaught = true;
        }
        assert(exceptionCaught, "cross product of Vectors of different sizes should fail");
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}