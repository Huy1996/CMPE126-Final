//
// Created by minhh on 10/7/2020.
//

#include "stock_node.h"
stock_node::stock_node(std::string stock_symbol, int stock_share, int stock_price){
    next = nullptr;
    previous = nullptr;
    symbol = stock_symbol;
    share = stock_share;
    price = stock_price;
}

stock_node::~stock_node() = default;

stock_list::stock_list()
{
    head = nullptr;
    tail = nullptr;
}

stock_list::~stock_list()
{
    stock_node *current_node = head;
    stock_node *delete_node;
    while(current_node){
        delete_node = current_node;
        current_node = current_node -> next;
        delete delete_node;
        length--;
    }
    head = nullptr;
    tail = nullptr;
}

void stock_list::delete_front()
{
    stock_node *delete_node = head;
    head = head->next;
    delete delete_node;
    head->previous= nullptr;
    length--;
}

void stock_list::delete_back()
{
    stock_node *delete_node = tail;
    tail = tail->previous;
    delete delete_node;
    tail->next = nullptr;
    length--;
}

void stock_list::delete_at(int pos)
{
    stock_node *delete_node = this->travel_to(pos);
    delete_node->previous->next = delete_node->next;
    delete_node->next->previous = delete_node->previous;
    delete delete_node;
    length--;
}

void stock_list::insert_front(stock_node *input)
{
    if (head == nullptr)
        this->append(input);
    else
    {
        input->next = head;
        head->previous = input;
        head = input;
    }
    length++;
}

void stock_list::insert_at(int pos, stock_node *input)
{
    stock_node *current_node = this->travel_to(pos);
    input->previous = current_node->previous;
    input->next = current_node;
    input->previous->next = input;
    current_node->previous = input;
    length++;
}

int stock_list::get_length()
{
    return length;
}

std::string stock_list::get_symbol(int pos)
{
    stock_node *current_node = this->travel_to(pos);
    return current_node->symbol;
}

int stock_list::get_share(int pos)
{
    stock_node *current_node = this->travel_to(pos);
    return current_node->share;
}

int stock_list::get_price(int pos)
{
    stock_node *current_node = this->travel_to(pos);
    return current_node->price;
}
stock_node *stock_list::travel_to(int pos)
{
    if(pos >= length || pos < 0)
    {
        throw std::exception();
    }
    stock_node *current_node = head;
    for(int i = 0; i < pos; i++)
        current_node = current_node->next;
    return current_node;
}

void stock_list::append(stock_node *input)
{
    if(head == nullptr)
    {
        head = input;
        tail = input;
    }
    else
    {
        tail->next = input;
        input->previous = tail;
        tail = input;
    }
    length++;
}

void stock_list::append_list(const stock_list &s)
{
    stock_node *current_node = s.head;
    while(current_node)
    {
        stock_node *input = new stock_node(current_node->symbol, current_node->share, current_node->price);
        append(input);
        current_node = current_node->next;
    }
}

void stock_list::create_stock()
{
    std::cout << "Enter the number of stock (must be larger or equal 20): ";
    int n;
    std::cin >> n;
    while(n < 20)
    {
        std::cout << "Invalid, please re-enter: ";
        std::cin >> n;
    }
    for(int i = 0; i < n; i++)
    {
        std::string stock_symbol = "AAPL_" + std::to_string(i);
        int stock_share = rand() % 100;
        int stock_price = rand() % 100;
        stock_node *input = new stock_node(stock_symbol, stock_share, stock_price);
        this->append(input);
    }
}

void stock_list::returnMiddleList()
{
    stock_node *current_node_1 = head;
    stock_node *current_node_2 = head;
    int count = 0;
    while (current_node_2->next && current_node_2->next->next)
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

void stock_list::print_list_forward()
{
    stock_node* current_node = head;
    std::cout << "Symbol" << std::setw(11) << "Share" << std::setw(10) << "Price" << std::endl;
    while(current_node)
    {
        std::cout << current_node->symbol << std::setw(10) << current_node->share << std::setw(10) << current_node->price << std::endl;
        current_node = current_node->next;
    }
    std::cout << "#----------------------------#" << std::endl;
}

void stock_list::print_list_backward()
{
    stock_node* current_node = tail;
    std::cout << "Symbol" << std::setw(11) << "Share" << std::setw(10) << "Price" << std::endl;
    while(current_node)
    {
        std::cout << current_node->symbol << std::setw(10) << current_node->share << std::setw(10) << current_node->price << std::endl;
        current_node = current_node->previous;
    }
    std::cout << "#----------------------------#" << std::endl;
}

void stock_list::slip_in_half(stock_list &first, stock_list &second)
{
    stock_node *current_node = head;
    stock_node *current_node_2 = head;
    while (current_node_2->next && current_node_2->next->next)
    {
        stock_node* input_node = new stock_node(current_node->symbol, current_node->share, current_node->price);
        first.append(input_node);
        current_node = current_node -> next;
        current_node_2 = current_node_2 -> next -> next;
    }

    while(current_node)
    {
        stock_node* input_node = new stock_node(current_node->symbol, current_node->share, current_node->price);
        second.append(input_node);
        current_node = current_node->next;
    }
}

stock_list& stock_list::operator = (const stock_list &rhs)
{
    if(this == &rhs)
        return *this;
    else
        this->~stock_list();

    stock_node *current_node = rhs.head;
    while(current_node)
    {
        stock_node* input_node = new stock_node(current_node->symbol, current_node->share, current_node->price);
        this->append(input_node);
        current_node = current_node->next;
    }
    return *this;
}

stock_list& stock_list::operator += (const stock_list &rhs)
{
    stock_node *current_node = rhs.head;
    while(current_node)
    {
        stock_node *input = new stock_node(current_node->symbol, current_node->share, current_node->price);
        this->append(input);
        current_node = current_node->next;
    }
    return *this;
}

stock_list& stock_list::operator + (const stock_list &rhs) const
{
    stock_list *to_return = new stock_list();
    stock_node *current_node = this->head;
    while(current_node)
    {
        stock_node *input = new stock_node(current_node->symbol, current_node->share, current_node->price);
        to_return->append(input);
        current_node = current_node->next;
    }

    current_node = rhs.head;
    while(current_node)
    {
        stock_node *input = new stock_node(current_node->symbol, current_node->share, current_node->price);
        to_return->append(input);
        current_node = current_node->next;
    }
    return *to_return;
}

