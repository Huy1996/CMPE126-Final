//
// Created by minhh on 11/12/2020.
//

#include <stdexcept>
#include "palindrome.h"
//----------------------------Queue section-----------------------------------//
queue::queue()
{
    store = new char[200];
    front_index = 0;
    back_index = 0;
}

queue::~queue()
{
    delete[] store;
    front_index = 0;
    back_index = 0;
}

bool queue::is_empty()
{
    return front_index == back_index;
}

int queue::size()
{
    return front_index - back_index;
}

char queue::top()
{
    if(back_index == front_index)
        throw out_of_range("Empty Queue Exception");
    else
        return store[front_index % 200];
}

void queue::enqueue(char input)
{
    if(back_index - front_index >= 200)
        throw out_of_range("Queue already full");
    else
    {
        store[back_index % 200] = input;
        back_index++;
    }
}

void queue::dequeue()
{
    if(front_index == back_index)
        throw out_of_range("Empty Queue");
    else
        front_index++;
}


//----------------------------Stack section-----------------------------------//

stack::stack()
{
    store = new char[200];
    index = 0;
}

stack::~stack()
{
    delete[] store;
    index = 0;
}

bool stack::is_empty()
{
    return index == 0;
}

int stack::size()
{
    return index;
}

char stack::top()
{
    if(index == 0)
        throw out_of_range("Stack empty");
    else
        return store[index - 1];
}

void stack::push(char input)
{
    if(index == 200)
        throw out_of_range("Stack fulled");
    else
    {
        store[index] = input;
        index++;
    }
}

void stack::pop()
{
    if(index == 0)
        throw out_of_range("Stack empty");
    else
        index--;
}