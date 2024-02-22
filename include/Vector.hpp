#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>
#include <iostream>
#include <cmath>

template<typename T>
class Vector
{
public:
	std::vector<T> data;

	Vector(const size_t size);
	Vector(const std::initializer_list<T> &elements);

	void print() const;
	void add(const Vector &other);
	void sub(const Vector &other);
	void scl(T scalar);
	void fma(const Vector &other, T scalar);

	static Vector linear_combination(const std::vector<Vector> &vectors, const std::vector<T> &coefficients);
	static Vector linear_interpolation(const Vector &u, const Vector &v, T t);

	T dot(const Vector &other) const;
	T norm_1() const;
	T norm_2() const;
	T norm_inf() const;

	static T angle_cos(const Vector &u, const Vector &v);
	static Vector cross_product(const Vector &u, const Vector &v);

	bool operator==(const Vector &other) const;
};

#endif // VECTOR_HPP
