#include <stdio.h>

int main() {
    int width = 20, height = 20;

    float x1 = 0.1, x2 = 0.8, y1 = 0.2, y2 = 0.5;

    for (unsigned int yi = 0; yi < height; ++yi) {
        for (unsigned int xi = 0; xi < width * 2; ++xi) {
            float x = 0.5 / width * xi, y = 1.0 / height * yi;
            if (x < x1 || x > x2 || y < y1 || y > y2) {
                printf(" ");
            } else {
                float slope21 = (y2 - y1) / (x2 - x1);
                if ((x - x1) * slope21 > y - y1)
                    printf(".");
                else
                    printf("O");
            }
        }
        printf("\n");
    }
}
