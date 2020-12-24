//
// Created by minhh on 9/11/2020.
//

#ifndef LAB_3_STOCK_H
#define LAB_3_STOCK_H
#include "node.h"
#include <iostream>


class stock {
node *head, *tail;
int length;
public:
    stock();
    virtual ~stock();
    void append(node *input);
    void append_list(const stock &s);
    void create_stock();
    void returnMiddleList();
    void print_list();
    void slip_in_half(stock &first, stock &second);
    stock &operator = (const stock &rhs);
};


#endif //LAB_3_STOCK_H
