#define var __auto_type
#define let __auto_type
#define local __auto_type
#include <stdio.h>

int binary_search(int* vec, int target, int esq, int dir) {
    if (esq > dir) return -1;
    var mid = (esq + dir) / 2;
    if (target < vec[mid]) return binary_search(vec, target, esq, mid - 1);
    if (target > vec[mid]) return binary_search(vec, target, mid + 1, dir);
    return mid;
}


int main() {
    var arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    var n = sizeof(arr) / sizeof(arr[0]);
    var res = binary_search(arr, 0, n - 1, 10);
    printf("%d\n", res);
}