#include <iostream>
#include "stock_node.h"
int main() {
    stock_list *c = new stock_list();
    c->create_stock();
    std::cout << "The stock list forward:\n";
    c->print_list_forward();
    std::cout << "\nThe stock list backward:\n";
    c->print_list_backward();
    //copy front, back and position 13;
    auto *front_node = new stock_node(c->get_symbol(0),c->get_share(0), c->get_price(0));
    auto *mid_node = new stock_node(c->get_symbol(13),c->get_share(13), c->get_price(13));
    auto *back_node = new stock_node(c->get_symbol(c->get_length()-1),c->get_share(c->get_length()-1), c->get_price(c->get_length()-1));

    //delete front, back and position 13;
    std::cout << "\n\nStock list after delete AAPL 13, front and back:\n";
    c->delete_at(13);
    c->delete_front();
    c->delete_back();
    c->print_list_forward();

    //insert front, back and position 13;
    std::cout << "\n\nStock list after insert front, back and position 13:\n";
    c->insert_front(front_node);
    c->append(back_node);
    c->insert_at(13, mid_node);
    c->print_list_forward();

    std::cout<<"\n\n";
    //return middle and slip in half
    stock_list first_half, second_half;
    c->returnMiddleList();
    c->slip_in_half(first_half, second_half);
    std::cout << "\n\nThe first half of the list:\n";
    first_half.print_list_forward();
    std::cout << "\nThe second half of the list:\n";
    second_half.print_list_forward();

    /* Extra work trying overloading operator
    stock_list total;
    total = first_half + second_half;
    first_half += second_half;
    std::cout<< "\n\n\n\nThe list total is:\n";
    total.print_list_forward();
    std::cout<< "\n\n\n\nThe list first_half is:\n";
    first_half.print_list_forward();
    std::cout<< "\n\n\n\nTest overloading operator = :\n";
    first_half.print_list_forward();
    second_half.~stock_list();
    std::cout<< "\nTest dangling pointer: \n";
    first_half.print_list_forward();
    */
    return 0;

}