#include "Order.h"
#include <iostream>
#include <iomanip>

// Constructor
Order::Order(const std::string& orderID_, int quantity_, char type_, int timestamp_, double limitPrice_)
    : orderID_(orderID_), quantity_(quantity_), type_(type_), timestamp_(timestamp_), limitPrice_(limitPrice_) {}

// Display the order (for debugging or output purposes)
void Order::display() const {
    std::cout << std::fixed << std::setprecision(2); // Ensure prices have 2 decimal places
    std::cout << orderID_ << " "
              << (type_ == 'B' ? "Buy" : "Sell") << " "
              << quantity_ << " "
              << (limitPrice_ < 0 ? "Market Order" : std::to_string(limitPrice_))
              << "\n";
}