//**********************************************
//Name: Nguyen Minh Huy Duong                 **
//Student ID: 014701349                       **
//Professor: Frank C. Lin                     **
//Lab 1: Complex Number                       **
//**********************************************

#include "complex.h"
#include "math.h"
using namespace std;

complex::complex(){}

complex::complex(double real, double image)
{
    real_part = real;
    image_part = image;
}

double complex::get_real_part()const
{
    return real_part;
}

double complex::get_image_part()const
{
    return image_part;
}

double complex::get_value()const
{
    double to_return = sqrt(pow(real_part,2) + pow(image_part, 2));
    return to_return;
}

complex operator + (const complex &c_1, const complex &c_2)
{
    complex to_return;
    to_return.real_part = c_1.real_part + c_2.real_part;
    to_return.image_part = c_1.image_part + c_2.image_part;
    return to_return;
}

ostream &operator << (ostream &stream, const complex &c)
{
    if(c.image_part < 0)
        stream << c.real_part << c.image_part << 'i' << endl;
    else
        stream << c.real_part << '+' << c.image_part << 'i' << endl;
    return stream;
}

complex &complex::operator=(const complex &rhs)
{
    if(this == &rhs)
        return *this;
    real_part = rhs.get_real_part();
    image_part = rhs.get_image_part();
    return *this;
}

bool operator < (const complex &c_1, const complex &c_2)
{
    return c_1.get_value() < c_2.get_value();
}

bool operator > (const complex &c_1, const complex &c_2)
{
    return c_1.get_value() > c_2.get_value();
}

bool operator == (const complex &c_1, const complex &c_2)
{
    return c_1.get_value() == c_2.get_value();
}