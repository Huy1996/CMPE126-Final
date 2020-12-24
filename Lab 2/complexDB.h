//
// Created by minhh on 9/2/2020.
//

#ifndef CMPE126_LAB_COMPLEXDB_H
#define CMPE126_LAB_COMPLEXDB_H

#include "complex.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <sstream>

using namespace std;


class complexDB : public complex{
    complex *complex_array;
private:
    int size;
public:
    complexDB();
    void pushback(complex input);
    void readinfo();
    int input_command();
    int get_size()const;
    void sort();
    void swap(unsigned pos1, unsigned pos2);
    void to_file();
    void recursive_sort(int n);
    void to_file_extra_credit();

};


#endif //CMPE126_LAB_COMPLEXDB_H
