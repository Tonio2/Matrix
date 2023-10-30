float linear_interpolation(float u, float v, float t)
{
	return std::fma(t, v - u, u);
}