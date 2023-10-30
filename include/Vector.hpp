#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>
#include <iostream>
#include <cmath>

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
	static Vector linear_interpolation(const Vector &u, const Vector &v, float t);

	float dot(const Vector &other) const;
	float norm_1() const;
	float norm_2() const;
	float norm_inf() const;

	static float angle_cos(const Vector &u, const Vector &v);
	static Vector cross_product(const Vector &u, const Vector &v);
};

#endif // VECTOR_HPP
