#include "Matrix.hpp"

template <typename T>
Matrix<T>::Matrix(const size_t rows, const size_t columns) : data(rows, std::vector<T>(columns)) {}

template <typename T>
Matrix<T>::Matrix(const std::initializer_list<std::initializer_list<T>> &elements)
{
    for (const std::initializer_list<T> &row : elements)
    {
        std::vector<T> rowVector(row);
        this->data.push_back(rowVector);
    }
}

template <typename T>
bool Matrix<T>::operator==(const Matrix &other) const
{
    // Check if the number of rows and columns are the same
    if (data.size() != other.data.size() || (data.size() && data[0].size() != other.data[0].size()))
    {
        return false;
    }

    if constexpr (std::is_floating_point_v<T>)
    {
        const T EPSILON = std::numeric_limits<T>::epsilon();
        T diff = 0.0;
        for (size_t i = 0; i < data.size(); ++i)
        {
            for (size_t j = 0; j < data[i].size(); ++j)
            {
                diff = data[i][j] - other.data[i][j];
                if (diff > EPSILON || diff < -EPSILON)
                {
                    return false;
                }
            }
        }
    }
    else
    {
        for (size_t i = 0; i < data.size(); ++i)
        {
            for (size_t j = 0; j < data[i].size(); ++j)
            {
                if (data[i][j] != other.data[i][j])
                {
                    return false;
                }
            }
        }
    }

    return true;
}

template <typename T>
void Matrix<T>::print() const
{
    for (const std::vector<T> &row : data)
    {
        for (const T &elem : row)
        {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
void Matrix<T>::add(const Matrix &m)
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

template <typename T>
void Matrix<T>::sub(const Matrix &m)
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

template <typename T>
void Matrix<T>::scl(T scalar)
{
    for (std::vector<T> &row : data)
    {
        for (T &value : row)
        {
            value *= scalar;
        }
    }
}

template <typename T>
Matrix<T> Matrix<T>::linear_interpolation(const Matrix<T> &u, const Matrix<T> &v, T t)
{
    if (u.data.size() != v.data.size())
    {
        throw std::invalid_argument("Matrices must have the same number of rows.");
    }

    for (size_t i = 0; i < u.data.size(); ++i)
    {
        if (u.data[i].size() != v.data[i].size())
        {
            throw std::invalid_argument("Matrices must have the same number of columns.");
        }
    }

    Matrix<T> result(u);

    for (size_t i = 0; i < u.data.size(); ++i)
    {
        for (size_t j = 0; j < u.data[i].size(); ++j)
        {
            result.data[i][j] = std::fma(t, v.data[i][j] - u.data[i][j], u.data[i][j]);
        }
    }

    return result;
}

template <typename T>
Vector<T> Matrix<T>::mul_vec(const Vector<T> &v) const
{
    if (data[0].size() != v.data.size())
    {
        throw std::invalid_argument("Matrix and vector must be compatible for multiplication.");
    }

    Vector<T> result(data.size());
    for (size_t i = 0; i < data.size(); ++i)
    {
        for (size_t j = 0; j < data[i].size(); ++j)
        {
            result.data[i] = std::fma(data[i][j], v.data[j], result.data[i]);
        }
    }

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::mul_mat(const Matrix<T> &m) const
{
    if (data[0].size() != m.data.size())
    {
        throw std::invalid_argument("Matrices must be compatible for multiplication.");
    }

    Matrix<T> result(data.size(), m.data[0].size());
    for (size_t i = 0; i < data.size(); ++i)
    {
        for (size_t j = 0; j < m.data[0].size(); ++j)
        {
            for (size_t k = 0; k < data[i].size(); ++k)
            {
                result.data[i][j] = std::fma(data[i][k], m.data[k][j], result.data[i][j]);
            }
        }
    }

    return result;
}

template <typename T>
T Matrix<T>::trace() const
{
    if (data.size() != data[0].size())
    {
        throw std::invalid_argument("Matrix must be square.");
    }

    T result = 0.0;
    for (size_t i = 0; i < data.size(); ++i)
    {
        result += data[i][i];
    }

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::transpose() const
{
    Matrix<T> result(data[0].size(), data.size());
    for (size_t i = 0; i < data.size(); ++i)
    {
        for (size_t j = 0; j < data[i].size(); ++j)
        {
            result.data[j][i] = data[i][j];
        }
    }

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::row_echelon() const
{
    Matrix<T> result(*this);

    size_t i = 0;
    size_t j = 0;
    while (i < result.data.size() && j < result.data[0].size())
    {
        // Find pivot in column j, starting in row i:
        size_t maxi = i;
        for (size_t k = i + 1; k < result.data.size(); ++k)
        {
            if (std::abs(result.data[k][j]) > std::abs(result.data[maxi][j]))
            {
                maxi = k;
            }
        }
        if (result.data[maxi][j] != 0)
        {
            // Swap row i and row maxi, but do not change the value of i
            if (i != maxi)
            {
                for (size_t k = 0; k < result.data[0].size(); ++k)
                {
                    T aux = result.data[i][k];
                    result.data[i][k] = result.data[maxi][k];
                    result.data[maxi][k] = aux;
                }
            }
            // Now A[i,j] will contain the old value of A[maxi,j].
            // divide each entry in row i by A[i,j]
            T A_ij = result.data[i][j];
            for (size_t k = 0; k < result.data[0].size(); ++k)
            {
                result.data[i][k] /= A_ij;
            }
            // Now A[i,j] will have the value 1.
            for (size_t u = i + 1; u < result.data.size(); ++u)
            {
                // Subtract A[u,j] * row i from row u
                T A_uj = result.data[u][j];
                for (size_t k = 0; k < result.data[0].size(); ++k)
                {
                    result.data[u][k] -= A_uj * result.data[i][k];
                }
                // Now A[u,j] will be 0, since A[u,j] - A[i,j] * A[u,j] = A[u,j] - 1 * A[u,j] = 0.
            }

            i++;
        }
        j++;
    }

    return result;
}

template <typename T>
T Matrix<T>::determinant() const
{
    // Assuming that the matrix is square (as per the given spec)
    size_t n = this->data.size();

    if (n == 1)
    {
        return this->data[0][0];
    }
    else if (n == 2)
    {
        return this->data[0][0] * this->data[1][1] - this->data[0][1] * this->data[1][0];
    }
    else if (n == 3)
    {
        T a = this->data[0][0] * (this->data[1][1] * this->data[2][2] - this->data[1][2] * this->data[2][1]);
        T b = this->data[0][1] * (this->data[1][0] * this->data[2][2] - this->data[1][2] * this->data[2][0]);
        T c = this->data[0][2] * (this->data[1][0] * this->data[2][1] - this->data[1][1] * this->data[2][0]);
        return a - b + c;
    }
    else if (n == 4)
    {
        T det = 0;
        for (size_t i = 0; i < 4; i++)
        {
            // Create a 3x3 matrix excluding the current row and column
            Matrix submat(3, 3);
            for (size_t j = 1; j < 4; j++)
            {
                size_t colIdx = 0;
                for (size_t k = 0; k < 4; k++)
                {
                    if (k == i)
                        continue;
                    submat.data[j - 1][colIdx] = this->data[j][k];
                    colIdx++;
                }
            }
            det += (i % 2 == 0 ? 1 : -1) * this->data[0][i] * submat.determinant();
        }
        return det;
    }

    // If we reach here, it means n > 4 which is not expected as per the spec.
    return 0.0;
}

template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;