// Guard to prevent multiple inclusions
#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <iostream>

class Matrix
{
public:
	std::vector<std::vector<float>> data;

	Matrix(const std::initializer_list<std::initializer_list<float>> &elements);

	void print() const;
	void add(const Matrix &m);
	void sub(const Matrix &m);
	void scl(float scalar);
};

#endif // MATRIX_HPP
