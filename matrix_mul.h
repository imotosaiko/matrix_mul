#ifndef MATRIX_MUL_H
#define MATRIX_MUL_H

#include <stdlib.h>
#include <stdio.h>

typedef int element_t;
typedef element_t* matrix_t;
typedef unsigned int dim_t;

#define ELEMENT_MAX 255

#define new_matrix(num_elements) malloc(sizeof(element_t) * num_elements)

void rand_matrix(matrix_t matrix,               \
                 const dim_t num_elements);

void disp_matrix(const char* name,              \
                 const matrix_t matrix,         \
                 const dim_t m, const dim_t n);

void matrix_mul(matrix_t matrix_r,              \
                matrix_t matrix1,               \
                matrix_t matrix2,               \
                dim_t m, dim_t n, dim_t k);

void matrix_add (matrix_t matrix_r,             \
                 matrix_t matrix1,              \
                 matrix_t matrix2,              \
                 dim_t m, dim_t n);

void matrix_sub(matrix_t matrix_r,              \
                matrix_t matrix1,               \
                matrix_t matrix2,               \
                dim_t m, dim_t n);

void part_matrix(matrix_t matrix,               \
                 matrix_t sub_matrix11,         \
                 matrix_t sub_matrix12,         \
                 matrix_t sub_matrix21,         \
                 matrix_t sub_matrix22,         \
                 dim_t n);

void comb_matrix(matrix_t matrix,               \
                 matrix_t sub_matrix11,         \
                 matrix_t sub_matrix12,         \
                 matrix_t sub_matrix21,         \
                 matrix_t sub_matrix22,         \
                 dim_t n);

void nearby_2_power(dim_t num, dim_t expanded_num);

void cw(matrix_t matrix_r, matrix_t matrix1, matrix_t matrix2, dim_t n);

#endif
