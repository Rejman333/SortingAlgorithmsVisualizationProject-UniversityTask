#include "headers/tools.h"

#include <iostream>
#include <random>

std::vector<int> generate_array(const int size, const int min, const int max) {
    std::vector<int> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);

    for (int &val: arr) {
        val = dist(gen);
    }
    return arr;
}
