//**********************************************
//Name: Nguyen Minh Huy Duong                 **
//Student ID: 014701349                       **
//Professor: Frank C. Lin                     **
//Lab 1: Complex Number                       **
//**********************************************

#include "complex.h"
using namespace std;

complex::complex(){}

complex::complex(int real, int image)
{
    real_part = real;
    image_part = image;
}

int complex::get_real_part()
{
    return real_part;
}

int complex::get_image_part()
{
    return image_part;
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

void complex::operator=(complex c)
{
    real_part = c.get_real_part();
    image_part = c.get_image_part();
}