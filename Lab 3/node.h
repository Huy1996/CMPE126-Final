//Name: Nguyen Minh Huy Duong
//Lab 3: Linked list
//Due: 10/8/20

#ifndef LAB_3_NODE_H
#define LAB_3_NODE_H
#include <iostream>
#include <iomanip>

class node {
public:
    node *next;
    std::string symbol;
    int share;
    int price;
    node(std::string stock_symbol, int stock_share, int stock_price);
    ~node();
};

class stock {
    node *head, *tail;
    int length;
public:
    stock();
    virtual ~stock();
    void insert_front(node *input);
    int get_length();
    std::string get_symbol(int pos);
    int get_share(int pos);
    int get_price(int pos);
    node *travel_to(int pos);
    void append(node *input);
    void append_list(const stock &s);
    void create_stock();
    void returnMiddleList();
    void print_list();
    void slip_in_half(stock &first, stock &second);
    stock &operator = (const stock &rhs);
};

#endif //LAB_3_NODE_H
