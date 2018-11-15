#pragma once

#include "MathLib.h"
#include <string>

namespace Math
{
    class Quaternion
    {
        public:
            Quaternion();
            Quaternion(const float&, const float&, const float&, const float&);
            Quaternion(const Vector&);
            ~Quaternion();
            float w;
            float x;
            float y;
            float z;
            double Magnitude();
            Quaternion Normalized();
            Quaternion Inverse();
            Quaternion Conjugate();
            Quaternion operator+(const Quaternion&);
            Quaternion operator/(const Quaternion&);
            Quaternion operator*(const Quaternion&);
            std::string ToString();
        private:
            
    };
}