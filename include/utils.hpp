#ifndef UTILS_H
#define UTILS_H

#include <stdexcept>
#include <cmath>
#include <iostream>

float linear_interpolation(float a, float b, float t);
void assert(bool condition, const std::string &message);
template<typename T>
bool areFloatsEqual(T a, T b)
{
    const T EPSILON = 10 * std::numeric_limits<T>::epsilon();
    T diff = a - b;
    return (diff <= EPSILON && diff >= -EPSILON);
}
template <typename T>
T absVal(T a)
{
    return a < T(0) ? -a : a;
}

#endif // UTILS_H