#pragma once
#include <vector>
#include "raylib.h"

constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 600;
constexpr int NUM_BARS = 100;
constexpr int BAR_WIDTH = SCREEN_WIDTH / NUM_BARS;
constexpr int TARGET_FPS = 30;

void DrawArray(const std::vector<int> &arr, int highlight1 = -1, int highlight2 = -1);

