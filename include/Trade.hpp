#pragma once

// Trade is a record of every order in the book

struct Trade{
    int buyOrderID;
    int sellOrderID;
    int qty;
    int price;
};