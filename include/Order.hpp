#pragma once

#include "Side.hpp"

// Define what one order is.
struct Order{
    int id;
    int qty;
    int price;
    Side side;
};
