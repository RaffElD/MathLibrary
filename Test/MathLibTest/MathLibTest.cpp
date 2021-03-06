// MathLibTest.cpp : Defines the entry point for the console application.
//

#include "MathLibrary\MathLib.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "Matrizes:" << "\n\n";
    const int extents = 3;
    Math::Matrix& m0 = *(new Math::Matrix(extents));
    for (int i = 0; i < extents * extents; i++) { m0.matrix[i] = i; }
    Math::Matrix& m1 = *(new Math::Matrix(extents));
    for (int i = 0; i < extents * extents; i++) { m1.matrix[i] = i+1; }

    cout << m0.ToString() << "+\n" << m1.ToString() << "=\n" << (m0 + m1).ToString() << "\n\n";
    cout << m0.ToString() << "-\n" << m1.ToString() << "=\n" << (m0 - m1).ToString() << "\n\n";
    cout << m0.ToString() << "*\n" << 2 << "=\n" << (m0 * 2).ToString() << "\n\n";
    cout << m0.ToString() << "/\n" << 2 << "=\n" << (m0 / 2).ToString() << "\n\n";
    cout << m0.ToString() << "*\n" << m1.ToString() << "=\n" << (m0 * m1).ToString() << "\n\n";

    /*cout << m0.ToString() << "\n";
    m0.Transpose();
    cout << "Transposed:\n" << "\n";
    cout << m0.ToString() << "\n\n";*/

    /*cout << "Quaternions:" << "\n\n";

    Math::Quaternion q1(1, 2, 3, 4);
    Math::Quaternion q2(8, 7, 6, 5);
    Math::Quaternion q3(9, 11, 13, 10);
    
    cout << "A: " << q1.ToString() << "\n";
    cout << "B: " << q2.ToString() << "\n";
    cout << "C: " << q3.ToString() << "\n\n";

    cout << "A+B+C = " << (q1+q2+q3).ToString() << "\n";
    cout << "C+B+A = " << (q3+q2+q1).ToString() << "\n\n";

    cout << "A*B = " << (q1*q2).ToString() << "\n";
    cout << "B*A = " << (q2*q1).ToString() << "\n\n";

    cout << "(A+B)*C = " << ((q1+q2)*q3).ToString() << "\n";
    cout << "A*C+B*C = " << ((q1*q3)+(q2*q3)).ToString() << "\n\n";

    cout << "(A*B)*C = " << ((q1*q2)*q3).ToString() << "\n";
    cout << "A*(B*C) = " << (q1*(q2*q3)).ToString() << "\n\n";
    
    cout << "A/B = " << (q1/q2).ToString() << "\n";
    cout << "B/A = " << (q2/q1).ToString() << "\n\n";

    cout << "A.Magnitude() = " << q1.Magnitude() << "\n";
    cout << "A.Normalized() = " << q1.Normalized().ToString() << "\n";
    cout << "A.Normalized().Magnitude() = " << q1.Normalized().Magnitude() << "\n\n";

    cout << "A.Inverse() = " << q1.Inverse().ToString() << "\n";
    cout << "A/A = " << (q1/q1).ToString() << "\n";
    cout << "A*A.Inverse() = " << (q1 * q1.Inverse()).ToString() << "\n";
    cout << "A.Inverse()*A = " << (q1.Inverse() * q1).ToString() << "\n\n";

    cout << "Vectors:" << "\n\n";

    Math::Vector v0(5, 2);
    Math::Vector v1(1, 2);
    float factor = 2;

    cout << v0.ToString() << " + " << v1.ToString() << " = " << (v0 + v1).ToString() << "\n";
    cout << v0.ToString() << " - " << v1.ToString() << " = " << (v0 - v1).ToString() << "\n";
    cout << v0.ToString() << " * " << factor << " = " << (v0 * factor).ToString() << "\n";
    cout << v0.ToString() << " / " << factor << " = " << (v0 / factor).ToString() << "\n\n";

    cout << v0.ToString() << " * " << v1.ToString() << " = " << (v0 * v1) << "\n";
    cout << v0.ToString() << ".Cross(" << v1.ToString() << ") = " << (v0.Cross(v1)).ToString() << "\n\n";

    cout << v0.ToString() << ".Magnitude() = " << v0.Magnitude() << "\n";
    cout << v1.ToString() << ".Magnitude() = " << v1.Magnitude() << "\n\n";

    cout << v0.ToString() << ".Normalized() = " << v0.Normalized().ToString() << "\n";
    cout << v1.ToString() << ".Normalized() = " << v1.Normalized().ToString() << "\n";
    cout << "Check: " << v0.ToString() << ".Normalized().Magnitude() = " << v0.Normalized().Magnitude() << "\n";
    cout << "Check: " << v1.ToString() << ".Normalized().Magnitude() = " << v1.Normalized().Magnitude() << "\n\n";*/

    return 0;
}