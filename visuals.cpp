#include "headers/visuals.h"


void draw_array(const std::vector<int> &arr, int highlight1, int highlight2) {
    ClearBackground(BLACK);
    for (int i = 0; i < arr.size(); i++) {
        auto color = WHITE;
        if (i == highlight1 || i == highlight2) color = RED;
        DrawRectangle(i * BAR_WIDTH, SCREEN_HEIGHT - arr[i], BAR_WIDTH - 1, arr[i], color);
    }
    EndDrawing();
}


