#include <iostream>
#include "calculator.h"

int main() {
    while(true)
    {
        calculator test;
        test.getInfix();
        test.showInfix();
        test.showPostfix();

        cout << "Result: " << test.calculate();

        cout << "\n\nEnter 1 to exit.";
        int exit;
        cin>>exit;
        cin.ignore();
        cout <<"\n";
        if(exit == 1)
            break;
    }

    return 0;
}