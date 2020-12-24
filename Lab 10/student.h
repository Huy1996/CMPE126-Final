//
// Created by minhh on 12/1/2020.
//

#ifndef LAB_10_STUDENT_H
#define LAB_10_STUDENT_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;
class student{
private:
    unsigned hw, quiz, midterm, final, average;
    unsigned student_id;
    string first, last;
public:
    student();
    student(string firstname, string lastname, unsigned id);
    virtual ~student();
    string get_first();
    string get_last();
    unsigned get_id();
    unsigned get_hw();
    unsigned get_quiz();
    unsigned get_mid();
    unsigned get_final();
    unsigned get_ave();
    void input_score(unsigned quiz_score, unsigned hw_score, unsigned midterm_score, unsigned final_score);
    void calculate_average();
    void input_hw(unsigned score);
    void input_quiz(unsigned score);
    void input_midterm(unsigned score);
    void input_final(unsigned score);
    friend ostream& operator << (ostream &stream, const student &a);
};

class rosterclass
{
private:
    vector<student> list;

public:
    int data_size;
    rosterclass();
    ~rosterclass();
    void read_from_file();
    void insertion_sort();
    void print();
    void quick_sort(int first, int last);
    int partition(int first, int last);
    void heapify(int n, int i);
    void heapSort();
};

#endif //LAB_10_STUDENT_H
