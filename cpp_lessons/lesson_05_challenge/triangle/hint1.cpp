#include <stdio.h>

int main() {
    int width = 20, height = 20;
    float x1 = 0.1, x2 = 0.8, x3 = 0.4, y1 = 0.1, y2 = 0.3, y3 = 0.9;

    for (unsigned int yi = 0; yi < height; ++yi) {
        for (unsigned int xi = 0; xi < width * 2; ++xi) {
            printf(".");
        }
        printf("\n");
    }
}
