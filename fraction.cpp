#include "fraction.h"

fraction::fraction()
{
    num = 0;
    denom = 1;
}

fraction::fraction(int n, int d)
{
    setValue(n,d);
}

fraction::~fraction()
{
    num = denom = 0;
}

fraction::fraction(const fraction &frac)
{
    num = frac.num;
    denom = frac.denom;
}

fraction::fraction(const double &other)
{
    setValue(other);
}

bool fraction::allDecimalsTheSame(const std::string &fracPart)
{
    if(fracPart[0] == '0') {
        return false;
    }
    for(unsigned int i = 1; i < fracPart.size(); ++i) {
        if(fracPart[0] != fracPart[i]) {
            return false;
        }
    }
    return true;
}

int fraction::makeDenom(int digits, bool same)
{
    std::string result("1");
    for(int i = 0; i < digits; ++i)
        result += "0";
    return std::stoi(result) - static_cast<int>(same);
}

fraction& fraction::operator=(const fraction &frac)
{
    if(this != &frac)
    {
        num = frac.num;
        denom = frac.denom;
    }
    return *this;
}

fraction& fraction::operator+=(const fraction &other)
{
    *this = *this + other;
    return *this;
}

fraction& fraction::operator-=(const fraction &other)
{
    *this = *this - other;
    return *this;
}

fraction& fraction::operator*=(const fraction &other)
{
    *this = *this * other;
    return *this;
}

fraction& fraction::operator/=(const fraction &other)
{
    *this = *this / other;
    return *this;
}


int fraction::getNum() const
{
    return num;
}

int fraction::getDenom() const
{
    return denom;
}

void fraction::setValue(int n, int d)
{
    num = n;
    denom = d;
    reduce();
}

void fraction::setValue(const double &other) {
    std::string wholePart, fractionPart;
    std::stringstream ss;

    ss<<std::fixed<<std::setprecision(5)<<other;
    getline(ss,wholePart,'.');
    getline(ss,fractionPart);
    int numDigits = static_cast<int>(fractionPart.size());
    denom = makeDenom(numDigits, allDecimalsTheSame(fractionPart));
    int fractionPartInt = std::stoi(fractionPart);
    if(wholePart[0] == '-') {
        fractionPartInt *= -1;
    }
    num = denom * std::stoi(wholePart) + fractionPartInt;
    reduce();
}

void fraction::display()
{
    std::cout<<" "<<num;
    if(denom != 1)
        std::cout<<"/"<<denom<<" ";
}


void fraction::getInput()
{
    char junk;
    std::cin>>num>>junk>>denom;
    reduce();
}


void fraction::reduce()
{
    bool neg = num < 0 || denom < 0,
            both = num < 0 && denom < 0;
    int divisor = gcd(abs(num), abs(denom));
    num = abs(num) / divisor;
    denom = abs(denom) / divisor;
    if(!both) //Asking is both == false
        if(neg)
            num *= -1;
}

int fraction::gcd(int p, int q)
{
    return !q ? p : gcd(q, p%q);
}
