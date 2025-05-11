#include "headers/tools.h"
#include "headers/sorting_algorithms.h"
#include "headers/visuals.h"
#include <iostream>

int main() {
    std::vector<int> array = generate_array(NUM_BARS, 10, SCREEN_HEIGHT - 10);
    heap_sort_visual(array);

    // std::vector<int> array = {3, 2, 1, 7, 6, 5, 4};
    // heap_sort(array);
    // for(auto num : array) {
    //     std::cout<<num<<std::endl;
    // }
    return 0;
}
