#include <stdio.h>

struct P {
    float x, y;
};

static constexpr bool side(const float px, const float py, const float p1x, const float p1y, const float s) {
    return (px - p1x) * s > py - p1y;
}

static constexpr float slope(const float p1x, const float p1y, const float p2x, const float p2y) {
    return (p2y - p1y) / (p2x - p1x);
}

int main() {
    constexpr unsigned char width = 20, height = 20;
    constexpr float p1x = 0.1, p1y = 0.1, p2x = 0.8, p2y = 0.3, p3x = 0.4, p3y = 0.9;
    constexpr float m1 = slope(p1x, p1y, p2x, p2y), m2 = slope(p1x, p1y, p3x, p3y), m3 = slope(p2x, p2y, p3x, p3y);
    constexpr bool s1 = side(p3x, p3y, p1x, p1y, m1), s2 = side(p2x, p2y, p1x, p1y, m2), s3 = side(p1x, p1y, p2x, p2y, m3);
    float px, py;

    for (unsigned int i = 0; i < 50000; ++i) {
        for (unsigned int yi = 0; yi < height; ++yi) {
            py = 1.0 / height * yi;
            for (unsigned int xi = 0; xi < width * 2; ++xi) {
                px = 0.5 / width * xi;

                bool c1 = side(px, py, p1x, p1y, m1);
                if constexpr (s1) c1 = !c1;
                bool c2 = side(px, py, p1x, p1y, m2);
                if constexpr (s2) c2 = !c2;
                bool c3 = side(px, py, p2x, p2y, m3);
                if constexpr (s3) c3 = !c3;

                if (c1 || c2 || c3)
                    printf(".");
                else
                    printf("O");
            }
            printf("\n");
        }
    }
}
// 16712 bytes
// 3.255s
// 16.507s
// 3.386s
