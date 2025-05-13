#pragma once
#include <vector>

std::vector<int> generate_array(size_t size, const int min, const int max);
std::vector<int> generate_array_sorted(size_t size, int min, int max, bool reversed = false);