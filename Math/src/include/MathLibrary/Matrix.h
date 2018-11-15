#pragma once

#include "MathLib.h"
#include <vector>
#include <string>

namespace Math
{
    class Matrix
    {
        public:
            Matrix();
            Matrix(int extents);
            ~Matrix();
            int extents;
            std::vector<int> matrix;
            Matrix& operator+(const Matrix&);
            Matrix& operator-(const Matrix&);
            Matrix& operator*(const int&);
            Matrix& operator*(const Matrix&);
            Matrix& operator/(const int&);
            int Det();
            void Transpose();
            std::string ToString();
        protected:


        private:

    };
}