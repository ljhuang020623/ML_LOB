#include "Orderbook.hpp"

#include <iostream>

void printState(const char* title, const Orderbook& book) {
    std::cout << "\n=== " << title << " ===\n";
    book.printOrder();
    book.printTopBook();
    book.printTrades();
}

int main() {
    Orderbook book;

    book.addOrder(Order{1, 10, 100, Side::Bid});
    book.addOrder(Order{2, 5, 105, Side::Bid});
    book.addOrder(Order{3, 7, 100, Side::Bid});
    printState("After adding resting bids", book);

    book.addOrder(Order{4, 4, 110, Side::Ask});
    book.addOrder(Order{5, 6, 108, Side::Ask});
    book.addOrder(Order{6, 3, 110, Side::Ask});
    printState("After adding resting asks", book);

    book.addOrder(Order{7, 7, 110, Side::Bid});
    printState("After bid 7 crosses the ask side", book);

    book.addOrder(Order{8, 20, 99, Side::Ask});
    printState("After ask 8 crosses the bid side", book);

    return 0;
}
