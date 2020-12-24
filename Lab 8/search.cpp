//
// Created by minhh on 11/18/2020.
//

#include "search.h"

bool isNumber (const string &s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int getNumber()
{
    string input;
    int to_return;
    do
    {
        getline(cin, input);
        if(isNumber(input))
        {
            to_return = stoi(input);
            break;
        }
        cout << "\nInvalid input. Please enter a number.\n";
        cout << "Please re-enter the number: ";
    }
    while(true);
    return to_return;
}

void insertionSort(int array[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

//================================================================//
//                         node class                             //
//================================================================//

node::node(int input)
{
    next = nullptr;
    data = input;
}

node::~node() = default;

//================================================================//
//                     linked list class                          //
//================================================================//
linked_list::linked_list()
{
    head = nullptr;
    tail = nullptr;
}

linked_list::~linked_list()
{
    node *current_node = head;
    node *delete_node;
    while(current_node)
    {
        delete_node = current_node;
        current_node = current_node -> next;
        delete delete_node;
    }
    head = nullptr;
    tail = nullptr;
}

void linked_list::append(int value)
{
    node *input = new node(value);
    if(head == nullptr)
    {
        head = input;
        tail = input;
    }
    else
    {
        tail->next = input;
        tail = tail->next;
    }
}

int linked_list::size()
{
    int i = 0;
    node *current = head;
    while(current)
    {
        i++;
        current = current->next;
    }
    return i;
}

int linked_list::get_value(int position)
{
    node *current = head;
    for(int i = 0; i <= position; i++)
    {
        if(current == nullptr)
            throw exception();
    }
    return current->data;
}

int linked_list::search(int value)
{
    int index = 0;
    node *current = head;
    while(current)
    {
        if(current->data == value)
            return index;
        index++;
        current = current->next;
    }
    return -1;
}

int linked_list::recursive_search(int val)
{
    return search_recursively(head, 0, val);
}

int linked_list::search_recursively(node *current, int position, int val)
{
    if(current == nullptr)
        return -1;
    if(current->data == val)
        return position;
    else
        return search_recursively(current->next, position + 1, val);
}

void linked_list::printout()
{
    string printout;
    node *current = head;
    while(current)
    {
        printout += to_string(current->data) + " -> ";
        current = current->next;
    }
    printout += "End.";
    cout << printout;
}
//================================================================//
//                         search class                           //
//================================================================//

search::search()
{
    size = 0;
}

search::~search()
{
    delete array;
    delete list;
}

void search::create_list()
{
    cout << "Enter the number of element: ";
    size = getNumber();
    array = new int[size];
    sorted_array = new int[size];
    int input;
    for(int i = 0; i < size; i++)
    {
        cout << "Enter element number " << i + 1 << " : ";
        input = getNumber();
        array[i] = input;
        sorted_array[i] = input;
        list->append(input);
    }
    insertionSort(sorted_array, size);
    command();
}

void search::command()
{
    int choice;
    do
    {
        cout << "\nChoose your search type: ";
        cout<<"\n1. Arrays: Sequential Search without recursion";
        cout<<"\n2. Arrays: Sequential Search with recursion";
        cout<<"\n3. Ordered Arrays: Binary Search without recursion";
        cout<<"\n4. Ordered Arrays: Binary Search with recursion";
        cout<<"\n5. Linked List: Search without recursion";
        cout<<"\n6. Linked List: Search with recursion";
        cout<<"\nEnter 0 to exit.\nYour choice: ";
        choice = getNumber();
        int val;
        switch(choice)
        {
            case 0:
                cout << "\nExit successful.";
                return;
            case 1:
                cout << "\nSpecify the number of elements to be searched: " << size;
                cout << "\n\nElements added to the array: ";
                print_array();
                cout << "\n\nSpecify the element to be searched for: ";
                val = getNumber();
                array_search(val, choice);
                break;
            case 2:
                cout << "\nSpecify the number of elements to be searched: " << size;
                cout << "\n\nElements added to the array: ";
                print_array();
                cout << "\n\nSpecify the element to be searched for: ";
                val = getNumber();
                array_search(val, choice);
                break;
            case 3:
                cout << "\nSpecify the number of elements to be searched: " << size;
                cout << "\n\nElements in the sorted array: ";
                print_S_array();
                cout << "\n\nSpecify the element to be searched for: ";
                val = getNumber();
                binary_search(val, choice);
                break;
            case 4:
                cout << "\nSpecify the number of elements to be searched: " << size;
                cout << "\n\nElements in the sorted array: ";
                print_S_array();
                cout << "\n\nSpecify the element to be searched for: ";
                val = getNumber();
                binary_search(val, choice);
                break;
            case 5:
                cout << "\nSpecify the number of elements to be searched: " << size;
                cout << "\n\nElements in the Linked list: ";
                list->printout();
                cout << "\n\nSpecify the element to be searched for: ";
                val = getNumber();
                linked_list_search(val, choice);
                break;
            case 6:
                cout << "\nSpecify the number of elements to be searched: " << size;
                cout << "\n\nElements in the Linked list: ";
                list->printout();
                cout << "\n\nSpecify the element to be searched for: ";
                val = getNumber();
                linked_list_search(val, choice);
                break;
            default:
                cout << "\nInvalid input. Please try again.";
        }
        cout << "\nPress [Enter] to continue . . .";
        getchar();
    }
    while(true);
}

void search::array_search(int val, int command)
{
    int index;
    switch (command)
    {
        case 1:
            index = array_search(val);
            break;
        case 2:
            index = array_search_recursive(val, 0, size - 1);
            break;
        default:
            cout << "\nInvalid command.";
    }
    if(index == -1)
        cout << "\nNumber " << val << " is not in the array.\n";
    else
        cout << "\nElement index: " << index << endl;
}

int search::array_search(int val)
{
    for(int i = 0; i < size; i++)
    {
        if (array[i] == val)
            return i;
    }
    return -1;
}

int search::array_search_recursive(int val, int left, int right)
{
    if(array[left] == val)
        return left;
    else if(array[right] == val)
        return right;
    else if(left >= right)
        return -1;
    else
        return array_search_recursive(val, left + 1, right - 1);
}

void search::binary_search(int val, int command)
{
    int index;
    switch(command)
    {
        case 3:
            index = binary_search(val);
            break;
        case 4:
            index = binary_search(val, 0, size - 1);
            break;
        default:
            cout << "\nInvalid command.";
    }
    if(index == -1)
        cout << "\nNumber " << val << " is not in the array.\n";
    else
        cout << "\nElement index: " << index << endl;
}

int search::binary_search(int val)
{
    int low = 0;
    int high = size - 1;
    int mid;
    while(low <= high)
    {
        mid = (high + low)/2;
        if(sorted_array[mid] == val)
            return mid;
        else if(sorted_array[mid] > val)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int search::binary_search(int val, int low, int high)
{
    if(low > high)
        return -1;
    int mid = (low + high) / 2;
    if(sorted_array[mid] == val)
        return mid;
    else if(sorted_array[mid] > val)
        return binary_search(val, low, mid - 1);
    else if(sorted_array[mid] < val)
        return binary_search(val, mid + 1, high);
}

void search::linked_list_search(int val, int command)
{
    int index;
    switch(command)
    {
        case 5:
            index = list->search(val);
            break;
        case 6:
            index = list->recursive_search(val);
            break;
        default:
            cout << "\nInvalid command.";
    }
    if(index == -1)
        cout << "\nNumber " << val << " is not in the list.\n";
    else
        cout << "\nElement index: " << index << endl;
}

void search::print_array()
{
    string printout;
    for(int i = 0; i < size; i++)
        printout += " " + to_string(array[i]) ;
    cout << printout;
}

void search::print_S_array()
{
    string printout;
    for(int i = 0; i < size; i++)
        printout += " " + to_string(sorted_array[i]) ;
    cout << printout;
}