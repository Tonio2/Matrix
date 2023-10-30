#include <iostream>
#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.cpp"

using namespace std;

int main() {
	float t = 0.6f;

	// Float
	float result = linear_interpolation(0.0, 10.0, t);
	cout << "Linear interpolation for float: " << result << endl;

	// Vector
	Vector v1 = {1.0, 2.0, 3.0};
	Vector v2 = {4.0, 5.0, 6.0};
	Vector vResult = Vector::linear_interpolation(v1, v2, t);
	cout << "Linear interpolation for Vector: " << endl;
	vResult.print();

	// Matrix
	Matrix m1 = {
				{1, 2},
				{3, 4}};
	Matrix m2 = {
				{5, 6},
				{7, 8}};
	Matrix mResult = Matrix::linear_interpolation(m1, m2, t);
	cout << "Linear interpolation for Matrix: " << endl;
	mResult.print();

	return 0;
}
