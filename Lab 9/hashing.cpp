//
// Created by minhh on 11/30/2020.
//

#include "hashing.h"

stock::stock()
{
    symbol = "";
    share = NULL;
    price = NULL;
}

stock::stock(int no, int no_share, int no_price)
{
    symbol = "APLL_" + to_string(no);
    share = no_share;
    price = no_price;
}

stock::~stock()
{
    symbol = "";
    share = 0;
    price = 0;
}

string stock::get_symbol()
{
    return symbol;
}

int stock::get_price()
{
    return price;
}

int stock::get_share()
{
    return share;
}

void stock::print()
{
    cout << "\nSymbol: " << symbol << "\nShare: " << share << "\nPrice: " << price << endl;
}

//==============================================================================================//

stock_node::stock_node(stock input){
    next = nullptr;
    data = input;
}

stock_node::~stock_node() = default;

//==============================================================================================//
hashing::hashing()
{
    linear = NULL;
    linear_flag = NULL;
    quadratic = NULL;
    quadratic_flag = NULL;
    chaining = NULL;
}

hashing::~hashing()
{
    delete linear;
    delete linear_flag;
    delete quadratic;
    delete quadratic_flag;
    delete chaining;
    size = 0;
    count = 0;
}

void hashing::create_stock()
{
    std::cout << "Enter the number of stock (must be larger or equal 10): ";
    int n;
    cin >> n;
    while(n < 10)
    {
        std::cout << "Invalid, please re-enter: ";
        std::cin >> n;
    }
    size = n + 10;                                                             //create table with 10 extra space;
    linear = new stock[size];
    linear_flag = new int[size];
    quadratic = new stock[size];
    quadratic_flag = new int[size];
    chaining = new stock_node*[size];
    for(int i = 0; i < n; i++)
    {
        int stock_share = rand() % 100;
        int stock_price = rand() % 100;
        stock input = stock(i, stock_share, stock_price);
        hash(input);
    }
    command();
}

