//
// Created by minhh on 10/20/2020.
//

#ifndef LAB_6_CALCULATOR_H
#define LAB_6_CALCULATOR_H
#include <string>
#include <math.h>
#include <iostream>
#include <math.h>
#include <iterator>
using namespace std;
class expressionstream{
private:
    string buffer;
    string::iterator current_pos;
    string::iterator next_position;

    void skip_space();
    string get_number();
    bool is_negative();
public:
    explicit expressionstream(const string &string_in);
    string get_next_token();
    string get_current_token();
    bool next_token_is_special();
    bool next_token_is_int();
    bool next_token_is_op();
    bool next_token_is_open_paren();
    bool next_token_is_close_paren();
};

class node{
public:
    node *next;
    string data;
    node(string input);
    ~node();
};

class stack{
private:
    node *head;
    node *tail;
public:
    stack();
    stack(string data);
    stack(const stack &original);
    ~stack();
    void push(string input);
    string top();
    void pop();
    bool empty();
    unsigned size() const;
    stack &operator=(const stack &RHS);
};

class queue{
private:
    node *head;
    node *tail;
public:
    queue();
    queue(string data);
    queue(const queue &original);
    ~queue();
    void enqueue(string data);
    void dequeue();
    string top();
    bool empty();
    unsigned size() const;
    queue &operator=(const queue &RHS);
    friend std::ostream& operator<<(std::ostream& stream, queue& RHS);
};

class calculator {
private:
    queue infix, postfix;

public:
    void getInfix();
    bool check_valid(const string &input);
    void convertToPostfix();
    void showInfix();
    void showPostfix();
    int calculate();


};


#endif //LAB_6_CALCULATOR_H
