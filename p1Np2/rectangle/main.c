#include<stdio.h>

double sqrt(double x) {
    if (x < 2) {
        return x;
    }
    double precision = 0.000001;
    double half = x /2;
    while (half * half - x > precision || x - half * half > precision) {
        half = (half + x / half) / 2;
    }
    return half;
}

struct Point {
    float X;
    float Y;
};

struct Rect {
    struct Point upperLeft;
    struct Point lowerRight;
};

int main() {
    const struct Rect rect;
    scanf("%f %f %f %f", &rect.upperLeft.X, &rect.upperLeft.Y, &rect.lowerRight.X, &rect.lowerRight.Y);
    setbuf(stdin, NULL);
    const float l = rect.lowerRight.X - rect.upperLeft.X;
    const float h = rect.upperLeft.Y - rect.lowerRight.Y;
    float area = l * h;
    double diagonal = sqrt(l*l + h*h);
    printf("%d %d\n",(int) area,(int) diagonal);
}