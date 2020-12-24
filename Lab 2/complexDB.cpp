//
// Created by minhh on 9/2/2020.
//

#include "complexDB.h"

complexDB::complexDB()
{
    complex_array = new complex[50];
    size = 0;
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

void complexDB::sort()
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = i + 1; j < size; j++){
            if(complex_array[i] > complex_array[j])
                swap(i, j);
        }
    }
}

void complexDB::to_file()
{
    ofstream output_file;
    output_file.open("126complex.txt");
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
        sum = sum + complex_array[i];
    }
    output_file << "Total is: " << sum << endl;
    output_file.close();
}

void complexDB::to_file_extra_credit()
{
    fstream output_file;
    output_file.open("126complex.txt", fstream::out | fstream::app);
    if(output_file.fail())
    {
        cout << "Fail to re-open the file." << endl;
        exit(1);
    }
    else
        cout<< "Output file re-opened successful" << endl;
    complex sum(0,0);
    cout << "\nRecursive sort." << endl;
    output_file << "Recursive sort (Extra credit):" << endl;
    for(int i = 0; i < size; i++)
    {
        output_file << complex_array[i];
        cout << complex_array[i];
        sum = sum + complex_array[i];
    }
    cout<< "Total is: " << sum << endl;
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