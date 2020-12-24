//
// Created by minhh on 12/1/2020.
//

#include "student.h"


student::student()
{
    first = "";
    last = "";
    student_id = hw = quiz = midterm = final = average = 0;

}

student::student(string firstname, string lastname, unsigned id)
{
    first = firstname;
    last = lastname;
    student_id = id;
    hw = quiz = midterm = final = average = 0;
}

student::~student() = default;

void student::input_score(unsigned quiz_score, unsigned hw_score, unsigned midterm_score, unsigned final_score)
{
    hw = hw_score;
    quiz = quiz_score;
    midterm = midterm_score;
    final = final_score;
    calculate_average();
}

void student::calculate_average()
{
    average = hw*0.1 + quiz*0.2 + midterm*0.3 + final*0.4;
}

string student::get_first()
{
    return first;
}

string student::get_last()
{
    return last;
}

unsigned student::get_id()
{
    return student_id;
}

unsigned student::get_hw()
{
    return hw;
}

unsigned student::get_quiz()
{
    return quiz;
}

unsigned student::get_mid()
{
    return midterm;
}

unsigned student::get_final()
{
    return final;
}

unsigned student::get_ave()
{
    return average;
}

void student::input_hw(unsigned score)
{
    hw = score;
    calculate_average();
}

void student::input_quiz(unsigned score)
{
    quiz = score;
    calculate_average();
}

void student::input_midterm(unsigned score)
{
    midterm = score;
    calculate_average();
}

void student::input_final(unsigned score)
{
    final = score;
    calculate_average();
}

ostream &operator << (ostream &stream, const student &RHS)
{
    stream << left
           << setw(16) <<RHS.first
           << setw(10)<< RHS.last
           << setw(8)<< RHS.student_id
           << setw(6)<< RHS.hw
           << setw(8)<< RHS.quiz
           << setw(7)<< RHS.midterm
           << setw(9)<< RHS.final
           << RHS.average << endl;
    return stream;
}

//=======================================================================//
rosterclass::rosterclass()
{
    data_size = 0;
}

rosterclass::~rosterclass()
{
    data_size = 0;
}

void rosterclass::read_from_file()
{
    string temp;
    ifstream ifs;
    ifs.open("student.txt");
    if(ifs.fail())
        cout << "Fuck";
    for(int i = 0; i < 5; i++)
        getline(ifs, temp);
    string first, last;
    unsigned id, hw, quiz, mid, final, average;
    while(ifs >> first)
    {
        ifs >> last;
        ifs >> id;
        ifs >> hw;
        ifs >> quiz;
        ifs >> mid;
        ifs >> final;
        ifs >> average;
        student data(first, last, id);
        data.input_score(quiz, hw, mid, final);
        list.push_back(data);
        data_size++;
    }
    ifs.close();
}

void rosterclass::insertion_sort()
{
    int i, j;
    student key;
    for (i = 1; i < list.size(); i++)
    {
        key = list[i];
        j = i - 1;

        while (j >= 0 && list[j].get_id() > key.get_id())
        {
            list[j + 1] = list[j];
            j = j - 1;
        }
        list[j + 1] = key;
    }
}

void rosterclass::quick_sort(int first, int last)
{
    if (first < last)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(first, last);

        // Separately sort elements before
        // partition and after partition
        quick_sort(first, pi - 1);
        quick_sort(pi + 1, last);
    }
}
int rosterclass::partition(int first, int last) {
    string pivot = list[last].get_first(); // pivot
    int i = (first - 1); // Index of smaller element

    for (int j = first; j <= last - 1; j++) {
        // If current element is smaller than the pivot
        if (toupper(list[j].get_first().at(0)) < toupper(pivot.at(0))) {
            i++; // increment index of smaller element
            swap(list[i], list[j]);
        }
    }
    swap(list[i + 1], list[last]);
    return (i + 1);
}
void rosterclass::print()
{
    string to_print = "First           Last      ID      HW    Quiz    Mid    Final    Average";
    cout << to_print << endl;
    for(int i = 0; i < list.size(); i++)
        cout << list[i];
}

void rosterclass::heapify(int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && list[l].get_hw() > list[largest].get_hw())
        largest = l;
    if (r < n && list[r].get_hw() > list[largest].get_hw())
        largest = r;
    if (largest != i) {
        swap(list[i], list[largest]);
        heapify(n, largest);
    }
}

void rosterclass::heapSort()
{
    int n = list.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(list[0], list[i]);
        heapify(i, 0);
    }
}