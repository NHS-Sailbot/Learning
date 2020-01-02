#include <stdio.h>

int main() {
    int width = 20, height = 20;

    for (unsigned int yi = 0; yi < height; ++yi) {
        for (unsigned int xi = 0; xi < width * 2; ++xi) {
            float x = 0.5 / width * xi, y = 1.0 / height * yi;
            if (x > y)
                printf(".");
            else
                printf(" ");
        }
        printf("\n");
    }
}
