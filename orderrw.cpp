#include "orderrw.h"
#include <fstream>
#include <iostream>
#include <sstream>

std::vector<Order> readOrdersFromFile(const std::string& filename, double& lastPrice) {
    std::ifstream inputFile(filename);
    std::vector<Order> orders;

    if (!inputFile) {
        std::cerr << "Error: Unable to open file " << filename << "\n";
        return orders;
    }

    inputFile >> lastPrice;
    std::string line;
    std::getline(inputFile, line); // Skip rest of the first line

    int timestamp = 0;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string orderID, typeStr;
        int quantity;
        double limitPrice = -1.0;

        iss >> orderID >> typeStr >> quantity;
        char type = typeStr[0];

        if (iss >> limitPrice) {
            // Limit price is set
        }

        orders.emplace_back(orderID, quantity, type, timestamp++, limitPrice);
    }

    return orders;
}

void writeOrdersToFile(const std::string& filename, const std::vector<std::string>& executedOrders,
                       const std::vector<Order>& pendingOrders) {
    std::ofstream outputFile(filename);

    if (!outputFile) {
        std::cerr << "Error: Unable to open file " << filename << "\n";
        return;
    }

    for (const auto& exec : executedOrders) {
        outputFile << exec << "\n";
    }

    for (const auto& order : pendingOrders) {
        outputFile << "order " << order.getOrderID() << " " << order.getQuantity()
                   << " shares unexecuted\n";
    }
}