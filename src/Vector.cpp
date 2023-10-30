#include "Vector.hpp"

Vector::Vector(const std::initializer_list<float> &elements) : data(elements) {}

void Vector::print() const
{
	for (const float &elem : data)
	{
		std::cout << elem << " ";
	}
	std::cout << std::endl;
}

void Vector::add(const Vector &v)
{
	if (data.size() != v.data.size())
	{
		throw std::invalid_argument("Vectors must be of the same size.");
	}

	for (size_t i = 0; i < data.size(); ++i)
	{
		data[i] += v.data[i];
	}
}

void Vector::sub(const Vector &v)
{
	if (data.size() != v.data.size())
	{
		throw std::invalid_argument("Vectors must be of the same size.");
	}

	for (size_t i = 0; i < data.size(); ++i)
	{
		data[i] -= v.data[i];
	}
}

void Vector::scl(float scalar)
{
	for (float &value : data)
	{
		value *= scalar;
	}
}
