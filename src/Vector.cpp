#include "Vector.hpp"

Vector::Vector(const size_t size) : data(size) {}
Vector::Vector(const std::initializer_list<float> &elements) : data(elements) {}

bool Vector::operator==(const Vector &other) const
{
	// Check if the sizes of the two vectors are the same
	if (data.size() != other.data.size())
	{
		return false;
	}

	// Define a small epsilon value for floating-point comparison
	const float EPSILON = 1e-6;
	float diff = 0.0;

	// Compare each element in the vectors
	for (size_t i = 0; i < data.size(); ++i)
	{
		diff = data[i] - other.data[i];
		if (diff > EPSILON || diff < -EPSILON)
		{
			return false;
		}
	}

	// All elements are equal
	return true;
}

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
		data[i] = std::fma(scalar, v.data[i], data[i]);
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

Vector Vector::linear_interpolation(const Vector &u, const Vector &v, float t)
{
	if (u.data.size() != v.data.size())
	{
		throw std::invalid_argument("Vectors must be of the same size.");
	}

	size_t size = u.data.size();
	Vector result(size);
	for (size_t i = 0; i < size; ++i)
	{
		result.data[i] = std::fma(t, v.data[i] - u.data[i], u.data[i]);
	}

	return result;
}

float Vector::dot(const Vector &v) const
{
	if (data.size() != v.data.size())
	{
		throw std::invalid_argument("Vectors must be of the same size.");
	}

	float result = 0.0;
	for (size_t i = 0; i < data.size(); ++i)
	{
		result += data[i] * v.data[i];
	}

	return result;
}

float Vector::norm_1() const
{
	float result = 0.0;
	for (const float &value : data)
	{
		result += std::max(value, -value);
	}

	return result;
}

float Vector::norm_2() const
{
	float result = 0.0;
	for (const float &value : data)
	{
		result += value * value;
	}

	return std::pow(result, 0.5);
}

float Vector::norm_inf() const
{
	float result = 0.0;
	float abs_value = 0.0;
	for (const float &value : data)
	{
		abs_value = std::max(value, -value);
		if (abs_value > result)
		{
			result = abs_value;
		}
	}

	return result;
}

float Vector::angle_cos(const Vector &u, const Vector &v)
{
	if (u.data.size() != v.data.size())
	{
		throw std::invalid_argument("Vectors must be of the same size.");
	}

	float norm_u = u.norm_2();
	float norm_v = v.norm_2();
	float dot_product = u.dot(v);

	return dot_product / (norm_u * norm_v);
}

Vector Vector::cross_product(const Vector &u, const Vector &v)
{
	if (u.data.size() != 3 || v.data.size() != 3)
	{
		throw std::invalid_argument("Vectors must be of size 3.");
	}

	Vector result(3);
	result.data[0] = u.data[1] * v.data[2] - u.data[2] * v.data[1];
	result.data[1] = u.data[2] * v.data[0] - u.data[0] * v.data[2];
	result.data[2] = u.data[0] * v.data[1] - u.data[1] * v.data[0];

	return result;
}