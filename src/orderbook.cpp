#include "Orderbook.hpp"
#include "Order.hpp"

#include <iostream>

void Orderbook::addOrder(const Order& order){
    // Best ask(smallest on the front)
    if (order.side == Side::Ask){
        int i = 0;
        while (i < asks.size()){
            if (order.price < asks[i].price){
                asks.insert(asks.begin() + i, order);
                return;
            }
            i++;
        }
        asks.push_back(order);
    }
    // Best bid(largest on the front) 
    else if (order.side == Side::Bid){
        int i = 0;
        while (i < bids.size()){
            if (order.price > bids[i].price){
                bids.insert(bids.begin() + i, order);
                return;
            }
            i++;
        }
        bids.push_back(order);
    }
}

void Orderbook::printTopBook() const {
    std::cout << "TOP OF BOOK:\n";
    // Best ask(lowest ask)
    if (asks.empty()) {
        std::cout << "Best ask: none\n";
    } else {
        const Order& bestAsk = asks.front();
        std::cout << "Best ask: "
                  << "id=" << bestAsk.id
                  << " price=" << bestAsk.price
                  << " qty=" << bestAsk.qty
                  << '\n';
    }
    // Best bid(highest bid)
    if (bids.empty()) {
        std::cout << "Best bid: none\n";
    } else {
        const Order& bestBid = bids.front();
        std::cout << "Best bid: "
                  << "id=" << bestBid.id
                  << " price=" << bestBid.price
                  << " qty=" << bestBid.qty
                  << '\n';
    }
    if (!bids.empty() && !asks.empty()) {
        int spread = asks.front().price - bids.front().price;
        std::cout << "Spread: " << spread << '\n';
    }
}

void Orderbook::printOrder() const{
    std::cout << "BIDS: \n";
    for (const Order& order : bids){
        std::cout << "id=" << order.id
                  << " price=" << order.price
                  << " qty="  << order.qty
                  << '\n';
    }
    std::cout << "ASKS: \n";
    for (const Order& order : asks){
        std::cout << "id=" << order.id
                  << " price=" << order.price
                  << " qty="  << order.qty
                  << '\n';
    }
}
