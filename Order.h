#ifndef ORDER_H
#define ORDER_H

#include <string>

class Order {
private:
    std::string orderID_; // Unique order identifier
    int quantity_;        // Number of shares
    char type_;           // 'B' for Buy or 'S' for Sell
    int timestamp_;       // Arrival time for priority
    double limitPrice_;   // Limit price; -1.0 for market orders

public:

    Order(const std::string& orderID_, int quantity_, char type_, int timestamp_, double limitPrice_ = -1.0);


};

#endif