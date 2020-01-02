#include <stdio.h>

bool side(float x, float y, float x1, float x2, float y1, float y2) { return (x - x1) * (y2 - y1) / (x2 - x1) > y - y1; }

int main() {
    int width = 20, height = 20;
    float x1 = 0.1, x2 = 0.8, x3 = 0.4, y1 = 0.1, y2 = 0.3, y3 = 0.9;

    for (unsigned int i = 0; i < 1000; ++i) {
        for (unsigned int yi = 0; yi < height; ++yi) {
            float y = 1.0 / height * yi;
            for (unsigned int xi = 0; xi < width * 2; ++xi) {
                float x = 0.5 / width * xi;

                bool c1 = side(x, y, x1, x2, y1, y2);
                if (side(x3, y3, x1, x2, y1, y2)) c1 = !c1;
                bool c2 = side(x, y, x1, x3, y1, y3);
                if (side(x2, y2, x1, x3, y1, y3)) c2 = !c2;
                bool c3 = side(x, y, x3, x2, y3, y2);
                if (side(x1, y1, x3, x2, y3, y2)) c3 = !c3;

                if (c1 || c2 || c3)
                    printf(".");
                else
                    printf("O");
            }
            printf("\n");
        }
    }
}
