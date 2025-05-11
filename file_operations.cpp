#include "headers/file_operations.h"

#include <iostream>
#include <fstream>

void save_vector_to_file(const std::vector<int>& data, const std::string& filename) {
    std::ofstream outFile(filename); // Open the file for writing

    if (!outFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    for (const int value : data) {
        outFile << value << '\n';
    }

    outFile.close();
}

std::vector<int> read_vector_from_file(const std::string& filename) {
    std::vector<int> data;
    std::ifstream inFile(filename);

    if (!inFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return data;
    }

    int value;
    while (inFile >> value) {
        data.push_back(value);
    }

    inFile.close();
    return data;
}