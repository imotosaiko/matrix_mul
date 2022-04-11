#include "matrix_mul.h"


void rand_matrix(matrix_t matrix,               \
                 const dim_t num_elements) {
    for (dim_t i = 0; i < num_elements; i++) {
        matrix[i] = rand() % ELEMENT_MAX;
    }
}


void disp_matrix(const char* name,                      \
                 const matrix_t matrix,                 \
                 const dim_t m, const dim_t n) {
    puts(name);
    for (dim_t i = 0; i < m; i++) {
        for (dim_t j = 0; j < n; j++) {
            printf("%d ", matrix[i * n + j]);
        }
        puts("");
    }
    puts("");
}


void matrix_mul(matrix_t matrix_r,              \
                matrix_t matrix1,               \
                matrix_t matrix2,               \
                dim_t m, dim_t n, dim_t k) {
    for (dim_t i1 = 0; i1 < m; i1++) {
        for (dim_t i2 = 0; i2 < k; i2 += 4) {
            /* malloc initliaze memory to 0 by default
             *
             * C[i1][i2] = 0
             * C[i1][i2 + 1] = 0
             * C[i1][i2 + 2] = 0
             * C[i1][i2 + 3] = 0
             */
            for (dim_t i3 = 0; i3 < n; i3++) {
                // C[i1][i2] += A[i1][i3] * B[i3][i2]
                matrix_r[i1 * k + i2] +=    \
                    matrix1[i1 * n + i3] *  \
                    matrix2[i3 * k + i2];
                // C[i1][i2 + 1] += A[i1][i3] * B[i3][i2 + 1]
                matrix_r[i1 * k + i2 + 1] +=    \
                    matrix1[i1 * n + i3] *      \
                    matrix2[i3 * k + i2 + 1];
                // C[i1][i2 + 2] += A[i1][i3] * B[i3][i2 + 2]
                matrix_r[i1 * k + i2 + 2] +=    \
                    matrix1[i1 * n + i3] *      \
                    matrix2[i3 * k + i2 + 2];
                // C[i1][i2 + 3] += A[i1][i3] * B[i3][i2 + 3]
                matrix_r[i1 * k + i2 + 3] +=    \
                    matrix1[i1 * n + i3] *      \
                    matrix2[i3 * k + i2 + 3];
            }
        }
    }
}

