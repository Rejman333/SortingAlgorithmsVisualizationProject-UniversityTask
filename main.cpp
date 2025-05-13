#include "headers/tools.h"
#include "headers/sorting_algorithms.h"
#include "headers/visuals.h"
#include <iostream>
#include <chrono>
#include <fstream>
#include <filesystem>

void print_menu() {
    std::cout << "\n=== Sorting Visualizer ===\n\n";
    std::cout << "Choose a sorting algorithm to visualize:\n";
    std::cout << "1. Insertion Sort \n";
    std::cout << "2. Selection Sort \n";
    std::cout << "3. Bubble Sort \n";
    std::cout << "4. Quick Sort \n";
    std::cout << "5. Shell Sort \n";
    std::cout << "6. Heap Sort \n";
    std::cout << "------------------------------\n";
    std::cout << "7. Run sorting algorithm analysis (benchmark mode)\n";
    std::cout << "0. Exit\n";
    std::cout << "\nEnter your choice: ";
}

int get_menu_option() {
    int option;
    while (true) {
        std::cin >> option;
        if (std::cin.fail() || option < 0 || option > 7) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Please enter a number between 0 and 7: ";
        } else {
            return option;
        }
    }
}

double measure_sort_time(void (*sort_func)(std::vector<int> &), const std::vector<int> &data) {
    std::vector<int> copy = data;
    auto start = std::chrono::high_resolution_clock::now();
    sort_func(copy);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double>(end - start).count();
}

void benchmark_sorting_algorithms() {
    std::vector<std::string> sort_names = {
        "insertion_sort",
        "selection_sort",
        "bubble_sort",
        "quick_sort",
        "shell_sort",
        "heap_sort"
    };

    std::vector<void(*)(std::vector<int>&)> sort_functions = {
        insertion_sort,
        selection_sort,
        bubble_sort,
        quick_sort,
        shell_sort,
        heap_sort
    };

    const std::vector<std::string> dataset_types = { "random", "sorted", "reversed" };
    const std::string base_dir = "results";

    auto benchmark_sizes = [](auto&& fn) {
        for (int size = 100; size <= 1000; size += 100) fn(size);
        for (int size = 2000; size <= 10000; size += 1000) fn(size);
        for (int size = 15000; size <= 100000; size += 5000) fn(size);
    };

    const int min_val = -100;
    const int max_val = 100;

    for (const auto& dataset_type : dataset_types) {
        std::string folder_path = base_dir + "/" + dataset_type;
        std::filesystem::create_directories(folder_path);  // Create folder if not exists

        std::cout << "Benchmarking: " << dataset_type << " arrays...\n";

        // Open files for all algorithms in this dataset type folder
        std::vector<std::ofstream> files;
        for (const auto& name : sort_names) {
            std::string filename = folder_path + "/" + name + ".csv";
            std::ofstream f(filename);
            f << "array_size,time_seconds\n";
            files.push_back(std::move(f));
        }

        // Run for each size
        benchmark_sizes([&](int size) {
            std::vector<int> base_array;
            if (dataset_type == "random")
                base_array = generate_array(size, min_val, max_val);
            else if (dataset_type == "sorted")
                base_array = generate_array_sorted(size, min_val, max_val, false);
            else
                base_array = generate_array_sorted(size, min_val, max_val, true);

            for (size_t i = 0; i < sort_functions.size(); ++i) {
                double elapsed = measure_sort_time(sort_functions[i], base_array);
                files[i] << size << "," << elapsed << "\n";
            }
        });

        for (auto& f : files) f.close();
    }

    std::cout << "Benchmark complete. CSV files saved in folders under 'results/'.\n";
}


int main() {
    while (true) {
        print_menu();
        int option = get_menu_option();

        std::vector<int> array = generate_array_sorted(NUM_BARS, 10, SCREEN_HEIGHT - 10, true);
        switch (option) {
            case 1:
                insertion_sort_visual(array);
                break;
            case 2:
                selection_sort_visual(array);
                break;
            case 3:
                bubble_sort_visual(array);
                break;
            case 4:
                quick_sort_visual(array);
                break;
            case 5:
                shell_sort_visual(array);
                break;
            case 6:
                heap_sort_visual(array);
                break;
            case 7:
                benchmark_sorting_algorithms();
                break;
            case 0:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Unknown option.\n";
                return 1;
        }
    }
}
