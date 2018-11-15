#include "include\MathLibrary\MathLib.h"
#include <sstream>

namespace Math
{
    Vector::Vector()
        : x(0), y(0), z(0)
    {
    }
    
    Vector::Vector(float x, float y)
        : x(x), y(y), z(0)
    {
    }

    Vector::Vector(float x, float y, float z)
        : x(x), y(y), z(z)
    {
    }

    Vector::~Vector()
    {
    }

    float Vector::operator*(const Vector& other)
    {
        return this->x * other.x + this->y * other.y + this->z * other.z;
    }

    Vector Vector::operator*(const float& factor)
    {
        return Vector(this->x * factor, this->y * factor, this->z * factor);
    }

    Vector Vector::operator/(const float& divisor)
    {
        return Vector(this->x / divisor, this->y / divisor, this->z / divisor);
    }

    Vector Vector::operator+(const Vector& other)
    {
        return Vector(this->x + other.x, this->y + other.y, this->z + other.z);
    }

    Vector Vector::operator-(const Vector& other)
    {
        return Vector(this->x - other.x, this->y - other.y, this->z - other.z);
    }

    Vector Vector::Cross(const Vector& other)
    {
        return Vector(this->y * other.z - other.y * this->z, this->z * other.x - other.z * this->x, this->x * other.y - other.x * this->y);
    }

    float Vector::Magnitude()
    {
        return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
    }

    Vector Vector::Normalized()
    {
        float magnitude = Magnitude();
        if (magnitude == 0) return Vector();
        return Vector(this->x / magnitude, this->y / magnitude, this->z / magnitude);
    }

    std::string Vector::ToString()
    {
        std::ostringstream out;
        out << std::defaultfloat;
        out << "(" << this->x << ", " << this->y << ", " << this->z << ")";
        return out.str();
    }
}