#pragma once

#include "MathLib.h"
#include <string>

namespace Math
{
    class Vector
    {
        public:
            Vector();
            Vector(float x, float y);
            Vector(float x, float y, float z);
            ~Vector();
            float x;
            float y;
            float z;
            float operator*(const Vector&);
            Vector operator*(const float&);
            Vector operator/(const float&);
            Vector operator+(const Vector&);
            Vector operator-(const Vector&);
            Vector Cross(const Vector&);
            float Magnitude();
            Vector Normalized();
            std::string ToString();
        protected:
        
        private:
            
    };
}