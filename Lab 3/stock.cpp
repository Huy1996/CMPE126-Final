//
// Created by minhh on 9/11/2020.
//

#include <iomanip>
#include "stock.h"

stock::stock()
{
    head = nullptr;
    tail = nullptr;
}

stock::~stock()
{
    node* current_node=head;
    node* delete_node;
    while(current_node){
        delete_node = current_node;
        current_node = current_node-> next;
        delete delete_node;
    }
}

void stock::append(node *input)
{
    if (head == nullptr){
        head = input;
        tail = input;
    }
    else {
        tail->next = input;
        tail = input;
    }
}

void stock::append_list(const stock &s)
{
    node* current_node = s.head;
    while (current_node)
    {
        append(current_node);
        current_node = current_node->next;
    }
}

void stock::create_stock()
{
    std::cout << "Enter the number of stock (must be larger or equal 20): ";
    std::cin >> length;
    while(length < 20)
    {
        std::cout << "Invalid, please re-enter: ";
        std::cin >> length;
    }
    for(int i = 0; i < length; i++)
    {
        std::string stock_symbol = "AAPL_" + std::to_string(i);
        int stock_share = rand() % 100;
        int stock_price = rand() % 100;
        node *input = new node(stock_symbol, stock_share, stock_price);
        this->append(input);
    }
}

void stock::returnMiddleList()
{
    node *current_node_1 = head;
    node *current_node_2 = head;
    int count = 0;
    while (current_node_2->next)
    {
        current_node_1 = current_node_1 -> next;
        current_node_2 = current_node_2 -> next -> next;
        count ++;
    }
    std::cout << "\nThe middle of the list at position " << count << "." << std::endl;
    std::cout << "Symbol" << std::setw(11) << "Share" << std::setw(10) << "Price" << std::endl;
    std::cout << current_node_1->symbol << std::setw(10) << current_node_1->share << std::setw(10) << current_node_1->price << std::endl;
    std::cout << "#----------------------------#" << std::endl;
}

void stock::print_list()
{
    node* current_node = head;
    std::cout << "Symbol" << std::setw(11) << "Share" << std::setw(10) << "Price" << std::endl;
    while(current_node)
    {
        std::cout << current_node->symbol << std::setw(10) << current_node->share << std::setw(10) << current_node->price << std::endl;
        current_node = current_node->next;
    }
    std::cout << "#----------------------------#" << std::endl;
}

void stock::slip_in_half(stock &first, stock &second)
{
    node *current_node = head;
    node *current_node_2 = head;
    while (current_node_2->next)
    {
        node* input_node = new node(current_node->symbol, current_node->share, current_node->price);
        first.append(input_node);
        current_node = current_node -> next;
        current_node_2 = current_node_2 -> next -> next;
    }

    while(current_node)
    {
        node* input_node = new node(current_node->symbol, current_node->share, current_node->price);
        second.append(input_node);
        current_node = current_node->next;
    }
}


