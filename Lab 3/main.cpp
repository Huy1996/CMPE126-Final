//Name: Nguyen Minh Huy Duong
//Lab 3: Linked list
//Due: 10/8/20

#include "node.h"
int main() {
    stock *c = new stock();
    c->create_stock();
    c->print_list();
    c->returnMiddleList();
    stock first_half, second_half;
    c->slip_in_half(first_half, second_half);

    std::cout << "\nThe first half of the list: \n";
    first_half.print_list();

    std::cout << "\nThe second half of the list: \n";
    second_half.print_list();

    std::cout << "\nAdd second list back to first list: \n";
    first_half.append_list(second_half);
    first_half.print_list();

    node *insert_node = new node("APPL_i", 13, 23);
    first_half.insert_front(insert_node);
    std::cout << "\nThe first list after insert new node at head: \n";
    first_half.print_list();

    std::cout << "\nGet data at position 13 of stock c:\n";
    std::cout << "Stock symbol: " << c->get_symbol(13) <<" Share: " << c->get_share(13) << " Price: " << c->get_price(13) << std::endl;
    return 0;
}