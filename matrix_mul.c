#include <string.h>
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
        for (dim_t i2 = 0; i2 < n; i2++) {
            
            for (dim_t i3 = 0; i3 < k; i3++) {
                /* malloc initliaze memory to 0 by default
                 *
                 * C[i1][i3] += A[i1][i2] * B[i2][i3]
                 *
                 */
                matrix_r[i1 * k + i3] +=    \
                    matrix1[i1 * n + i2] *  \
                    matrix2[i2 * k + i3];
            }
        }
    }
}


void matrix_add(matrix_t matrix_r,              \
                matrix_t matrix1,               \
                matrix_t matrix2,               \
                dim_t m, dim_t n) {
    matrix_t matrix_r_p = matrix_r;        
    matrix_t matrix_r_end = matrix_r + m*n;
    matrix_t matrix1_p = matrix1;
    matrix_t matrix2_p = matrix2;
    while (matrix_r_p < matrix_r_end) {
        *matrix_r_p = *matrix1_p + *matrix2_p;
        matrix_r_p++;   
        matrix1_p++;
        matrix2_p++;
    }                                            
}


void matrix_sub(matrix_t matrix_r,              \
                matrix_t matrix1,               \
                matrix_t matrix2,               \
                dim_t m, dim_t n) {
    matrix_t matrix_r_p = matrix_r;        
    matrix_t matrix_r_end = matrix_r + m*n;
    matrix_t matrix1_p = matrix1;
    matrix_t matrix2_p = matrix2;
    while (matrix_r_p < matrix_r_end) {
        *matrix_r_p = *matrix1_p - *matrix2_p;
        matrix_r_p++;   
        matrix1_p++;
        matrix2_p++;
    }                                            
}


void part_matrix(matrix_t matrix,               \
                 matrix_t sub_matrix11,         \
                 matrix_t sub_matrix12,         \
                 matrix_t sub_matrix21,         \
                 matrix_t sub_matrix22,         \
                 dim_t n) {
    for (dim_t i = 0; i < n; i++) {
        for (dim_t j = 0; j < n; j++) {
            *(sub_matrix11 + i * n + j) =       \
                *(matrix + i * 2 * n + j);
            *(sub_matrix12 + i * n + j) =       \
                *(matrix + i * 2 * n + j + n);
            *(sub_matrix21 + i * n + j) =               \
                *(matrix + (i + n) * 2 * n + j);
            *(sub_matrix22 + i * n + j) =               \
                *(matrix + (i + n) * 2 * n + j + n);
        }
        
    }
}


void comb_matrix(matrix_t matrix,                        \
                 matrix_t sub_matrix11,                  \
                 matrix_t sub_matrix12,                  \
                 matrix_t sub_matrix21,                  \
                 matrix_t sub_matrix22,                  \
                 dim_t n) {
    for (dim_t i = 0; i < n; i++) {
        for (dim_t j = 0; j < n; j++) {
            *(matrix + i * 2 * n + j) =         \
                *(sub_matrix11 + i * n + j);
            *(matrix + i * 2 * n + j + n) =     \
                *(sub_matrix12 + i * n + j);
            *(matrix + (i + n) * 2 * n + j) =   \
                *(sub_matrix21 + i * n + j);
            *(matrix + (i + n) * 2 * n + j + n) =       \
                *(sub_matrix22 + i * n + j);
        }
    }
}


void nearby_2_power(dim_t num, dim_t expanded_num) {  
    expanded_num = num;
    expanded_num -= 1;
    expanded_num |= expanded_num >> 16;
    expanded_num |= expanded_num >> 8;
    expanded_num |= expanded_num >> 4;
    expanded_num |= expanded_num >> 2;
    expanded_num |= expanded_num >> 1;
    expanded_num += 1;
}


void cw(matrix_t matrix_r, matrix_t matrix1, matrix_t matrix2, dim_t n) {
    if (n == 2) {
        matrix_mul(matrix_r, matrix1, matrix2, 4, 4, 4);
        return;
    }

    matrix_t a11 = malloc(sizeof(element_t) * n * n * 8);
    matrix_t a12 = a11 + n * n;
    matrix_t a21 = a12 + n * n;
    matrix_t a22 = a21 + n * n;
    part_matrix(matrix1, a11, a12, a21, a22, n);
    matrix_t b11 = a22 + n * n;
    matrix_t b12 = b11 + n * n;
    matrix_t b21 = b12 + n * n;
    matrix_t b22 = b21 + n * n;
    part_matrix(matrix2, b11, b12, b21, b22, n);
    
    matrix_t s1 = matrix1;
    matrix_t s2 = s1 + n * n;
    matrix_t s3 = s2 + n * n;
    matrix_t s4 = s3 + n * n;
    matrix_t t1 = matrix2;
    matrix_t t2 = t1 + n * n;
    matrix_t t3 = t2 + n * n;
    matrix_t t4 = t3 + n * n;
    
    matrix_add(s1, a21, a22, n, n);
    matrix_sub(s2, s1, a11, n, n);
    matrix_sub(s3, a11, a21, n, n);
    matrix_sub(s4, a12, s2, n, n);
    matrix_sub(t1, b12, b11, n, n);
    matrix_sub(t2, b22, t1, n, n);
    matrix_sub(t3, b22, b12, n, n);
    matrix_sub(t4, t2, b21, n, n);
    
    matrix_t m1 = a21;
    memset(m1, 0, sizeof(element_t) * n * n);
    cw(m1, a11, b11, n / 2);
    matrix_t m2 = a11;
    memset(m2, 0, sizeof(element_t) * n * n);
    cw(m2, a12, b21, n/2);
    matrix_t m3 = a12;
    memset(m3, 0, sizeof(element_t) * n * n);
    cw(m3, s4, b22, n/2);
    matrix_t m4 = s4;
    memset(m4, 0, sizeof(element_t) * n * n);
    cw(m4, a22, t4, n/2);
    matrix_t m5 = a22;
    memset(m5, 0, sizeof(element_t) * n * n);
    cw(m5, s1, t1, n/2);
    matrix_t m6 = s1;
    memset(m6, 0, sizeof(element_t) * n * n);
    cw(m6, s2, t2, n/2);
    matrix_t m7 = s2;
    memset(m7, 0, sizeof(element_t) * n * n);
    cw(m7, s3, t3, n/2);

    matrix_t u1 = b11;
    matrix_t u2 = b12;
    matrix_t u3 = b21;
    matrix_t u4 = b22;
    matrix_t u5 = s3;
    matrix_t u6 = s4;
    matrix_t u7 = t1;
   
    matrix_add(u1, m1, m2, n, n);
    matrix_add(u2, m1, m6, n, n);
    matrix_add(u3, u2, m7, n, n);
    matrix_add(u4, u2, m5, n, n);
    matrix_add(u5, u4, m3, n, n);
    matrix_sub(u6, u3, m4, n, n);
    matrix_add(u7, u3, m5, n, n);
    
    matrix_t c11 = u1;
    matrix_t c12 = u5;
    matrix_t c21 = u6;
    matrix_t c22 = u7;    
    comb_matrix(matrix_r, c11, c12, c21, c22, n);

    free(a11);
}