unsigned hashing::hashing_function(string to_hash) {
    // DJB2 Hashing Algorithm
    unsigned int hash = 5381;
    for(char c: to_hash){
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

void hashing::linear_hash(stock input)
{
    int hash = hashing_function(input.get_symbol()) % size;
    int attemp = 0;
    do
    {
        int index = (hash + attemp) % size;
        if (linear_flag[index] != flagOCCUPIED)
        {
            linear[index] = input;
            linear_flag[index] = flagOCCUPIED;
            return;
        }
        else if(linear_flag[index] == flagOCCUPIED && linear[index].get_symbol() == input.get_symbol())
        {
            linear[index] = input;
            return;
        }
        attemp++;
    }
    while(true);
}

void hashing::quadratic_hash(stock input){
    int hash = hashing_function(input.get_symbol()) % size;
    int attemp = 0;
    do
    {
        int index = (hash + attemp^2) % size;
        if (quadratic_flag[index] != flagOCCUPIED)
        {
            quadratic[index] = input;
            quadratic_flag[index] = flagOCCUPIED;
            return;
        }
        else if(quadratic_flag[index] == flagOCCUPIED && quadratic[index].get_symbol() == input.get_symbol())
        {
            quadratic[index] = input;
            return;
        }
        attemp++;
    }
    while(true);
}

void hashing::chaining_hash(stock input){
    int index = hashing_function(input.get_symbol()) % size;
    stock_node *to_input = new stock_node(input);
    if(chaining[index] == nullptr)
        chaining[index] = to_input;
    else
    {
        stock_node *current = chaining[index];
        while(current->next)
        {
            if(current->data.get_symbol() == to_input->data.get_symbol())
            {
                current->data = to_input->data;
                count--;
                return;
            }
            current = current->next;
        }
        current->next = to_input;
    }
}

void hashing::hash(stock input)
{
    if(count >= size)
    {
        cout << "Unable to add to linear and quadratic table." << endl;
        chaining_hash(input);
        count++;
    }
    else
    {
        count++;
        linear_hash(input);
        quadratic_hash(input);
        chaining_hash(input);
    }
}

void hashing::search(int number, int type)
{
    string symbol = "APLL_" + to_string(number);
    int index;
    stock_node *search;
    switch(type)
    {
        case 1:
            index = search_linear(symbol);
            if(index != -1)
                linear[index].print();
            break;
        case 2:
            index = search_quaratic(symbol);
            if(index != -1)
                quadratic[index].print();
            break;
        case 3:
            search = search_chaining(symbol);
            if(search != nullptr)
                search->data.print();
            break;
    }
}

int hashing::search_linear(string symbol)
{
    int hash = hashing_function(symbol) % size;
    int attemp = 0;
    do
    {
        int index = (hash + attemp) % size;
        if(linear_flag[index] == flagOCCUPIED && linear[index].get_symbol() == symbol)
        {
            return index;
        }
        else if(linear_flag[index] == flagEMPTY)
        {
            cout << "\nDoes not exist." << endl;
            return -1;
        }
        attemp++;
    }
    while(true);
}

int hashing::search_quaratic(string symbol)
{
    int hash = hashing_function(symbol) % size;
    int attemp = 0;
    do
    {
        int index = (hash + attemp^2) % size;
        if(quadratic_flag[index] == flagOCCUPIED && quadratic[index].get_symbol() == symbol)
        {
            return index;
        }
        else if(quadratic_flag[index] == flagEMPTY)
        {
            cout << "\nDoes not exist." << endl;
            return -1;
        }
        attemp++;
    }
    while(true);
}

stock_node *hashing::search_chaining(string symbol)
{
    int index = hashing_function(symbol) % size;
    if(chaining[index] == nullptr)
    {
        cout << "\nDoes not exits." << endl;
        return nullptr;
    }
    else
    {
        stock_node *current = chaining[index];
        while(current)
        {
            if(current->data.get_symbol() == symbol)
            {
                return current;
            }
            current = current->next;
        }
        cout << "\nDoes not exits." << endl;
        return nullptr;
    }
}

void hashing::command()
{
    do
    {
        cout << "\nWhat do you want to do?" << endl;
        cout << "(1) Search linear hash table." << endl;
        cout << "(2) Search quadratic hash table." << endl;
        cout << "(3) Search chaining hash table." << endl;
        cout << "(4) Delete stock." << endl;
        cout << "(0) Exit." << endl;
        cout << "Your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 0)
            return;
        else if(choice > 4 || choice < 0)
        {
            cout << "Invalid. Please try again.\n";
            continue;
        }
        int number;
        cout << "Which stock you want to see: APLL_";
        cin >> number;
        if(choice != 4)
            search(number, choice);
        else
            remove(number);
    }
    while(true);
}

void hashing::remove(int number)
{
    string symbol = "APLL_" + to_string(number);
    remove_linear(symbol);
    remove_quaratic(symbol);
    remove_chaining(symbol);
}

void hashing::remove_linear(string symbol)
{
    int index = search_linear(symbol);
    if(index == -1)
    {
        cout << "\nDoes not exist in linear table." << endl;
    }
    else
    {
        linear_flag[index] = flagDELETE;
    }
}

void hashing::remove_quaratic(string symbol){
    int index = search_quaratic(symbol);
    if(index == -1)
    {
        cout << "\nDoes not exist in quadratic table." << endl;
    }
    else
    {
        quadratic_flag[index] = flagDELETE;
        cout << "\nDeleted" << endl;
    }
}

void hashing::remove_chaining(string symbol)
{
    int index = hashing_function(symbol) % size;
    if(chaining[index] == nullptr)
    {
        cout << "Does not exits." << endl;
    }
    else if(chaining[index]->data.get_symbol() == symbol && chaining[index]->next == nullptr)
    {
        stock_node *to_delete = chaining[index];
        chaining[index] = nullptr;
        delete to_delete;
        return;
    }
    else
    {
        bool found = false;
        stock_node *current = chaining[index];
        int count = 0;
        while(current)
        {
            if(current->data.get_symbol() == symbol)
            {
                found = true;
                break;
            }
            current = current->next;
            count++;
        }
        if(found)
        {
            if(current->next == nullptr)
            {
                stock_node *temp = chaining[index];
                for(int i = 1; i < count; i++)
                    temp = temp->next;
                temp->next = nullptr;
                delete current;
                return;
            }
            while(current->next->next)
            {
                current->data = current->next->data;
                current = current->next;
            }
            current->data = current->next->data;
            stock_node *to_delete = current->next;
            current->next = nullptr;
            delete to_delete;
        }
        else;
            cout << "\nDoes not exits." << endl;
    }
}