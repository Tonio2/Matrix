// Guard to prevent multiple inclusions
#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <iostream>
#include <cmath>
#include "Vector.hpp"

class Matrix
{
public:
	std::vector<std::vector<float>> data;

	Matrix(const size_t rows, const size_t columns);
	Matrix(const std::initializer_list<std::initializer_list<float>> &elements);

	void print() const;
	void add(const Matrix &m);
	void sub(const Matrix &m);
	void scl(float scalar);

	static Matrix linear_interpolation(const Matrix &u, const Matrix &v, float t);
	
	Vector mul_vec(const Vector &v) const;
	Matrix mul_mat(const Matrix &m) const;

	float trace() const;

	Matrix transpose() const;
	Matrix row_echelon() const;
	
	float determinant() const;

	Matrix inverse() const;

	bool operator==(const Matrix &other) const;
};

#endif // MATRIX_HPP
