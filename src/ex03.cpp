#include "Vector.hpp"
#include "utils.hpp"

int main()
{
	try
	{
		Vector<float> u = {1.0, 2.0, 3.0};
		Vector<float> v = {4.0, 5.0, 6.0};
        Vector<float> w = u.dot(v);
        float expected = 32.0;
        assert(w == expected, "dot product of Vectors");

        // Should not work if vector are not the same size
        Vector<float> x = {1.0, 2.0};
        bool exceptionCaught = false;
        try
        {
            Vector<float> y = u.dot(x);
        }
        catch (const std::invalid_argument &e)
        {
            exceptionCaught = true;
        }
        assert(exceptionCaught, "dot product of Vectors of different sizes should fail");
	}

	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}