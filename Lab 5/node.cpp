//Name: Nguyen Minh Huy Duong
//Lab 3: Linked list
//Due: 10/8/20
#include "node.h"

node::node(std::string stock_symbol, int stock_share, int stock_price){
    next = nullptr;
    symbol = stock_symbol;
    share = stock_share;
    price = stock_price;
}

node::~node() = default;

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

void stock::insert_front(node *input)
{
    if (head == nullptr)
        this->append(input);
    else
    {
        input->next = head;
        head = input;
        length++;
    }
}

void stock::append(node *input)
{
    length++;
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

int stock::get_length()
{
    return length;
}

std::string stock::get_symbol(int pos)
{
    if(pos >= length || pos < 0)
    {
        throw std::exception();
    }
    node *current_node = this->travel_to(pos);
    return current_node->symbol;
}

int stock::get_share(int pos)
{
    if(pos >= length || pos < 0)
    {
        throw std::exception();
    }
    node *current_node = this->travel_to(pos);
    return current_node->share;
}

int stock::get_price(int pos)
{
    if(pos >= length || pos < 0)
    {
        throw std::exception();
    }
    node *current_node = this->travel_to(pos);
    return current_node->price;
}

node *stock::travel_to(int pos)
{
    if(pos >= length || pos < 0)
    {
        throw std::exception();
    }
    node *current_node = head;
    for(int i = 0; i < pos; i++)
        current_node = current_node->next;
    return current_node;
}

void stock::create_stock()
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
        node *input = new node(stock_symbol, stock_share, stock_price);
        this->append(input);
    }
}


void stock::returnMiddleList()
{
    node *current_node_1 = head;
    node *current_node_2 = head;
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
    while (current_node_2->next && current_node_2->next->next)
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

void stock::print_list_forward_recursively(node *current_node)
{
    if(current_node == nullptr)
        return;
    std::cout << current_node->symbol << std::setw(10) << current_node->share << std::setw(10) << current_node->price << std::endl;
    print_list_forward_recursively(current_node->next);
}

void stock::print_list_backward_recursively(node *current_node)
{
    if(current_node == nullptr)
        return;
    print_list_backward_recursively(current_node->next);
    std::cout << current_node->symbol << std::setw(10) << current_node->share << std::setw(10) << current_node->price << std::endl;

}