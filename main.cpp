#include <iostream>
#include <vector>
#include "Order.h"


std::vector<Order> readOrdersFromFile(const std::string& filename, double& lastPrice);
void writeOrdersToFile(const std::string& filename, const std::vector<Order>& executedOrders,
                       const std::vector<Order>& pendingOrders);

int main() {

    std::string inputFilename = "input.txt";
    std::string outputFilename = "output.txt";

    // Variables to store orders and last price
    double lastPrice;
    std::vector<Order> orders = readOrdersFromFile(inputFilename, lastPrice);

    // Separate executed and pending orders
    std::vector<Order> executedOrders;
    std::vector<Order> pendingOrders;

    // Simple order processing logic
    for (const auto& order : orders) {
        if ((order.getType() == "buy" && order.getPrice() >= lastPrice) ||
            (order.getType() == "sell" && order.getPrice() <= lastPrice)) {
            executedOrders.push_back(order);
            } else {
                pendingOrders.push_back(order);
            }
    }

    // Write results to the output file
    writeOrdersToFile(outputFilename, executedOrders, pendingOrders);

    std::cout << "Processing complete. Results written to " << outputFilename << ".\n";
    return 0;
}