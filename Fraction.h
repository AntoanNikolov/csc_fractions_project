#include <string>


// not sure why these lines are necessary, I found them on Google but they (along with a line at the bottom) fix an error
#ifndef MY_STRUCT_H 
#define MY_STRUCT_H

struct Fraction
{
    int numerator, denominator;

    Fraction();
    Fraction(int n);
    Fraction(int n,int d);
    Fraction(std::string a);
    std::string to_string();
    bool operator==(const Fraction& f2) const;
    bool operator>(const Fraction& f2) const;
    bool operator<(const Fraction& f2) const;
    bool operator>=(const Fraction& f2) const;
    bool operator<=(const Fraction& f2) const;
    bool operator!=(const Fraction& f2) const;
    Fraction operator+(const Fraction& f2);
    Fraction operator-(const Fraction& f2);
    Fraction operator*(const Fraction& f2);
    Fraction operator/(const Fraction& f2);

};
int gcd(int a, int b); 

#endif