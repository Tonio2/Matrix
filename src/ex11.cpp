#include "Matrix.hpp"

int main()
{
    try
    {
        // 1. Matrix already in row echelon form.
        Matrix m1 = {
            {1., 0., 0.},
            {0., 1., 0.},
            {0., 0., 1.}
        };
        std::cout << "det(m1) = " << m1.determinant() << std::endl;

        // 2. Non-square matrix
        Matrix m2 = {
            {1., 0., 0.},
            {0., 1., 0.}
        };
        std::cout << "det(m2) = " << m2.determinant() << std::endl;

        // 3. Singular matrix
        Matrix m3 = {
            {1., 2., 3.},
            {4., 5., 6.},
            {7., 8., 9.}
        };
        std::cout << "det(m3) = " << m3.determinant() << std::endl;

        // 4. 2x2 matrix
        Matrix m4 = {
            {3., 8.},
            {4., 6.}
        };
        std::cout << "det(m4) = " << m4.determinant() << std::endl;

        // 5. 4x4 matrix
        Matrix m5 = {
            {2., -3., 1., 5.},
            {3., 0., 6., 4.},
            {-1., 3., 3., 2.},
            {1., 2., 1., 0.}
        };
        std::cout << "det(m5) = " << m5.determinant() << std::endl;

        // 6. Matrix with same rows
        Matrix m6 = {
            {1., 2., 3.},
            {1., 2., 3.},
            {1., 2., 3.}
        };
        std::cout << "det(m6) = " << m6.determinant() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
