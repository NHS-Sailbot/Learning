#include <stdio.h>

int main() {
    int width = 20, height = 20;
    float x1 = 0.1, x2 = 0.8, x3 = 0.4, y1 = 0.1, y2 = 0.3, y3 = 0.9;
    float slope21 = (y2 - y1) / (x2 - x1);
    float slope31 = (y3 - y1) / (x3 - x1);
    float slope32 = (y3 - y2) / (x3 - x2);

    for (unsigned int yi = 0; yi < height; ++yi) {
        for (unsigned int xi = 0; xi < width * 2; ++xi) {
            float x = 0.5 / width * xi, y = 1.0 / height * yi;
            if ((x - x1) * slope21 > y - y1 || //
                (x - x1) * slope31 < y - y1 || //
                (x - x2) * slope32 < y - y2    //
            )
                printf(".");
            else
                printf("O");
        }
        printf("\n");
    }
}
