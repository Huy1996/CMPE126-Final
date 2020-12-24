//**********************************************
//Name: Nguyen Minh Huy Duong                 **
//Student ID: 014701349                       **
//Professor: Frank C. Lin                     **
//Lab 1: Complex Number                       **
//**********************************************

#ifndef LAB_COMPLEX_H
#define LAB_COMPLEX_H

#include <iostream>

using namespace std;
class complex
{
private:
    double real_part;
    double image_part;

public:
    complex();
    explicit complex(double real, double image);
    double get_real_part()const;
    double get_image_part()const;
    double get_value()const;
    friend complex operator + (const complex &c_1, const complex &c_2);
    friend ostream& operator << (ostream &stream, const complex &c);
    complex &operator = (const complex &rhs);
    friend bool operator < (const complex &c_1, const complex &c_2);
    friend bool operator > (const complex &c_1, const complex &c_2);
    friend bool operator == (const complex &c_1, const complex &c_2);
};


#endif //LAB_COMPLEX_H
