#include "include\MathLibrary\Matrix.h"

namespace Math
{
    Matrix::Matrix()
        : extents(3), matrix(3 * 3)
    {
    }

    Matrix::Matrix(int newExtents)
        : extents(newExtents), matrix(newExtents*newExtents)
    {
    }

    Matrix::~Matrix()
    {
        delete(&matrix);
    }

    Matrix& Matrix::operator+(const Matrix& other)
    {
        if(this->extents != other.extents) throw new std::exception("Cannot add matrizes of different sizes!");
        Matrix& result = *(new Matrix(this->extents));
        for (int i = 0; i < this->extents * this->extents; i++)
        {
            result.matrix[i] = this->matrix[i] + other.matrix[i];
        }
        return result;
    }

    Matrix& Matrix::operator-(const Matrix& other)
    {
        if (this->extents != other.extents) throw new std::exception("Cannot subtract matrizes of different sizes!");
        Matrix& result = *(new Matrix(this->extents));
        for (int i = 0; i < this->extents * this->extents; i++)
        {
            result.matrix[i] = this->matrix[i] - other.matrix[i];
        }
        return result;
    }

    Matrix& Matrix::operator*(const int& factor)
    {
        Matrix& result = *(new Matrix(this->extents));
        for (int i = 0; i < this->extents * this->extents; i++)
        {
            result.matrix[i] = this->matrix[i] * factor;
        }
        return result;
    }

    Matrix& Matrix::operator*(const Matrix& other)
    {
        if (this->extents != other.extents) throw new std::exception("Cannot multiply matrizes of different sizes!");
        Matrix& result = *(new Matrix(this->extents));
        for (int y = 0; y < this->extents; y++)
        {
            for (int column = 0; column < this->extents; column++)
            {
                for (int x = 0; x < this->extents; x++)
                {
                    result.matrix[y * result.extents + column] += this->matrix[y * this->extents + x] * other.matrix[x * other.extents + column];
                }
            }
        }
        return result;
    }

    Matrix& Matrix::operator/(const int& divisor)
    {
        Matrix& result = *(new Matrix(this->extents));
        for (int i = 0; i < this->extents * this->extents; i++)
        {
            result.matrix[i] = this->matrix[i] / divisor;
        }
        return result;
    }

    int Matrix::Det()
    {
        int det = 0;
        int diagValue;
        for (int i = 0; i < extents; i++)
        {
            for (int x = i, y = 0; y < extents; x++, y++)
            {
                if(y == 0)
                {
                    diagValue = matrix[(y % extents) * extents + (x % extents)];
                }
                else
                {
                    diagValue *= matrix[(y % extents) * extents + (x % extents)];
                }
            }
            det += diagValue;

            for (int x = i, y = extents - 1; y >= 0; x++, y--)
            {
                if (y == extents - 1)
                {
                    diagValue = matrix[(y < 0 ? (extents + y) : y) * extents + (x % extents)];
                }
                else
                {
                    diagValue *= matrix[(y < 0 ? (extents + y) : y) * extents + (x % extents)];
                }
            }
            det -= diagValue;
        }

        return det;
    }

    void Matrix::Transpose()
    {
        for (int y = 0; y < extents - 1; y++)
        {
            for (int x = y+1; x < extents; x++)
            {
                int temp = this->matrix[y * extents + x];
                this->matrix[y * extents + x] = this->matrix[x * extents + y];
                this->matrix[x * extents + y] = temp;
            }
        }
    }

    std::string Matrix::ToString()
    {
        std::string string = "";
        for (int y = 0; y < extents; y++)
        {
            for (int x = 0; x < extents; x++)
            {
                string += std::to_string(matrix[y * extents + x])
                    + (matrix[y * extents + x] < 10 ? "  " : " ");

            }
            string += '\n';
        }

        return string;
    }
}