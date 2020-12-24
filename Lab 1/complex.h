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
    int real_part;
    int image_part;

public:
    complex();
    explicit complex(int real, int image);
    int get_real_part();
    int get_image_part();
    friend complex operator + (const complex &c_1, const complex &c_2);
    friend ostream& operator << (ostream &stream, const complex &c);
    void operator = (complex c);
};


#endif //LAB_COMPLEX_H
