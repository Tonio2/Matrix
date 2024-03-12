#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    try
    {
        Matrix<float> m1 = {
            {4, 7, 2},
            {3, 6, 1},
            {2, 5, 3}};
        Matrix<float> m1Inverse = m1.inverse();
        Matrix<float> m1InverseExpected = {{13. / 9., -11. / 9., -5. / 9.}, {-7. / 9., 8. / 9., 2. / 9.}, {1. / 3., -2. / 3., 1. / 3.}};
        assert(m1Inverse == m1InverseExpected, "Regular square matrix");

        // Identity matrix
        Matrix<float> m2 = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}};
        Matrix<float> m2Inverse = m2.inverse();
        Matrix<float> m2InverseExpected = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        assert(m2Inverse == m2InverseExpected, "Identity matrix");

        // Singular matrix (determinant should be zero)
        Matrix<float> m3 = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};
        bool exceptionThrown = false;
        try
        {
            m3.inverse();
        }
        catch (const std::exception &e)
        {
            exceptionThrown = true;
        }
        assert(exceptionThrown, "Singular matrix");

        // Another regular square matrix
        Matrix<float> m4 = {
            {2, -1, 0},
            {-1, 2, -1},
            {0, -1, 2}};
        Matrix<float> m4Inverse = m4.inverse();
        Matrix<float> m4InverseExpected = {{3. / 4., 1. / 2., 1. / 4.}, {1. / 2., 1., 1. / 2.}, {1. / 4., 1. / 2., 3. / 4.}};
        assert(m4Inverse == m4InverseExpected, "Regular square matrix");

        // Matrix with negative numbers
        Matrix<float> m5 = {
            {-3, 5, -1},
            {2, -4, 6},
            {-1, 2, -1}};
        Matrix<float> m5Inverse = m5.inverse();
        Matrix<float> m5InverseExpected = {{-2., 3. / 4., 13. / 2.}, {-1., 1. / 2., 4.}, {0., 1. / 4., 1. / 2.}};
        assert(m5Inverse == m5InverseExpected, "Regular square matrix with negative numbers");

        // Square matrix of size 2 for edge case testing
        Matrix<float> m6 = {
            {3, 5},
            {2, 4}};
        Matrix<float> m6Inverse = m6.inverse();
        Matrix<float> m6InverseExpected = {{2., -2.5}, {-1., 1.5}};
        assert(m6Inverse == m6InverseExpected, "2x2 square matrix");

        // Larger square matrix (4x4) for more comprehensive testing
        Matrix<float> m7 = {
            {4, 2, 3, 1},
            {0, 5, 2, 2},
            {1, 2, 4, 3},
            {3, 1, 1, 5}};
        Matrix<float> m7Inverse = m7.inverse();
        Matrix<float> m7InverseExpected = {{67. / 281., -11. / 281., -50. / 281., 21. / 281.}, {14. / 281., 69. / 281., -44. / 281., -4. / 281.}, {10. / 281., -31. / 281., 89. / 281., -43. / 281.}, {-45. / 281., -1. / 281., 21. / 281., 53. / 281.}};
        assert(m7Inverse == m7InverseExpected, "4x4 square matrix");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

// Test wolfram alpha
// inverse {{4, 7, 2}, {3, 6, 1}, {2, 5, 3}}
// inverse {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}
//
// inverse {{2, -1, 0}, {-1, 2, -1}, {0, -1, 2}}
// inverse {{-3, 5, -1}, {2, -4, 6}, {-1, 2, -1}}
// inverse {{3, 5}, {2, 4}}
// inverse {{4, 2, 3, 1}, {0, 5, 2, 2}, {1, 2, 4, 3}, {3, 1, 1, 5}}