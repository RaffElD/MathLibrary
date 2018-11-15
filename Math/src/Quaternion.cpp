#include "include\MathLibrary\MathLib.h"
#include <sstream>

namespace Math
{
    Quaternion::Quaternion()
        : w(0), x(0), y(0), z(0)
    {
    }

    Quaternion::Quaternion(const float& w, const float& x, const float& y, const float& z)
        : w(w), x(x), y(y), z(z)
    {
    }

    Quaternion::Quaternion(const Vector& v)
        : w(0), x(v.x), y(v.y), z(v.z)
    {
    }

    Quaternion::~Quaternion()
    {
    }

    double Quaternion::Magnitude()
    {
        return sqrt(powf(this->w, 2) + powf(this->x, 2) + powf(this->y, 2) + powf(this->z, 2));
    }

    Quaternion Quaternion::Normalized()
    {
        float magnitude = (float)this->Magnitude();
        return Quaternion(this->w/magnitude, this->x / magnitude, this->y / magnitude, this->z / magnitude);
    }

    Quaternion Quaternion::Conjugate()
    {
        return Quaternion(this->w, -this->x, -this->y, -this->z);
    }

    Quaternion Quaternion::Inverse()
    {
        float quotient = this->w*this->w + this->x*this->x + this->y*this->y + this->z*this->z;
        Quaternion conjugate = this->Conjugate();
        return Quaternion(conjugate.w/quotient, conjugate.x/quotient, conjugate.y/quotient, conjugate.z/quotient);
    }

    Quaternion Quaternion::operator+(const Quaternion& other)
    {
        Quaternion q(this->w + other.w, this->x + other.x, this->y + other.y, this->z + other.z);
        return q;
    }

    Quaternion Quaternion::operator/(const Quaternion& other)
    {
        float quotient = this->w*this->w + this->x*this->x + this->y*this->y + this->z*this->z;
        Quaternion q;
        q.w = (this->w*other.w + this->x*other.x + this->y*other.y + this->z*other.z)/quotient;
        q.x = (this->w*other.x - this->x*other.w - this->y*other.z + this->z*other.y)/quotient;
        q.y = (this->w*other.y + this->x*other.z - this->y*other.w - this->z*other.x)/quotient;
        q.z = (this->w*other.z - this->x*other.y + this->y*other.x - this->z*other.w)/quotient;
        return q;
    }

    Quaternion Quaternion::operator*(const Quaternion& other)
    {
        Quaternion q;
        q.w = this->w*other.w - this->x*other.x - this->y*other.y - this->z*other.z;
        q.x = this->w*other.x + this->x*other.w + this->y*other.z - this->z*other.y;
        q.y = this->w*other.y - this->x*other.z + this->y*other.w + this->z*other.x;
        q.z = this->w*other.z + this->x*other.y - this->y*other.x + this->z*other.w;
        return q;
    }

    std::string Quaternion::ToString()
    {
        std::ostringstream out;
        out << std::defaultfloat;
        out << "W: " << this->w << "; X: " << this->x << "; Y: " << this->y << "; Z: " << this->z;
        return out.str();
    }
}