#include "include\MathLibrary\GeneralFunctions.h"

namespace Math
{
#pragma region Min
    int Min(const int& firstInt, const int& secondInt)
    {
        if(firstInt < secondInt) return firstInt;
        else return secondInt;
    }

    float Min(const float& firstFloat, const float& secondFloat)
    {
        if (firstFloat < secondFloat) return firstFloat;
        else return secondFloat;
    }

    double Min(const double& firstDouble, const double& secondDouble)
    {
        if (firstDouble < secondDouble) return firstDouble;
        else return secondDouble;
    }
    #pragma endregion

    #pragma region Max
    int Max(const int& firstInt, const int& secondInt)
    {
        if (firstInt > secondInt) return firstInt;
        else return secondInt;
    }

    float Max(const float& firstFloat, const float& secondFloat)
    {
        if (firstFloat > secondFloat) return firstFloat;
        else return secondFloat;
    }

    double Max(const double& firstDouble, const double& secondDouble)
    {
        if (firstDouble > secondDouble) return firstDouble;
        else return secondDouble;
    }
#pragma endregion
}