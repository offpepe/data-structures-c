#include <stdio.h>
#include <time.h>


int main() {
    int age, year;
    printf("Digite a sua idade: ");
    scanf("%d", &age);
    printf("Digite o ano atual: ");
    setbuffer(stdin, NULL, 0);
    scanf("%d", &year);
    printf("Ano de nascimento: %d \n", year - age);
    return 0;
}