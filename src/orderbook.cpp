#include "Orderbook.hpp"
#include "Order.hpp"


#include <iostream>
#include <algorithm>

void Orderbook::addOrder(const Order& order){
    // keep the original order, copy the current order
    Order incoming = order;

    // Best ask(smallest on the front)
    if (incoming.side == Side::Ask){
        while (incoming.qty > 0 && !(bids.empty())) {
            Order& bestBid = bids.front();

            if (incoming.price > bestBid.price) {
                break;
            }

            int tradeqty = std::min(incoming.qty, bestBid.qty);
            Trade trade{
                bestBid.id,
                incoming.id,
                tradeqty,
                bestBid.price
            };
            addTrade(trade);
            
            incoming.qty -= tradeqty;
            bestBid.qty -= tradeqty;
            
            if (bestBid.qty == 0) {
                bids.erase(bids.begin());
            }
        }
        if (incoming.qty > 0) {
            int i = 0;
            while (i < asks.size()) {
                // if the price is equal u still need to keep going cuz the id is different(the order is from differnt person)
                if (incoming.price < asks[i].price) {
                    asks.insert(asks.begin() + i, incoming);
                    return;
                }
                i++;
            }
            asks.push_back(incoming);
        }
    }

    // Best bid(largest on the front) 
    else if (order.side == Side::Bid){
        while (incoming.qty > 0 && !(asks.empty())) {
            Order& bestAsk = asks.front();

            if (incoming.price < bestAsk.price){
                break;
            }
            int tradeqty = std::min(incoming.qty, bestAsk.qty);
            Trade trade{
                incoming.id,
                bestAsk.id,
                tradeqty,
                bestAsk.price
            };
            addTrade(trade);

            incoming.qty -= tradeqty;
            bestAsk.qty -= tradeqty;

            if (bestAsk.qty == 0) {
                asks.erase(asks.begin());
            }
        }
        if (incoming.qty > 0){
            int i = 0;
            while (i < bids.size()) {
                if (incoming.price > bids[i].price) {
                    bids.insert(bids.begin() + i, incoming); 
                    return;
                }
                i++;
            }
            bids.push_back(incoming);
        }
    }
}

void Orderbook::addTrade(const Trade& trade){
    trades.push_back(trade);
}

void Orderbook::printTrades() const{
    std::cout << "TRADES: \n";
    for (const Trade& trade : trades){
        std::cout << "buyOrderID=" << trade.buyOrderID
                  << " sellOrderID=" << trade.sellOrderID
                  << " qty=" << trade.tradeQty
                  << " price=" << trade.tradePrice
                  << '\n';
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
