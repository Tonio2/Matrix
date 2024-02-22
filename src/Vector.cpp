#include "Vector.hpp"

template <typename T>
Vector<T>::Vector(const size_t size) : data(size) {}

template <typename T>
Vector<T>::Vector(const std::initializer_list<T> &elements) : data(elements) {}

template <typename T>
bool Vector<T>::operator==(const Vector &other) const
{
    // Check if the sizes of the two vectors are the same
    if (data.size() != other.data.size())
    {
        return false;
    }

    if constexpr (std::is_floating_point_v<T>)
    {
        const T EPSILON = std::numeric_limits<T>::epsilon();
        T diff = 0.0;

        for (size_t i = 0; i < data.size(); ++i)
        {
            diff = data[i] - other.data[i];
            if (diff > EPSILON || diff < -EPSILON)
            {
                return false;
            }
        }
    }
    else
    {
        for (size_t i = 0; i < data.size(); ++i)
        {
            if (data[i] != other.data[i])
            {
                return false;
            }
        }
    }

    return true;
}

template <typename T>
void Vector<T>::print() const
{
    for (const T &elem : data)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void Vector<T>::add(const Vector &v)
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

template <typename T>
void Vector<T>::sub(const Vector &v)
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

template <typename T>
void Vector<T>::scl(T scalar)
{
    for (T &value : data)
    {
        value *= scalar;
    }
}

template <typename T>
void Vector<T>::fma(const Vector &v, T scalar)
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

template <typename T>
Vector<T> Vector<T>::linear_combination(const std::vector<Vector<T>> &vectors, const std::vector<T> &coefficients)
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

template <typename T>
Vector<T> Vector<T>::linear_interpolation(const Vector<T> &u, const Vector<T> &v, T t)
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

template <typename T>
T Vector<T>::dot(const Vector &v) const
{
    if (data.size() != v.data.size())
    {
        throw std::invalid_argument("Vectors must be of the same size.");
    }

    T result = 0.0;
    for (size_t i = 0; i < data.size(); ++i)
    {
        result += data[i] * v.data[i];
    }

    return result;
}

template <typename T>
T Vector<T>::norm_1() const
{
    T result = 0.0;
    for (const T &value : data)
    {
        result += std::max(value, -value);
    }

    return result;
}

template <typename T>
T Vector<T>::norm_2() const
{
    T result = 0.0;
    for (const T &value : data)
    {
        result += value * value;
    }

    return std::pow(result, 0.5);
}

template <typename T>
T Vector<T>::norm_inf() const
{
    T result = 0.0;
    T abs_value = 0.0;
    for (const T &value : data)
    {
        abs_value = std::max(value, -value);
        if (abs_value > result)
        {
            result = abs_value;
        }
    }

    return result;
}

template <typename T>
T Vector<T>::angle_cos(const Vector &u, const Vector &v)
{
    if (u.data.size() != v.data.size())
    {
        throw std::invalid_argument("Vectors must be of the same size.");
    }

    T norm_u = u.norm_2();
    T norm_v = v.norm_2();
    T dot_product = u.dot(v);

    return dot_product / (norm_u * norm_v);
}

template <typename T>
Vector<T> Vector<T>::cross_product(const Vector<T> &u, const Vector<T> &v)
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

template class Vector<int>;
template class Vector<float>;
template class Vector<double>;