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

void finish_animation(const std::vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        BeginDrawing();
        ClearBackground(BLACK); // lub inny kolor tła

        for (int j = 0; j < arr.size(); j++) {
            Color color = (j <= i) ? GREEN : WHITE;
            DrawRectangle(j * BAR_WIDTH, SCREEN_HEIGHT - arr[j], BAR_WIDTH - 1, arr[j], color);
        }

        EndDrawing();
    }

    // Zatrzymaj animację końcową do zamknięcia okna
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        for (int j = 0; j < arr.size(); j++) {
            DrawRectangle(j * BAR_WIDTH, SCREEN_HEIGHT - arr[j], BAR_WIDTH - 1, arr[j], GREEN);
        }
        EndDrawing();
    }

    CloseWindow();
}
