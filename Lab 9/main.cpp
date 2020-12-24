
#include "search.h"
#include "hashing.h"

int main() {
    cout << "What do you want to do?" << endl;
    cout << "(1) Integer (Lab 8: Array, Linked list)" << endl;
    cout << "(2) Stock (Lab 9: Hashing linear, quadratic, chaining." << endl;
    cout << "Your choice: ";
    int choice;
    cin >> choice;
    cin.ignore();
    if(choice == 1)
    {
        search test = search();
        test.create_list();
    }
    else if(choice == 2)
    {
        hashing test;
        test.create_stock();
    }
    else
        cout << "\nInvalid.\n";
    return 0;




}