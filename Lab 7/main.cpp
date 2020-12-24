#include <iostream>
#include "palindrome.h"
#include <string>
#include <iomanip>
#include <fstream>
#include <cctype>

int main() {
    ifstream op;
    op.open("palindrome.txt");
    string temp;
    while(!op.eof())
    {
        stack a;
        queue b;
        getline(op, temp);
        for(int i = 0; i < temp.length(); i++)
        {
            if(isalpha(temp.at(i)))
            {
                a.push(tolower(temp.at(i)));
                b.enqueue(tolower(temp.at(i)));
            }
        }
        cout << temp << endl;
        bool flag = true;
        for(int i = 0; i < a.size(); i++)
        {
            if(a.top() != b.top())
                flag = false;
            a.pop();
            b.dequeue();
        }
        if(flag)
            cout << "Palindrome.\n\n";
        else
            cout << "Not a Palindrome.\n\n";
    }
    return 0;
}