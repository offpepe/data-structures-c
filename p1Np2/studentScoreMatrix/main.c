#include <stdio.h>

#define TOTAL_TESTS 3
#define TOTAL_STUDENTS 10


int main() {
    int i, j, worstScore, minIdx;
    float studentMatrix[TOTAL_STUDENTS][TOTAL_TESTS];
    int totalWorstScores[] = { 0, 0, 0 };
    for (i = 0; i < 10; i++) {
         for (j = 0; j < 3; j++) {
             scanf("%f", &studentMatrix[i][j]);
         }
    }
    for (i = 0; i < TOTAL_STUDENTS; i ++) {
        worstScore = studentMatrix[i][0];
        minIdx = 0;
        for (j = 0; j < TOTAL_TESTS; j++) {
            if (studentMatrix[i][j] < worstScore) {
                worstScore = studentMatrix[i][j];
                minIdx = j;
            }
        }
        totalWorstScores[minIdx]++;
    }
    printf("%d %d %d\n", totalWorstScores[0], totalWorstScores[1], totalWorstScores[2]);
    return 0;
}