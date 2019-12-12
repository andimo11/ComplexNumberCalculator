#include "fraction.h"

std::ostream& operator<<(std::ostream& out, const fraction &frac)
{
    out<<frac.num;
    if(frac.denom != 1)
        out<<"/"<<frac.denom;
    return out;
}

std::istream& operator>>(std::istream& in, fraction &frac)
{
    char junk;
    std::stringstream ss;
    std::string possibleFraction;
    if(&in == &std::cin)
    {
        if(in>>possibleFraction)
        {
            ss<<possibleFraction;
            ss>>frac;
        }
    }
    else
    {
        int possibleDenom;
        bool isNegative = false;
        if(in.peek() == '-') {
            isNegative = true;
            in.ignore(1);
        }
        if(in>>frac.num)
        {
            if(in.peek() == '/' && in >> junk && in >> possibleDenom) {
                if(possibleDenom == 0) {
                    throw(fraction::DIVIDE_BY_ZERO);
                }
                frac.denom = possibleDenom;
            } else {
                frac.denom = 1;
            }
            frac.reduce();
            if(isNegative) {
                frac.num *= -1;
            }
            in.clear();
        } else {
        }
    }
    return in;
}

fraction operator+(const fraction &x,const fraction &y)
{
    fraction result;
    int num = x.num * y.denom + y.num  * x.denom,
            denom = x.denom * y.denom;
    result.setValue(num,denom);
    return result;
}

fraction operator-(const fraction &x,const fraction &y)
{
    fraction result;
    int num = x.num * y.denom - y.num  * x.denom,
            denom = x.denom * y.denom;
    result.setValue(num,denom);
    return result;
}

fraction operator*(const fraction &x,const fraction &y)
{
    fraction result;
    int num = x.num * y.num,
            denom = x.denom * y.denom;
    result.setValue(num,denom);
    return result;
}

fraction operator/(const fraction &x,const fraction &y)
{
    if(y.num == 0) {
        throw(fraction::DIVIDE_BY_ZERO);
    }
    fraction result;
    int num = x.num * y.denom,
            denom = x.denom * y.num;
    result.setValue(num,denom);
    return result;
}


fraction operator^(const fraction &x,const fraction &y)
{
    double temp1 = pow(pow(x.num, y.num),1./y.denom),
            temp2 = pow(pow(x.denom, y.num),1./y.denom);
    return temp1/temp2;
}


bool operator==(const fraction &x,const fraction &y)
{
    return x.num * y.denom == y.num * x.denom;
}

bool operator>=(const fraction &x,const fraction &y)
{
    return x.num * y.denom >= y.num * x.denom;
}

bool operator<=(const fraction &x,const fraction &y)
{
    return x.num * y.denom <= y.num * x.denom;
}

bool operator!=(const fraction &x,const fraction &y)
{
    return x.num * y.denom != y.num * x.denom;
}

bool operator<(const fraction &x,const fraction &y)
{
    return x.num * y.denom < y.num * x.denom;
}

bool operator>(const fraction &x,const fraction &y)
{
    return x.num * y.denom > y.num * x.denom;
}



