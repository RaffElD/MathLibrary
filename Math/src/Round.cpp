#include "include\MathLibrary\Round.h"
#include <cmath>

namespace Math
{
    int RoundToInt(const float& someFloat)
    {
        int intValue = (int)someFloat;
        if(std::fmodf(someFloat, 1) >= 0.5f) intValue++;
        return intValue;
    }

    float Round(const float& someFloat, int digits)
    {
        return ((float)RoundToInt(someFloat * (10 ^ digits))/(10 ^ digits));
    }
}