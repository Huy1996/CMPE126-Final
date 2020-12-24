#include <iostream>
#include "student.h"
#include <vector>


int main() {
    rosterclass cmpe;
    cmpe.read_from_file();

    cout << "Sort by name:\n\n";
    cmpe.quick_sort(0, cmpe.data_size-1);
    cmpe.print();

    cout << endl << endl;
    cout << "Sort by student id:\n\n";
    cmpe.insertion_sort();
    cmpe.print();

    cout << endl << endl;
    cout << "Sort by homework:\n\n";
    cmpe.heapSort();
    cmpe.print();
    return 0;
}
