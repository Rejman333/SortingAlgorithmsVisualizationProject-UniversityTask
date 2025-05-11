#include "headers/tools.h"
#include "headers/sorting_algorithms.h"
#include "headers/visuals.h"
#include <iostream>

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

int main() {
    while (true) {
        print_menu();
        int option = get_menu_option();

        std::vector<int> array = generate_array(NUM_BARS, 10, SCREEN_HEIGHT - 10);
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
                quick_sort_visual(array, 0, array.size() - 1);
                break;
            case 5:
                shell_sort_visual(array);
                break;
            case 6:
                heap_sort_visual(array);
                break;
            case 7:
                // benchmark_all(); // <-- musisz zdefiniować tę funkcję sam
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
