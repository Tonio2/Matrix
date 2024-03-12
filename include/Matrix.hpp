// Guard to prevent multiple inclusions
#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <iostream>
#include <cmath>
#include "Vector.hpp"

template<typename T>
class Matrix
{
public:
	std::vector<std::vector<T>> data;

	Matrix(const size_t rows, const size_t columns);
	Matrix(const std::initializer_list<std::initializer_list<T>> &elements);

	void print() const;
	void add(const Matrix &m);
	void sub(const Matrix &m);
	void scl(T scalar);

	static Matrix linear_interpolation(const Matrix &u, const Matrix &v, T t);
	
	Vector<T> mul_vec(const Vector<T> &v) const;
	Matrix mul_mat(const Matrix &m) const;

	T trace() const;

	Matrix transpose() const;
	Matrix row_echelon() const;
	
	T determinant() const;

	Matrix inverse() const;

    int rank() const;

	bool operator==(const Matrix &other) const;
};

#endif // MATRIX_HPP
