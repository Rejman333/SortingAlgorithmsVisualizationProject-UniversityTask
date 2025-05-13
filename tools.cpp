#include "headers/tools.h"

#include <iostream>
#include <random>
#include <algorithm>

std::vector<int> generate_array(size_t size, const int min, const int max) {
    std::vector<int> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);

    for (int &val: arr) {
        val = dist(gen);
    }
    return arr;
}

std::vector<int> generate_array_sorted(size_t size, int min, int max, bool reversed) {
    std::vector<int> arr(size);

    if (size == 0) return arr;

    double step = static_cast<double>(max - min) / (size - 1);

    for (size_t i = 0; i < size; ++i) {
        arr[i] = static_cast<int>(min + i * step);
    }

    if (reversed) {
        std::reverse(arr.begin(), arr.end());
    }

    return arr;
}

