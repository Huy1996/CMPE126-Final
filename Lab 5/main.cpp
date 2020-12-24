#include "complex.h"
#include "node.h"

using namespace std;
void tower_of_hanoi(int n, char A, char C, char B);
int main() {
    std::ofstream ofs;
    ofs.open("126complex.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    complexDB c;
    c.readinfo();
    cout << "Original complex number list: \n";
    c.to_file();
    c.recursive_sort(c.get_size());
    cout << "\nList after recursive sort: \n";
    c.to_file();
    complex max = c.data_at(0);
    max = c.find_max_recursively(1, max);
    cout<< "\nMax complex number is: " << max << endl;

    cout << "\n\n____________________________________\nStock class. \n";
    stock a;
    a.create_stock();
    cout << "\nPrint list forward.";
    cout << "\nSymbol" << setw(11) << "Share" << setw(10) << "Price" << endl;
    node *temp = a.travel_to(0);
    a.print_list_forward_recursively(temp);
    cout << "\nPrint list backward.";
    cout << "\nSymbol" << setw(11) << "Share" << setw(10) << "Price" << endl;
    a.print_list_backward_recursively(temp);

    cout << "\n\n____________________________________\nTest tower of Hanoi.\n";
    cout << "Enter number of disk: ";
    int n;
    cin >> n;
    tower_of_hanoi(n, 'A', 'C', 'B');


    return 0;
}

void tower_of_hanoi(int n, char A, char C, char B)
{
    if (n == 1)
    {
        cout << "Move disk 1 from rod " << A << " to rod " << C<<endl;
        return;
    }
    tower_of_hanoi(n - 1, A, B, C);
    cout << "Move disk " << n << " from rod " << A << " to rod " << C << endl;
    tower_of_hanoi(n - 1, B, C, A);
}