// Guard to prevent multiple inclusions
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>
#include <iostream>

class Vector
{
public:
	std::vector<float> data;

	Vector(const std::initializer_list<float> &elements);

	void print() const;
	void add(const Vector &other);
	void sub(const Vector &other);
	void scl(float scalar);
};

#endif // VECTOR_HPP
