#include <stdio.h>

#define STUDENTS 10
#define EXAMS 3

int main() {
    float grades[STUDENTS][EXAMS];
    int worst_exam[EXAMS] = {0};
    int i, j, min_index;
    float min_grade;
    // Read grades
    // for (i = 0; i < STUDENTS; i++) {
    //     for (j = 0; j < EXAMS; j++) {
    //         scanf("%f", &grades[i|[j]);
    //     }
    // }
    // Find worst exam for each student
    for (i = 0; i < STUDENTS; i++) {
        min_grade = grades[i][0];
        min_index = 0;
        for (j = 1; j < EXAMS; j++) {
            if (grades[i][j] < min_grade) {
                min_grade = grades[i][j];
                min_index = j;
            }
        }
        worst_exam[min_index]++;
    }

    // Print results
    printf("%d %d %d\n", worst_exam[0], worst_exam[1], worst_exam[2]);

    return 0;
}