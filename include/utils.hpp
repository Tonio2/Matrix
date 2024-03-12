#ifndef UTILS_H
#define UTILS_H

#include <stdexcept>
#include <cmath>
#include <iostream>

float linear_interpolation(float a, float b, float t);
void assert(bool condition, const std::string& message);
bool areFloatsEqual(float a, float b);

#endif // UTILS_H