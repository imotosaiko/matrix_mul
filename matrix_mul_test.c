#include <string.h>

#include "matrix_mul.h"


int main() {
    element_t m1[] = {163, 151, 162, 85, 83, 190, 241, 252, 249, 121, 107, 82, 20, 19, 233, 226};
    element_t m2[] = {45, 81, 142, 31, 86, 8, 87, 39, 167, 5, 212, 208, 82, 130, 119, 117};
    element_t m3[16];
    element_t expected[] = {54345, 26271, 80742, 54583, 80986, 42208, 109396, 89595, 46204, 32332, 78327, 44288, 59977, 32317, 80783, 76267};
    memset(m3, 0, sizeof(element_t) * 16);
    matrix_mul(m3, m1, m2, 4, 4, 4);
    if ((memcmp(m3, expected, sizeof(element_t) * 16)) != 0) {
        printf("test not pass, maybe you are wrong!\n");
        exit(1);
    } else {
        printf("test pass!\n");
    }
}
