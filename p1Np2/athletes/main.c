#include<stdio.h>

#define MAX_NAME_SIZE 254
#define MAX_SPORT_SIZE 50
#define N_ATHLETES 3

struct athlete {
    unsigned int age;
    float height;
    char name[MAX_NAME_SIZE];
    char sport[MAX_SPORT_SIZE];
};

int main() {
    int i;
    int older = 0;
    int taller = 0;
    struct athlete athletes[N_ATHLETES];
    for (i = 0; i < N_ATHLETES; i++) {
        printf("nome: ");
        fgets(athletes[i].name, MAX_NAME_SIZE, stdin);
        setbuf(stdin, NULL);
        printf("idade: ");
        scanf("%d", &athletes[i].age);
        setbuf(stdin, NULL);
        printf("altura: ");
        scanf("%f", &athletes[i].height);
        setbuf(stdin, NULL);
        printf("esporte que pratica: ");
        fgets(athletes[i].sport, MAX_SPORT_SIZE, stdin);
        setbuf(stdin, NULL);
    }
    for (i = 0; i < N_ATHLETES; i++) {
        if (athletes[i].age > athletes[older].age) older = i;
        if (athletes[i].height > athletes[taller].height) taller = i;
    }
    printf("%s", athletes[taller].name);
    printf("%s", athletes[older].name);
}
