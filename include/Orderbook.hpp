#pragma once

#include "Order.hpp"
#include "Trade.hpp"

#include <vector>

class Orderbook{
public:
    void addOrder(const Order& order);
    void printOrder() const;
    // print the best sell
    void printTopBook() const;
private:
    std::vector<Order> bids;
    std::vector<Order> asks;
    std::vector<Trade> trades;
};