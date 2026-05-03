#pragma once

#include "Order.hpp"
#include "Trade.hpp"

#include <vector>

class Orderbook{
public:
    void addOrder(const Order& order);
    void addTrade(const Trade& trade);
    void printOrder() const;
    void printTopBook() const;
    void printTrades() const;
private:
    std::vector<Order> bids;
    std::vector<Order> asks;
    std::vector<Trade> trades;
};