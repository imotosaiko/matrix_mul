#include <stdio.h>
#include <time.h>

#include "matrix_mul.h"

#define REPEAT_TIMES 10
// #define VERBOSE

int main() {
    dim_t m, n, k;
    puts("Please enter three nums: ");
    scanf("%d %d %d", &m, &n, &k);
    matrix_t matrix1 = new_matrix(m * n);
    matrix_t matrix2 = new_matrix(n * k);
    matrix_t matrix_r = new_matrix(m * k);
    rand_matrix(matrix1, m * n);
    rand_matrix(matrix2, n * k);

    clock_t start, end;
    double average_time;
    start = clock();
    for (size_t i = 0; i < REPEAT_TIMES; i++) {
        matrix_mul(matrix_r, matrix1, matrix2, m, n, k);
    }
    end = clock();
    average_time = ((double)(end - start) / CLOCKS_PER_SEC) / REPEAT_TIMES;
    printf("run completed!\n"
           "run times: %d\n"
           "average time: %f\n", REPEAT_TIMES, average_time);

#ifdef VERBOSE
    disp_matrix("matrix1", matrix1, m, n);
    disp_matrix("matrix2", matrix2, n, k);
    disp_matrix("matrix_r", matrix_r, m, k);
#endif

    free(matrix1);
    free(matrix2);
    free(matrix_r);
    
    return 0;
}
