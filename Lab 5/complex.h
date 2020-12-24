//**********************************************
//Name: Nguyen Minh Huy Duong                 **
//Student ID: 014701349                       **
//Professor: Frank C. Lin                     **
//Lab 1: Complex Number                       **
//**********************************************

#ifndef LAB_COMPLEX_H
#define LAB_COMPLEX_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <sstream>

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

class complexDB : public complex{
    complex *complex_array;
private:
    int size;
public:
    complexDB();
    complex data_at(unsigned n);
    void pushback(complex input);
    void readinfo();
    int input_command();
    int get_size()const;
    void swap(unsigned pos1, unsigned pos2);
    void to_file();
    void recursive_sort(int n);
    complex find_max_recursively(unsigned n, complex max);


};


#endif //LAB_COMPLEX_H
