#include <stdio.h>

int main() {
    int n, i, j, isUnique, totalUnique = 0;
    scanf("%d", &n);
    if (n > 100 || n < 0) {
        printf("Tamanho inválido");
        return -1;
    }
    int vec[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &vec[i]);
    }
    for (i = 0; i < n; i++) {
        isUnique = 1;
        j = i + 1;
        if (j == n) j = 0;
        while (j != i) {
            if (vec[i] == vec[j]) {
                isUnique = 0;
                break;
            }
            j++;
            if (j == n) j = 0;
        }
        if (isUnique) totalUnique++;
    }
    printf("%d\n", totalUnique);
}