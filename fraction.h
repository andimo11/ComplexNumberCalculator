#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <iomanip>

class fraction
{
public:
    enum ERRORS {DIVIDE_BY_ZERO};
    /*
           * The default constructor makes an "empty"
           * object, and is required ALL the time!
           */
    fraction();
    /*
           * Two item constructor that will pass a numerator
           * and a denominator to the new fraction
           */
    fraction(int n, int d = 1);
    /*
           * How do you destroy a fraction?
           * By the destructor!
           */
    ~fraction();
    /*
           * The copy constructor is fired whenever
           * 1. You pass by value
           * 2. You use a return statement that
           *    does not got back to a reference
           */
    fraction(const fraction &fraction);
    /*
           * The assignment operator needs to be
           * returned by reference so that you can
           * "chain" operators.
           * e.g.
           * x = y = z;
           */
    //Other constructors to "help" make my life easier.
    fraction(const double &other);

    fraction& operator=(const fraction &fraction);
    //Additional assignment operators
    fraction& operator+=(const fraction &fraction);
    fraction& operator-=(const fraction &fraction);
    fraction& operator*=(const fraction &fraction);
    fraction& operator/=(const fraction &fraction);

    int getNum() const; //accessor function for numerator
    int getDenom() const; //accessor function for denominator
    void setValue(int n, int d = 1); //mutator function
    void setValue(const double &other);
    void display();
    void getInput();

    /*
           * Friends of a class.
           * Friends are used when you are interacting
           * between two or more other objects; whether
           * it be of the class type or something else.
           *
           * Friends are NOT members of the class, but have
           * access to private member data and functions.
           */
    friend
    std::ostream& operator<<(std::ostream& out, const fraction &frac);

    friend
    std::istream& operator>>(std::istream& out, fraction &frac);

    friend
    fraction operator+(const fraction &x,const fraction &y);

    friend
    fraction operator-(const fraction &x,const fraction &y);

    friend
    fraction operator*(const fraction &x,const fraction &y);

    friend
    fraction operator^(const fraction &x,const fraction &y);

    friend
    fraction operator/(const fraction &x,const fraction &y);

    friend
    bool operator==(const fraction &x,const fraction &y);

    friend
    bool operator>=(const fraction &x,const fraction &y);

    friend
    bool operator<=(const fraction &x,const fraction &y);

    friend
    bool operator!=(const fraction &x,const fraction &y);

    friend
    bool operator<(const fraction &x,const fraction &y);

    friend
    bool operator>(const fraction &x,const fraction &y);

protected:
    int num, denom;

private:
    void reduce();
    int gcd(int p, int q);

    bool allDecimalsTheSame(const std::string &fracPart);
    int makeDenom(int digits, bool same);
};

#endif // FRACTION_H
