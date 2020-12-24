//
// Created by minhh on 11/30/2020.
//

#ifndef LAB_9_HASHING_H
#define LAB_9_HASHING_H
#define flagEMPTY 0
#define flagOCCUPIED -1
#define flagDELETE -2

#include <iostream>
#include <iomanip>

using namespace std;
class stock{
private:
    string symbol;
    int share;
    int price;
public:
    stock();
    stock(int no, int no_share, int no_price);
    ~stock();
    string get_symbol();
    int get_share();
    int get_price();
    void print();
};

class stock_node{
public:
    stock_node *next;
    stock data;
    stock_node(stock input);
    ~stock_node();
};

class hashing {
public:
    stock *linear;
    int *linear_flag;
    stock *quadratic;
    int *quadratic_flag;
    stock_node **chaining;
    int size;
    int count;
public:
    hashing();
    ~hashing();
    void create_stock();
    unsigned hashing_function(string to_hash);
    void linear_hash(stock input);
    void quadratic_hash(stock input);
    void chaining_hash(stock input);
    void hash(stock input);
    void search(int number, int type);
    int search_linear(string symbol);
    int search_quaratic(string symbol);
    stock_node *search_chaining(string symbol);
    void command();
    void remove(int number);
    void remove_linear(string symbol);
    void remove_quaratic(string symbol);
    void remove_chaining(string symbol);
};

bool isNumber (const string &s);
int getNumber();
#endif //LAB_9_HASHING_H
