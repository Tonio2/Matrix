#include <iostream>
#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

using namespace std;

int main() {
	float t = 0.6f;

	// Float
	float res = linear_interpolation(0.0, 10.0, t);
	float expected = 6.0;
    assert(res == expected, "linear interpolation for float");

	// Vector
	Vector<float> v1 = {1.0, 2.0, 3.0};
	Vector<float> v2 = {4.0, 5.0, 6.0};
	Vector<float> vResult = Vector<float>::linear_interpolation(v1, v2, t);
    Vector<float> vExpected = {2.8, 3.8, 4.8};
    assert(vResult == vExpected, "linear interpolation for Vector");

    // Should not work for vectors of different sizes
    Vector<float> v3 = {1.0, 2.0, 3.0, 4.0};
    bool exceptionCaught = false;
    try
    {
        Vector<float>::linear_interpolation(v3, v2, t);
    }
    catch (const std::invalid_argument &e)
    {
        exceptionCaught = true;
    }
    assert(exceptionCaught, "linear interpolation for Vectors of different sizes should fail");

	// Matrix
	Matrix<float> m1 = {
				{1, 2},
				{3, 4}};
	Matrix<float> m2 = {
				{5, 6},
				{7, 8}};
	Matrix<float> mResult = Matrix<float>::linear_interpolation(m1, m2, t);
	Matrix<float> mExpected = {
                {3.4, 4.4},
                {5.4, 6.4}};
    assert(mResult == mExpected, "linear interpolation for Matrix");

    // Should not work for matrices of different sizes
    Matrix<float> m3 = {
                {1, 2, 3},
                {4, 5, 6}};
    exceptionCaught = false;
    try
    {
        Matrix<float>::linear_interpolation(m3, m2, t);
    }
    catch (const std::invalid_argument &e)
    {
        exceptionCaught = true;
    }
    assert(exceptionCaught, "linear interpolation for Matrices of different sizes should fail");

	return 0;
}
