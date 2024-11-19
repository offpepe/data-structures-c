#include <stdio.h>
void imprimirArraysDePonteiros(int **arrayDePonteiros, int numArrays, int tamanhoArray) {
    printf("Arrays Originais:\n");
    for (int i = 0; i < numArrays; i++) {
        for (int j = 0; j < tamanhoArray; j++) {
            printf("%d ", *(*(arrayDePonteiros + i) + j));
        }
        printf("\n");
    }
}
int main() {
    int array1[] = {1, 2, 3};
    int array2[] = {4, 5, 6};
    int array3[] = {7, 8, 9};
    int *arrayDePonteiros[] = {array1, array2, array3};
    imprimirArraysDePonteiros(arrayDePonteiros, 3, 3);
    return 0;
}