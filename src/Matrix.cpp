#include "Matrix.hpp"
#include "utils.hpp"

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
        const T EPSILON = 10 * std::numeric_limits<T>::epsilon();
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
    T nullValue = T(0);

    size_t i = 0;
    size_t j = 0;
    while (i < result.data.size() && j < result.data[0].size())
    {
        // Find pivot in column j, starting in row i:
        size_t maxi = i;
        for (size_t k = i + 1; k < result.data.size(); ++k)
        {
            if (absVal<T>(result.data[k][j]) > absVal<T>(result.data[maxi][j]))
            {
                maxi = k;
            }
        }
        if (not areFloatsEqual(result.data[maxi][j], nullValue))
        {
            // Swap row i and row maxi, but do not change the value of i
            if (i != maxi)
            {
                for (size_t k = 0; k < result.data[0].size(); ++k)
                {
                    std::swap(result.data[i][k], result.data[maxi][k]);
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
        Matrix submat(3, 3);
        for (size_t i = 0; i < 4; i++)
        {
            // Create a 3x3 matrix excluding the first row and the i-th column
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

template <typename T>
Matrix<T> Matrix<T>::inverse() const
{
    T nullValue = T(0);

    if (data.size() != data[0].size())
    {
        throw std::invalid_argument("Matrix must be square to find its inverse.");
    }

    size_t n = data.size();
    Matrix<T> result(n, n * 2);

    // Construct augmented matrix: [A | I]
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            result.data[i][j] = data[i][j];
        }
        result.data[i][i + n] = 1;
    }

    // Apply Gauss-Jordan elimination
    for (size_t i = 0; i < n; ++i)
    {
        // Find the pivot
        size_t maxRow = i;
        for (size_t k = i + 1; k < n; ++k)
        {
            if (absVal<T>(result.data[k][i]) > absVal<T>(result.data[maxRow][i]))
            {
                maxRow = k;
            }
        }
        if (areFloatsEqual(result.data[maxRow][i], nullValue))
        {
            throw std::runtime_error("Matrix is singular and cannot be inverted.");
        }

        // Swap rows
        std::swap(result.data[i], result.data[maxRow]);

        // Scale to make the pivot 1
        T pivot = result.data[i][i];
        for (size_t j = 0; j < 2 * n; ++j)
        {
            result.data[i][j] /= pivot;
        }

        // Zero out other elements in the column
        for (size_t u = 0; u < n; ++u)
        {
            if (u != i)
            {
                T factor = result.data[u][i];
                for (size_t j = 0; j < 2 * n; ++j)
                {
                    result.data[u][j] -= factor * result.data[i][j];
                }
            }
        }
    }

    // Extract the inverse matrix from the augmented matrix
    Matrix<T> inverseMatrix(n, n);
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            inverseMatrix.data[i][j] = result.data[i][j + n];
        }
    }

    return inverseMatrix;
}

template <typename T>
int Matrix<T>::rank() const {
    T nullValue = T(0);
    Matrix<T> ref = this->row_echelon();
    int rank = 0;
    for (const auto& row : ref.data) {
        for (const auto& element : row) {
            if (!areFloatsEqual(element, nullValue)) {
                ++rank;
                break;
            }
        }
    }
    return rank;
}

template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;