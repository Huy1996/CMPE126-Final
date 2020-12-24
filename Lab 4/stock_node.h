//
// Created by minhh on 10/7/2020.
//

#ifndef LAB_4_STOCK_NODE_H
#define LAB_4_STOCK_NODE_H
#include <iostream>
#include <iomanip>

class stock_node {
public:
    stock_node *next, *previous;
    std::string symbol;
    int share;
    int price;
    stock_node(std::string stock_symbol, int stock_share, int stock_price);
    ~stock_node();
};

class stock_list {
private:
    stock_node *head, *tail;
    int length;
public:
    stock_list();
    virtual ~stock_list();
    void delete_front();
    void delete_back();
    void delete_at(int pos);
    void insert_front(stock_node *input);
    void insert_at(int pos, stock_node *input);
    int get_length();
    std::string get_symbol(int pos);
    int get_share(int pos);
    int get_price(int pos);
    stock_node *travel_to(int pos);
    void append(stock_node *input);
    void append_list(const stock_list &s);
    void create_stock();
    void returnMiddleList();
    void print_list_forward();
    void print_list_backward();
    void slip_in_half(stock_list &first, stock_list &second);
    stock_list &operator = (const stock_list &rhs);
    stock_list &operator += (const stock_list &rhs);
    stock_list &operator + (const stock_list &rhs) const;
};


#endif //LAB_4_STOCK_NODE_H
