//
// Created by minhh on 11/12/2020.
//

#ifndef LAB_7_PALINDROME_H
#define LAB_7_PALINDROME_H
using namespace std;
class queue{
    private:
        char *store;
        unsigned front_index;
        unsigned back_index;

    public:
        queue();
        virtual ~queue();
        bool is_empty();
        int size();
        char top();
        void enqueue(char input);
        void dequeue();
};

class stack{
    private:
        char *store;
        unsigned index;

    public:
        stack();
        virtual ~stack();
        bool is_empty();
        int size();
        char top();
        void push(char input);
        void pop();
};



#endif //LAB_7_PALINDROME_H
