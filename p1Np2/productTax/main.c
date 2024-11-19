#include <stdio.h>

#define A 0.07;
#define B 0.12;
#define C 0.15;
#define D 0.08;

int main() {
    float value, tax;
    char type;
    printf("Insira o valor do produto: ");
    scanf("%f", &value);
    setbuffer(stdin, NULL, 0);
    printf("Insira o tipo do produto: ");
    scanf("%c", &type);
    switch (type) {
        case 'A': tax = value * A; break;
        case 'B': tax = value * B; break;
        case 'C': tax = value * C; break;
        case 'D': tax = value * D; break;
        default: printf("Produto não encontrado.\n"); return -1;
    }
    printf("O valor acrescido de imposto é: %.4f \n", value + tax);
    return 0;
}