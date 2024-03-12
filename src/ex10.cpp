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
        Matrix<float> expected1 = {
            {1., 0., 0.},
            {0., 1., 0.},
            {0., 0., 1.}
        };
        assert(m1.row_echelon() == expected1, "Matrix already in row echelon form");

        // 2. Matrix not in row echelon form.
        Matrix<float> m2 = {
            {0., 2., 3.},
            {4., 5., 6.},
            {7., 8., 9.}
        };
        Matrix<float> expected2 = {
            {1, 8./7., 9./7.},
            {0., 1., 3./2.},
            {0., 0., 1.}
        };
        assert(m2.row_echelon() == expected2, "Matrix not in row echelon form");

        // 3. Singular matrix.
        Matrix<float> m3 = {
            {1., 2., 3.},
            {0., 0., 0.},
            {4., 5., 6.}
        };
        Matrix<float> expected3 = {
            {1., 5./4., 3./2.},
            {0., 1., 2.},
            {0., 0., 0.}
        };
        assert(m3.row_echelon() == expected3, "Singular matrix");

        // 4. Matrix with more rows than columns.
        Matrix<float> m4 = {
            {1., 2.},
            {3., 4.},
            {5., 6.}
        };
        Matrix<float> expected4 = {
            {1., 1.2},
            {0., 1.},
            {0., 0.}
        };
        assert(m4.row_echelon() == expected4, "Matrix with more rows than columns");

        // 5. Matrix with more columns than rows.
        Matrix<float> m5 = {
            {1., 2., 3., 4.},
            {5., 6., 7., 8.}
        };
        Matrix<float> expected5 = {
            {1., 1.2, 1.4, 1.6},
            {0., 1., 2., 3.}
        };
        Matrix<float> result = m5.row_echelon();
        bool test = result == expected5;
        assert(m5.row_echelon() == expected5, "Matrix with more columns than rows");

        // 6. Empty matrix. Nothing should happen.
        Matrix<float> m6 = {};
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

// Test with wolfram alpha
// RowReduce[{{0, 2, 3}, {4, 5, 6}, {7, 8, 9}}]