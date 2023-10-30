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
        std::cout << "Row echelon form of m1 is:" << std::endl;
        m1.row_echelon().print();

        // 2. Matrix not in row echelon form.
        Matrix m2 = {
            {0., 2., 3.},
            {4., 5., 6.},
            {7., 8., 9.}
        };
        std::cout << "Row echelon form of m2 is:" << std::endl;
        m2.row_echelon().print();

        // 3. Singular matrix.
        Matrix m3 = {
            {1., 2., 3.},
            {0., 0., 0.},
            {4., 5., 6.}
        };
        std::cout << "Row echelon form of m3 is:" << std::endl;
        m3.row_echelon().print();

        // 4. Matrix with more rows than columns.
        Matrix m4 = {
            {1., 2.},
            {3., 4.},
            {5., 6.}
        };
        std::cout << "Row echelon form of m4 is:" << std::endl;
        m4.row_echelon().print();

        // 5. Matrix with more columns than rows.
        Matrix m5 = {
            {1., 2., 3., 4.},
            {5., 6., 7., 8.}
        };
        std::cout << "Row echelon form of m5 is:" << std::endl;
        m5.row_echelon().print();

        // 6. Empty matrix. This should probably fail.
        Matrix m6 = {};
        std::cout << "Row echelon form of m6 is:" << std::endl;
        m6.row_echelon().print();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
