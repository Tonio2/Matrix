#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>
#include <iostream>

class Vector
{
public:
	std::vector<float> data;

	Vector(const size_t size);
	Vector(const std::initializer_list<float> &elements);

	void print() const;
	void add(const Vector &other);
	void sub(const Vector &other);
	void scl(float scalar);
	void fma(const Vector &other, float scalar);

	static Vector linear_combination(const std::vector<Vector> &vectors, const std::vector<float> &coefficients);
};

#endif // VECTOR_HPP
