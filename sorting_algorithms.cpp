#include "headers/sorting_algorithms.h"
#include "headers/visuals.h"
/*
II grupa metod:
	Sortowanie przez kopcowanie    Heap Sort
 */

//How to dell with sentinel value?
void insertion_sort(std::vector<int> &to_sort) {
    to_sort.insert(to_sort.begin(), 0);
    for (int i = 2; i < to_sort.size(); i++) {
        const int elem = to_sort[i];
        int j = i - 1;
        to_sort[0] = elem; //Sentinel for better performance
        while (to_sort[j] > elem) {
            to_sort[j + 1] = to_sort[j];
            j--;
        }
        to_sort[j + 1] = elem;
    }
    to_sort.erase(to_sort.begin());
}

void insertion_sort_visual(std::vector<int> &to_sort) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Insertion Sort Visualizer");
    SetTargetFPS(TARGET_FPS);

    to_sort.insert(to_sort.begin(), 0);
    for (int i = 2; i < to_sort.size(); i++) {
        const int elem = to_sort[i];
        int j = i - 1;
        to_sort[0] = elem; //Sentinel for better performance
        BeginDrawing();
        draw_array(to_sort, i - 1, i);

        while (to_sort[j] > elem) {
            to_sort[j + 1] = to_sort[j];
            j--;

            BeginDrawing();
            draw_array(to_sort, j, j + 1);
        }
        to_sort[j + 1] = elem;
    }
    to_sort.erase(to_sort.begin());

    finish_animation(to_sort);
}

void selection_sort(std::vector<int> &to_sort) {
    for (int i = 0; i < to_sort.size(); i++) {
        int min_idx = i;
        for (int j = i + 1; j < to_sort.size(); j++) {
            if (to_sort[min_idx] > to_sort[j]) min_idx = j;
        }
        if (min_idx != i) std::swap(to_sort[i], to_sort[min_idx]);
    }
}

void selection_sort_visual(std::vector<int> &to_sort) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Selection Sort Visualizer");
    SetTargetFPS(TARGET_FPS);

    for (int i = 0; i < to_sort.size(); i++) {
        int min_idx = i;
        for (int j = i + 1; j < to_sort.size(); j++) {
            if (to_sort[min_idx] > to_sort[j]) min_idx = j;
            BeginDrawing();
            draw_array(to_sort, min_idx, j);
        }
        if (min_idx != i) {
            std::swap(to_sort[i], to_sort[min_idx]);
        }
    }

    finish_animation(to_sort);
}

void bubble_sort(std::vector<int> &to_sort) {
    size_t end = to_sort.size();
    if (end <= 1) return;
    bool was_swap;

    do {
        was_swap = false;
        for (int i = 1; i < end; i++) {
            if (to_sort[i - 1] > to_sort[i]) {
                std::swap(to_sort[i - 1], to_sort[i]);
                was_swap = true;
            }
        }
        end--;
    } while (was_swap);
}

void bubble_sort_visual(std::vector<int> &to_sort) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bubble Sort Visualizer");
    SetTargetFPS(TARGET_FPS);

    size_t end = to_sort.size();
    if (end <= 1) return;
    bool was_swap;

    do {
        was_swap = false;
        for (int i = 1; i < end; i++) {
            BeginDrawing();
            draw_array(to_sort, i - 1, i);
            if (to_sort[i - 1] > to_sort[i]) {
                std::swap(to_sort[i - 1], to_sort[i]);
                was_swap = true;
            }
        }
        end--;
    } while (was_swap);

    finish_animation(to_sort);
}

size_t partition(std::vector<int> &to_sort, size_t start, size_t end) {
    int pivot = to_sort[end];
    size_t i = start;

    for (auto j = start; j < end; j++) {
        if (to_sort[j] < pivot) {
            std::swap(to_sort[i], to_sort[j]);
            i++;
        }
    }
    std::swap(to_sort[i], to_sort[end]);

    return i;
}

void quick_sort_recursive(std::vector<int> &to_sort, size_t start, size_t end) {
    if (end <= start) return; //base case
    size_t pivot_index = partition(to_sort, start, end);
    if (pivot_index > 0) quick_sort_recursive(to_sort, start, pivot_index - 1);
    quick_sort_recursive(to_sort, pivot_index + 1, end);
}

void quick_sort(std::vector<int> &to_sort) {
    quick_sort_recursive(to_sort, 0, to_sort.size() - 1);
}

