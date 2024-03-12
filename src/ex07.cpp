#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    try
    {
        Matrix<float> u = {
            {1.0, 0.0},
            {0.0, 1.0}};
        Vector<float> v = {4.0, 5.0};
        Vector<float> w = u.mul_vec(v);
        Vector<float> expected = {4.0, 5.0};
        assert(w == expected, "multiplication of Matrix and Vector");

        // Should not work if matrix and vector are not of the same size
        Matrix<float> x = {
            {1.0, 0.0, 0.0},
            {0.0, 1.0, 0.0}};
        bool exceptionCaught = false;
        try
        {
            Vector<float> y = x.mul_vec(v);
        }
        catch (const std::invalid_argument &e)
        {
            exceptionCaught = true;
        }
        assert(exceptionCaught, "multiplication of Matrix and Vector of different sizes should fail");

        Matrix<float> m = {
            {3., -5.},
            {6., 8.}};
        Matrix<float> n = {
            {2., 1.},
            {4., 2.}};
        Matrix<float> o = m.mul_mat(n);
        Matrix<float> expected2 = {
            {-14., -7.},
            {44., 22.}};
        assert(o == expected2, "multiplication of Matrices");

        // Should not work if matrices are not of the same size
        Matrix<float> p = {
            {1., 2.},
            {3., 4.},
            {5., 6.}};
        bool exceptionCaught2 = false;
        try
        {
            Matrix<float> q = m.mul_mat(p);
        }
        catch (const std::invalid_argument &e)
        {
            exceptionCaught2 = true;
        }
        assert(exceptionCaught2, "multiplication of Matrices of different sizes should fail");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

// Test with wolfram alpha
// {{3,-5},{6,8}} * {{2,1},{4,2}}