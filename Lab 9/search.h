//
// Created by minhh on 11/27/2020.
//

#ifndef LAB_9_SEARCH_H
#define LAB_9_SEARCH_H
#include <iostream>
using namespace std;
class node{
public:
    int data;
    node *next;
    node(int input);
    ~node();
};

class linked_list{
private:
    node *head, *tail;
public:
    linked_list();
    ~linked_list();
    void append(int value);
    int size();
    int get_value(int position);
    int search(int value);
    int recursive_search(int val);
    int search_recursively(node *current, int position, int val);
    void printout();

};

class search {
private:
    int *array;
    int *sorted_array;
    linked_list list;
    int size;
public:
    search();
    ~search();
    void create_list();
    void command();
    void array_search(int val, int command);
    int array_search(int val);
    int array_search_recursive(int val, int left, int right);
    void binary_search(int val, int command);
    int binary_search(int val);
    int binary_search(int val, int low, int high);
    void linked_list_search(int val, int command);
    void print_array();
    void print_S_array();
};

#endif //LAB_9_SEARCH_H
