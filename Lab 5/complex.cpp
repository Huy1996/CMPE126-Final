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

complexDB::complexDB()
{
    complex_array = new complex[50];
    size = 0;
}

complex complexDB::data_at(unsigned n)
{
    if(n<size)
        return complex_array[n];
    else
        std::cout<< "Position out of range.\n";
}

void complexDB::pushback(complex input)
{
    complex_array[size] = input;
    size++;
}

void complexDB::readinfo()
{
    int i = input_command();
    ifstream input_file;

    if(i == 1)
        input_file.open("126import.txt");
    else if(i == 2)
        input_file.open("126importHard.txt");
    else
        input_file.open("complex.txt");

    if(input_file.fail())
    {
        cout << "Fail to open the file." << endl;
        exit(1);
    }
    else
        cout<< "Input file opened successful" << endl;

    double real, image;
    string temp, string_real, string_image;
    complex sum(0, 0);

    while(!input_file.eof())
    {
        getline(input_file, temp);
        bool flag = false;
        for (int i = 0; i < temp.length(); i++)
        {
            if (isalpha(temp.at(i)) && temp.at(i) != 'i')
                flag = true;
        }
        if (flag)
            continue;
        if(temp.length() == 0)
            continue;
        int plus_index = temp.find("+");
        int minus_index = temp.find("-", 1);
        int i_index = temp.find("i");
        if(i_index == -1)
        {
            string_real = temp.substr(0, temp.length() -  1);
            string_image = "0";
        }
        else if(i_index == 0)
        {
            string_real = "0";
            string_image = "1";
        }
        else if(temp.find("-i") == 0)
        {
            string_real = "0";
            string_image = "-1";
        }
        else if(plus_index == -1 && minus_index == -1)
        {
            string_real = "0";
            string_image = temp.substr(0, i_index);
        }
        else if(plus_index == -1)
        {
            string_real = temp.substr(0, minus_index);
            string_image = temp.substr(minus_index, i_index - minus_index);
        }
        else
        {
            string_real = temp.substr(0, plus_index);
            string_image = temp.substr(plus_index + 1, i_index - plus_index -1);
        }
        real = stod(string_real);
        image = stod(string_image);
        complex com(real, image);
        this -> pushback(com);
    }
    input_file.close();
}

int complexDB::input_command()
{
    int to_return;
    cout << "Please choose the file you want to import (1 or 2 or 3)." << endl;
    cout << "(1): 126import.txt" << endl;
    cout << "(2): 126inportHard.txt" << endl;
    cout << "(3): complex.txt" << endl;
    cin >> to_return;
    while(to_return != 1 && to_return != 2 && to_return != 3)
    {
        cout << "Invalid input. Please try again." << endl;
        cin >> to_return;
    }
    return to_return;
}

int complexDB::get_size() const
{
    return size;
}

void complexDB::swap(unsigned pos1, unsigned pos2)
{
    complex temp;
    temp = complex_array[pos1];
    complex_array[pos1] = complex_array[pos2];
    complex_array[pos2] = temp;
}

void complexDB::to_file()
{
    fstream output_file;
    output_file.open("126complex.txt", fstream::out | fstream::app);
    if(output_file.fail())
    {
        cout << "Fail to open the file." << endl;
        exit(1);
    }
    else
        cout<< "Output file opened successful" << endl;
    complex sum(0,0);
    for(int i = 0; i < size; i++)
    {
        output_file << complex_array[i];
        cout << complex_array[i];
        sum = sum + complex_array[i];
    }
    output_file << "Total is: " << sum << endl;

    output_file.close();
}


void complexDB::recursive_sort(int n)
{
    if (n == 1)
        return;
    for (int i=0; i<n-1; i++)
        if (complex_array[i] > complex_array[i+1])
            swap(i, i+1);
    recursive_sort(n-1);
}

complex complexDB::find_max_recursively(unsigned pos, complex max)
{
    if(pos < size)
    {
        if(max < data_at(pos))
            max = data_at(pos);
        max = find_max_recursively(pos+1,max);
    }
    return max;

}