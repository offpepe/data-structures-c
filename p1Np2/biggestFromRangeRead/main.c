#include<stdio.h>

int main() {
    int size, actual;
    int times = 0;
    int biggest = 0;
    scanf("%d", &size);
    for(; size > 0; size--) {
        scanf("%d", &actual);
        if (actual == biggest) {
            times++;
            continue;
        }
        if (actual < biggest) continue;
        biggest = actual;
        times = 1;
    }
    printf("%d %d\n", biggest, times);
}