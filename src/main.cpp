#include "Orderbook.hpp"

#include <iostream>
#include <algorithm>


int main() {
    Orderbook book;

    Order bid1{1, 5, 100, Side::Bid};
    Order bid2{2, 3, 105, Side::Bid};
    Order bid3{3, 8, 99, Side::Bid};

    Order ask1{4, 2, 110, Side::Ask};
    Order ask2{5, 7, 103, Side::Ask};
    Order ask3{6, 1, 105, Side::Ask};

    book.addOrder(bid1);
    book.addOrder(bid2);
    book.addOrder(bid3);
    book.addOrder(ask1);
    book.addOrder(ask2);
    book.addOrder(ask3);

    book.printOrder();
    book.printTopBook();

    return 0;
}
