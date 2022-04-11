#ifndef MATRIX_MUL_H
#define MATRIX_MUL_H

#include <stdlib.h>
#include <stdio.h>

typedef int element_t;
typedef element_t* matrix_t;
typedef unsigned short dim_t;

#define ELEMENT_MAX 255

#define new_matrix(num_elements) malloc(sizeof(element_t) * num_elements)

void rand_matrix(matrix_t matrix,               \
                 const dim_t num_elements);

void disp_matrix(const char* name,                      \
                 const matrix_t matrix,                 \
                 const dim_t m, const dim_t n);

void matrix_mul(matrix_t matrix_r,              \
                matrix_t matrix1,               \
                matrix_t matrix2,               \
                dim_t m, dim_t n, dim_t k);

#endif
