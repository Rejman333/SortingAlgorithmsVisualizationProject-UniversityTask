#pragma once
#include <vector>
#include <string>

void save_vector_to_file(const std::vector<int>& data, const std::string& filename);

std::vector<int> read_vector_from_file(const std::string& filename);