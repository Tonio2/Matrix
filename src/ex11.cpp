#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    try
    {
        // 1. Matrix already in row echelon form.
        Matrix<float> m1 = {
            {1., 0., 0.},
            {0., 1., 0.},
            {0., 0., 1.}
        };
        assert(areFloatsEqual(m1.determinant(), float(1)), "Matrix already in row echelon form");

        // 2. Non-square matrix
        Matrix<float> m2 = {
            {1., 0., 0.},
            {0., 1., 0.}
        };
        // Result is undefined as per the spec

        // 3. Singular matrix
        Matrix<float> m3 = {
            {1., 2., 3.},
            {4., 5., 6.},
            {7., 8., 9.}
        };
        assert(areFloatsEqual(m3.determinant(), float(0)), "Singular matrix");

        // 4. 2x2 matrix
        Matrix<float> m4 = {
            {3., 8.},
            {4., 6.}
        };
        assert(areFloatsEqual(m4.determinant(), float(-14)), "2x2 matrix");

        // 5. 4x4 matrix
        Matrix<float> m5 = {
            {2., -3., 1., 5.},
            {3., 0., 6., 4.},
            {-1., 3., 3., 2.},
            {1., 2., 1., 0.}
        };
        assert(areFloatsEqual(m5.determinant(), float(157)), "4x4 matrix");

        // 6. Matrix with same rows
        Matrix<float> m6 = {
            {1., 2., 3.},
            {1., 2., 3.},
            {1., 2., 3.}
        };
        assert(areFloatsEqual(m6.determinant(), float(0)), "Matrix with same rows");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

// Test on wolfram alpha
// 1. det({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}) = 1
// 3. det({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}) = 0
// 4. det({{3, 8}, {4, 6}}) = -14
// 5. det({{2, -3, 1, 5}, {3, 0, 6, 4}, {-1, 3, 3, 2}, {1, 2, 1, 0}}) = 0