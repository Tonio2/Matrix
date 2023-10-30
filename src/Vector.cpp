#include "Vector.hpp"

Vector::Vector(const size_t size) : data(size) {}
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

void Vector::fma(const Vector &v, float scalar)
{
	if (data.size() != v.data.size())
	{
		throw std::invalid_argument("Vectors must be of the same size.");
	}

	for (size_t i = 0; i < data.size(); ++i)
	{
		data[i] += scalar * v.data[i];
	}
}

Vector Vector::linear_combination(const std::vector<Vector> &vectors, const std::vector<float> &coefficients)
{
	if (vectors.size() != coefficients.size())
	{
		throw std::invalid_argument("Vectors and coefficients must be of the same size.");
	}

	size_t size = vectors[0].data.size();
	for (const Vector &v : vectors)
	{
		if (v.data.size() != size)
		{
			throw std::invalid_argument("Vectors must be of the same size.");
		}
	}

	Vector result(size);
	for (size_t i = 0; i < vectors.size(); ++i)
	{
		result.fma(vectors[i], coefficients[i]);
	}

	return result;
}
