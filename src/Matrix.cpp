#include "Matrix.hpp"

Matrix::Matrix(const std::initializer_list<std::initializer_list<float>> &elements)
{
	for (const std::initializer_list<float> &row : elements)
	{
		std::vector<float> rowVector(row);
		this->data.push_back(rowVector);
	}
}

void Matrix::print() const
{
	for (const std::vector<float> &row : data)
	{
		for (const float &elem : row)
		{
			std::cout << elem << " ";
		}
		std::cout << std::endl;
	}
}

void Matrix::add(const Matrix &m)
{
	if (data.size() != m.data.size())
	{
		throw std::invalid_argument("Matrices must have the same number of rows.");
	}

	for (size_t i = 0; i < data.size(); ++i)
	{
		if (data[i].size() != m.data[i].size())
		{
			throw std::invalid_argument("Matrices must have the same number of columns.");
		}

		for (size_t j = 0; j < data[i].size(); ++j)
		{
			data[i][j] += m.data[i][j];
		}
	}
}

void Matrix::sub(const Matrix &m)
{
	if (data.size() != m.data.size())
	{
		throw std::invalid_argument("Matrices must have the same number of rows.");
	}

	for (size_t i = 0; i < data.size(); ++i)
	{
		if (data[i].size() != m.data[i].size())
		{
			throw std::invalid_argument("Matrices must have the same number of columns.");
		}

		for (size_t j = 0; j < data[i].size(); ++j)
		{
			data[i][j] -= m.data[i][j];
		}
	}
}

void Matrix::scl(float scalar)
{
	for (std::vector<float> &row : data)
	{
		for (float &value : row)
		{
			value *= scalar;
		}
	}
}