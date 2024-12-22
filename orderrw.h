#ifndef FILEIO_H
#define FILEIO_H

#include <vector>
#include <string>
#include "Order.h"

// Function to read orders from a file
std::vector<Order> readOrdersFromFile(const std::string& filename, double& lastPrice);

// Function to write executed and pending orders to a file
void writeOrdersToFile(const std::string& filename, const std::vector<std::string>& executedOrders,
                       const std::vector<Order>& pendingOrders);

#endif