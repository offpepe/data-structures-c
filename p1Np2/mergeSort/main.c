#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // create temporary arrays
    int L[n1], R[n2];

    // copy data to temporary arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // merge the two arrays
    int k = left;
    i = 0;
    j = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // copy the remaining elements of L[], if there are any
    while (i < n1)
        arr[k++] = L[i++];

    // copy the remaining elements of R[], if there are any
    while (j < n2)
        arr[k++] = R[j++];
}

void parallel_merge_sort(int arr[], int start, int end) {
    const int maxThreads = omp_get_max_threads();
    if (maxThreads == 1) {
        if (start >= end) return;
        int mid = (start + end) / 2;
        #pragma omp parallel sections
        {
            #pragma omp section
            {
                parallel_merge_sort(arr, start, mid);
            }
            #pragma omp section
            {
                parallel_merge_sort(arr, mid + 1, end);
            }
        }
    } else {
        if (start >= end) return;
        int mid = (start + end) / 2;

        #pragma omp parallel
        {
            int tid = omp_get_thread_num();
            if (tid == 0)
                parallel_merge_sort(arr, start, mid);
            else if (tid == 1)
                parallel_merge_sort(arr, mid + 1, end);

        }

        merge(arr, start, mid, end);
    }
}

void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++)
        printf("%d, ", arr[i]);
    printf("]\n");
}

int main() {
    const int n = 1000000;
    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }

    clock_t start = clock();
    parallel_merge_sort(arr, 0, n - 1);
    clock_t end = clock();
    printf("RESULT: ");
    printArray(arr, n);
    free(arr);
    printf("Total time taken: %.2f seconds\n", ((double) (end - start)) / CLOCKS_PER_SEC);
    return 0;
}

