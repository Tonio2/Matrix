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
        int rank1 = m1.rank();
        assert(rank1 == 3, "Matrix already in row echelon form");

        // 2. Matrix not in row echelon form.
        Matrix<float> m2 = {
            {0., 2., 3.},
            {4., 5., 6.},
            {7., 8., 9.}
        };
        int rank2 = m2.rank();
        assert(rank2 == 3, "Matrix not in row echelon form");

        // 3. Singular matrix.
        Matrix<float> m3 = {
            {1., 2., 3.},
            {0., 0., 0.},
            {4., 5., 6.}
        };
        int rank3 = m3.rank();
        assert(rank3 == 2, "Singular matrix");

        // 4. Matrix with more rows than columns.
        Matrix<float> m4 = {
            {1., 2.},
            {3., 4.},
            {5., 6.}
        };
        int rank4 = m4.rank();
        assert(rank4 == 2, "Matrix with more rows than columns");

        // 5. Matrix with more columns than rows.
        Matrix<float> m5 = {
            {1., 2., 3., 4.},
            {5., 6., 7., 8.}
        };
        int rank5 = m5.rank();
        assert(rank5 == 2, "Matrix with more columns than rows");

        // 6. Matrix 4*4 for more extensive testing
        Matrix<float> m6 = {
            {4, 2, 3, 1},
            {0, 5, 2, 2},
            {1, 2, 4, 3},
            {3, 1, 1, 5}};
        int rank6 = m6.rank();
        assert(rank6 == 4, "Matrix 4*4 for more extensive testing");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

// Test with wolfram alpha
// rank {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}
// rank {{0, 2, 3}, {4, 5, 6}, {7, 8, 9}}
// rank {{1, 2, 3}, {0, 0, 0}, {4, 5, 6}}
// rank {{1, 2}, {3, 4}, {5, 6}}
// rank {{1, 2, 3, 4}, {5, 6, 7, 8}}
// rank {{4, 2, 3, 1}, {0, 5, 2, 2}, {1, 2, 4, 3}, {3, 1, 1, 5}}