size_t partition_visual(std::vector<int> &to_sort, size_t start, size_t end) {
    int pivot = to_sort[end];
    size_t i = start;

    for (auto j = start; j < end; j++) {
        BeginDrawing();
        draw_array(to_sort, j, i);
        if (to_sort[j] < pivot) {
            std::swap(to_sort[i], to_sort[j]);
            i++;
        }
    }
    std::swap(to_sort[i], to_sort[end]);

    return i;
}

void quick_sort_recursive_visual(std::vector<int> &to_sort, size_t start, size_t end) {
    if (end <= start) return; //base case
    size_t pivot_index = partition_visual(to_sort, start, end);
    if (pivot_index > 0) quick_sort_recursive_visual(to_sort, start, pivot_index - 1);
    quick_sort_recursive_visual(to_sort, pivot_index + 1, end);
}

void quick_sort_visual(std::vector<int> &to_sort) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Quick Sort");
    SetTargetFPS(TARGET_FPS);

    quick_sort_recursive_visual(to_sort, 0, to_sort.size() - 1);

    finish_animation(to_sort);
}

void shell_sort(std::vector<int> &to_sort) {
    size_t n = to_sort.size();

    for (size_t gap = n / 2; gap > 0; gap = gap / 2) {
        for (size_t i = gap; i < n; i++) {
            int temp = to_sort[i];
            size_t j;
            for (j = i; j >= gap && to_sort[j - gap] > temp; j -= gap) {
                to_sort[j] = to_sort[j - gap];
            }
            to_sort[j] = temp;
        }
    }
}

void shell_sort_visual(std::vector<int> &to_sort) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Shell Sort Visualizer");
    SetTargetFPS(TARGET_FPS);

    size_t n = to_sort.size();

    for (size_t gap = n / 2; gap > 0; gap = gap / 2) {
        for (size_t i = gap; i < n; i++) {
            int temp = to_sort[i];
            size_t j;
            for (j = i; j >= gap && to_sort[j - gap] > temp; j -= gap) {
                to_sort[j] = to_sort[j - gap];
                BeginDrawing();
                draw_array(to_sort, j, j - gap);
            }
            to_sort[j] = temp;
        }
    }

    finish_animation(to_sort);
}

void heapify(std::vector<int>& to_sort, size_t n, size_t i) {
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < n && to_sort[left] > to_sort[largest])
        largest = left;

    if (right < n && to_sort[right] > to_sort[largest])
        largest = right;

    if (largest != i) {
        std::swap(to_sort[i], to_sort[largest]);
        heapify(to_sort, n, largest);
    }
}

void build_max_heap(std::vector<int>& to_sort) {
    size_t arr_size = to_sort.size();
    if (arr_size < 2) return;

    for (size_t i = arr_size / 2; i-- > 0; ) {
        heapify(to_sort, arr_size, i);
    }
}

void heap_sort(std::vector<int>& to_sort) {
    build_max_heap(to_sort);

    for (size_t i = to_sort.size() - 1; i > 0; i--) {
        std::swap(to_sort[0], to_sort[i]);
        heapify(to_sort, i, 0);
    }
}

void heapify_visual(std::vector<int>& to_sort, size_t n, size_t i) {
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < n && to_sort[left] > to_sort[largest])
        largest = left;

    if (right < n && to_sort[right] > to_sort[largest])
        largest = right;

    if (largest != i) {
        std::swap(to_sort[i], to_sort[largest]);
        BeginDrawing();
        draw_array(to_sort, i, largest);


        heapify_visual(to_sort, n, largest);
    }
}

void build_max_heap_visual(std::vector<int>& to_sort) {
    size_t arr_size = to_sort.size();
    if (arr_size < 2) return;

    for (size_t i = arr_size / 2; i-- > 0; ) {
        heapify_visual(to_sort, arr_size, i);
    }
}

void heap_sort_visual(std::vector<int> &to_sort) {
    if (to_sort.size() <= 1) return;
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Heap Sort Visualizer");
    SetTargetFPS(TARGET_FPS);

    build_max_heap_visual(to_sort);

    for (size_t i = to_sort.size() - 1; i > 0; i--) {
        std::swap(to_sort[0], to_sort[i]);
        heapify_visual(to_sort, i, 0);
    }

    finish_animation(to_sort);

}
