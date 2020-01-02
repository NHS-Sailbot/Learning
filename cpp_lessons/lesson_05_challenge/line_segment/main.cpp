#include <stdio.h>

int main() {
    int width = 20, height = 20;
    float x1 = 0.1, x2 = 0.4, y1 = 0.1, y2 = 0.8;

    float slope = (y2 - y1) / (x2 - x1) / 2;

    float min_x = x1, max_x = x2;
    float min_y = y1, max_y = y2;

    if (x2 < x1) min_x = x2, max_x = x1;
    if (y2 < y1) min_y = y2, max_y = y1;

    for (unsigned int yi = 0; yi < height; ++yi) {
        for (unsigned int xi = 0; xi < width * 2; ++xi) {
            float x = 0.5 / width * xi, y = 1.0 / height * yi;
            if (x < min_x || x > max_x || y < min_y || y > max_y) {
                printf(" ");
            } else {
                if (slope > 1 || slope < -1) {
                    if (int(xi - x1 * width * 2 + 0.5) == int((yi - y1 * width) / slope + 0.5))
                        printf("#");
                    else
                        printf(" ");
                } else {
                    if (int(slope * (xi - x1 * width * 2) + 0.5) == int(yi - y1 * width + 0.5))
                        printf("#");
                    else
                        printf(" ");
                }
            }
        }
        printf("\n");
    }
}
