//
// Created by Alexander Dimopoulos on 11/25/18.
//
#include "complexNumber.h"
#include <math.h>
#define _USE_MATH_DEFINES

complexNumber::complexNumber()
{
    realNumber = 0;
    imaginaryNumber = 0;
}

complexNumber::~complexNumber()
{
    eraseAll();
}

complexNumber::complexNumber(const mixedNumber &a, const mixedNumber &b)
{
    setValue(a, b);
}

void setValue(const complexNumber &a, const complexNumber &b)
{
    setValue(a, b);
}


complexNumber& complexNumber::operator=(const complexNumber &other)
{
    if(this != &other)
        copy(other);
    return *this;
}

mixedNumber complexNumber::getReal()
{
    return realNumber;
}

mixedNumber complexNumber::getImaginary()
{
    return imaginaryNumber;
}

complexNumber complexNumber::getConjugate() const
{
    //create a complexNumber object newbie
    //check if there is a denominator
    //if yes, get its value and make sure the answer has a numerator and denominator
    //else take the sign for the imaginary number and flip it (ex. - => +)
    //return newbie

    mixedNumber imNew;
    complexNumber newbie;

    imNew= this->imaginaryNumber * -1;
    newbie.setValue(this->realNumber, imNew);

    return newbie;
}

complexNumber complexNumber::pow(const complexNumber& base, const complexNumber& exponent)
{
    //(a^2 + b^2)^(c/2) * {cos[c arg(a + bi) + 1/2 d ln(a^2 + b^2)] + i sin[c arg(a + bi) + 1/2 d ln(a^2 + b^2)]}
    //first                 second1                                     second2
    complexNumber send;
    double a, b, c, d, finalReal, finalImag;
    a = static_cast<double>(base.realNumber.getNum()) / base.realNumber.getDenom();
    b = static_cast<double>(base.imaginaryNumber.getNum())/base.imaginaryNumber.getDenom();
    c = static_cast<double>(exponent.realNumber.getNum())/exponent.realNumber.getDenom();
    d = static_cast<double>(exponent.imaginaryNumber.getNum())/exponent.imaginaryNumber.getDenom();

    double common = std::pow(a,2) + std::pow(b,2);
    double first;
    double second1, second2;

    double argument = arg(a, b);

    //first
    first = std::pow(common,(c/2)) * std::exp(-1 * d * argument);

    //second1

    second1 = c * argument;
    double hold = std::log(common);
    double second1half = 0.5 * d * hold;
    second1 = cos(second1 + second1half);

    finalReal = first * second1;

    //(i) sin[c arg(a + bi) + 1/2 d ln(a^2 + b^2)]}
    //second2
    second2 = c * argument;
    second2 += 0.5 * d * hold;
    finalImag = sin(second2) * first;

    mixedNumber real, imag;
    real = finalReal;
    imag = finalImag;
    send.setValue(real, imag);

    return send;
}

mixedNumber complexNumber::getMagnitude() //find r
{
    //magnitute is found by taking the real number (p) and the imaginary number (q)
    //  squaring them, adding them together, then taking the square root
    //sqrt( p^2 + q^2)
//    mixedNumber p = getReal(), q = getImaginary();
//    p = p^2;
//    q = q^2;
//    p = p + q;
//    q = p * p;
    double realDouble = static_cast<double>(realNumber.getNum()) / realNumber.getDenom();
    double realDoubleSquared = realDouble * realDouble;
    double imaginaryDouble = static_cast<double>(imaginaryNumber.getNum()) / imaginaryNumber.getDenom();
    double imaginaryDoubleSquared = imaginaryDouble * imaginaryDouble;
    double magnitude = sqrt(realDoubleSquared + imaginaryDoubleSquared);
    mixedNumber result(magnitude);
    return result;
}

mixedNumber complexNumber::getDirection() //find (theta)
{
    double x = static_cast<double>(realNumber.getNum()) / realNumber.getDenom();
    double y = static_cast<double>(imaginaryNumber.getNum()) / imaginaryNumber.getDenom();
    mixedNumber result = arg(x, y);

    return result;
}

void complexNumber::getPolar()
{
    mixedNumber r = getMagnitude();
    mixedNumber theta = getDirection();
    std::cout<<"Polar Coordinates: ("<<r<<", "<<theta<<")"<<std::endl;
}

bool complexNumber::isOrthogonal(const complexNumber &other)
{
    fraction dotProduct = realNumber * other.realNumber + imaginaryNumber * other.imaginaryNumber;
    return dotProduct.getNum() == 0;
}

void complexNumber::setValue(const mixedNumber &a, const mixedNumber &b)
{
    realNumber = a;
    imaginaryNumber = b;
}

void complexNumber::eraseAll()
{
    realNumber = 0;
    imaginaryNumber = 0;
}

void complexNumber::copy(const complexNumber& other)
{
    this->imaginaryNumber = other.imaginaryNumber;
    this->realNumber = other.realNumber;
}

complexNumber& complexNumber::operator+=(const complexNumber& other)
{
    *this = *this + other;
    return *this;
}

complexNumber& complexNumber::operator-=(const complexNumber& other)
{
    *this = *this - other;
    return *this;
}

complexNumber& complexNumber::operator*=(const complexNumber& other)
{
    *this = *this * other;
    return *this;
}

complexNumber& complexNumber::operator/=(const complexNumber& other)
{
    *this = *this / other;
    return *this;
}

double complexNumber::arg(double &x, double &y) {
    if(x == 0 && y == 0) {
        throw(UNDEFINED_DIRECTION);
    }
    return atan2(y, x);
}
