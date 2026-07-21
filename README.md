# SortingAlgorithmsVisualizationProject – University Task

This project is a C++ console application designed for educational purposes, allowing users to visualize and benchmark classic sorting algorithms.
It was developed as a university assignment to combine algorithm understanding with performance analysis and basic UI design.

### Features

- **Interactive console menu** to select algorithms.
- **Visual representation** of sorting algorithms in action:
  - Insertion Sort
  - Selection Sort
  - Bubble Sort
  - Quick Sort
  - Shell Sort
  - Heap Sort
- **Benchmarking mode**:
  - Measures and logs execution time of all sorting algorithms.
  - Tests on multiple array types: `random`, `sorted`, `reversed`.
  - Saves results as `.csv` files inside the `results/` directory.

### Benchmarking mode (option 7) generates .csv files in:
```
results/
├── random/
├── sorted/
└── reversed/
```
Each folder contains timing results for all sorting algorithms, useful for plotting graphs or comparing performance.

## Demo

![Sort](media/sort.gif)


## How to Run

This project was developed using **JetBrains CLion**, which uses **CMake** as its build system.

### Run in CLion (recommended):

1. Open the project folder in CLion.
2. CLion will automatically detect the `CMakeLists.txt` file and configure the project.
3. Press **Shift + F10** (or click the green ▶️ button) to build and run the project.

### Alternative (manual build):

If you prefer to build manually using the terminal (with CMake installed):

```bash
mkdir build
cd build
cmake ..
cmake --build .
./SortingAlgorithmsVisualizationProject
