//**********************************************
//Name: Nguyen Minh Huy Duong                 **
//Student ID: 014701349                       **
//Professor: Frank C. Lin                     **
//Lab 1: Complex Number                       **
//**********************************************

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <sstream>
#include "complex.h"

using namespace std;

int main()
{
    ifstream input_file;
    ofstream output_file;
    input_file.open("complex.txt");
    output_file.open("complexObj.txt");
    if(input_file.fail() || output_file.fail())
        cout << "File fail to open" << endl;
    else
        cout << "File opened successful" << endl;

    int real, image;
    string temp, string_real, string_image;
    complex sum(0, 0);
    while(!input_file.eof())
    {
        getline(input_file, temp);
        bool flag = false;
        for(int i = 0; i < temp.length(); i++)
        {
            if(isalpha(temp.at(i)) && temp.at(i) != 'i')
                flag = true;
        }
        if(flag)
            continue;
        int position_1 = temp.find("+");
        int position_2 = temp.find("i");
        if (position_2 == -1)
            continue;
        if(position_1 == -1) // the image part is negative
        {
            position_1 = temp.find("-",1);
            if(position_1 == -1)
                continue;
            else
            {
                string_real=temp.substr(0,position_1);
                string_image=temp.substr(position_1+1,position_2 - position_1);
            }
        }
        else
        {
            string_real=temp.substr(0,position_1);
            string_image=temp.substr(position_1+1,position_2 - position_1-1);
        }
        real = stoi(string_real);
        image = stoi(string_image);
        complex com(real, image);
        output_file << com;
        sum = sum + com;
    }
    output_file << "Total is: " << sum;
    input_file.close();
    output_file.close();
}