#include <string.h>
#include <stdbool.h>

#include "matrix_mul.h"

_Bool main_test() {
    element_t m1[] = {163, 151, 162, 85, 83, 190, 241, 252, 249, 121, 107, 82, 20, 19, 233, 226};
    element_t m2[] = {45, 81, 142, 31, 86, 8, 87, 39, 167, 5, 212, 208, 82, 130, 119, 117};
    element_t m3[16];
    element_t expected[] = {54345, 26271, 80742, 54583, 80986, 42208, 109396, 89595, 46204, 32332, 78327, 44288, 59977, 32317, 80783, 76267};
    memset(m3, 0, sizeof(element_t) * 16);
    matrix_mul(m3, m1, m2, 4, 4, 4);
    if ((memcmp(m3, expected, sizeof(element_t) * 16)) != 0) {
        return false;
    } else {
        return true;
    }
}

_Bool add_test() {
    element_t m1[] = {163, 151, 162, 85, 83, 190, 241, 252, 249, 121, 107, 82, 20, 19, 233, 226};
    element_t m2[] = {45, 81, 142, 31, 86, 8, 87, 39, 167, 5, 212, 208, 82, 130, 119, 117};
    element_t m3[16];
    element_t expected[] = {208, 232, 304, 116, 169, 198, 328, 291, 416, 126, 319, 290, 102, 149, 352, 343};
    memset(m3, 0, sizeof(element_t) * 16);
    matrix_add(m3, m1, m2, 4, 4);
    if ((memcmp(m3, expected, sizeof(element_t) * 16)) != 0) {
        return false;
    } else {
        return true;
    }
}

_Bool sub_test() {
    element_t m1[] = {163, 151, 162, 85, 83, 190, 241, 252, 249, 121, 107, 82, 20, 19, 233, 226};
    element_t m2[] = {45, 81, 142, 31, 86, 8, 87, 39, 167, 5, 212, 208, 82, 130, 119, 117};
    element_t m3[16];
    element_t expected[] = {118, 70, 20, 54, -3, 182, 154, 213, 82, 116, -105, -126, -62, -111, 114, 109};
    memset(m3, 0, sizeof(element_t) * 16);
    matrix_sub(m3, m1, m2, 4, 4);
    if ((memcmp(m3, expected, sizeof(element_t) * 16)) != 0) {
        return false;
    } else {
        return true;
    }
}

_Bool part_test() {
    element_t m[] = {163, 151, 162, 85, 83, 190, 241, 252, 249, 121, 107, 82, 20, 19, 233, 226};
    element_t m1[4];
    element_t m2[4];
    element_t m3[4];
    element_t m4[4];
    element_t expected_m1[4] = {163, 151, 83, 190};
    element_t expected_m2[4] = {162, 85, 241, 252};
    element_t expected_m3[4] = {249, 121, 20, 19};
    element_t expected_m4[4] = {107, 82, 233, 226};

    memset(m1, 0, sizeof(element_t) * 4);
    memset(m2, 0, sizeof(element_t) * 4);
    memset(m3, 0, sizeof(element_t) * 4);
    memset(m4, 0, sizeof(element_t) * 4);
    part_matrix(m, m1, m2, m3, m4, 2);
    
    int flag1 = memcmp(m1, expected_m1, sizeof(element_t) * 4);
    int flag2 = memcmp(m2, expected_m2, sizeof(element_t) * 4);
    int flag3 = memcmp(m3, expected_m3, sizeof(element_t) * 4);
    int flag4 = memcmp(m4, expected_m4, sizeof(element_t) * 4);
    if (flag1 | flag2 | flag3 | flag4) {
        return false;
    } else {
        return true;
    }
}

_Bool comb_test() {
    element_t m1[4] = {163, 151, 83, 190};
    element_t m2[4] = {162, 85, 241, 252};
    element_t m3[4] = {249, 121, 20, 19};
    element_t m4[4] = {107, 82, 233, 226};
    element_t m[16];
    element_t expected_m[] = {163, 151, 162, 85, 83, 190, 241, 252, 249, 121, 107, 82, 20, 19, 233, 226};
    
    memset(m, 0, sizeof(element_t) * 16);
    comb_matrix(m, m1, m2, m3, m4, 2);

    if (memcmp(m, expected_m, sizeof(element_t) * 16) != 0) {
        return false;
    } else {
        return true;
    }
}

_Bool cw_test() {
    element_t m1[] = {163, 151, 162, 85, 83, 190, 241, 252, 249, 121, 107, 82, 20, 19, 233, 226, 45, 81, 142, 31, 86, 8, 87, 39, 167, 5, 212, 208, 82, 130, 119, 117, 27, 153, 74, 237, 88, 61, 106, 82, 54, 213, 36, 74, 104, 142, 173, 149, 95, 60, 53, 181, 196, 140, 221, 108, 17, 50, 61, 226, 180, 180, 89, 207};
    element_t m2[] = {206, 35, 61, 39, 223, 167, 249, 150, 252, 30, 224, 102, 44, 14, 123, 140, 202, 48, 66, 143, 188, 159, 123, 206, 209, 184, 177, 135, 236, 138, 214, 187, 46, 21, 99, 14, 60, 220, 164, 58, 122, 6, 32, 167, 147, 27, 52, 221, 76, 245, 236, 136, 150, 104, 214, 104, 160, 9, 111, 142, 147, 71, 201, 65};
    element_t m3[64];
    element_t expected[] = {207753, 97847, 168649, 157852, 199613, 133169, 222994, 183105, 177644, 92222, 146531, 115657, 172484, 116797, 207149, 135947, 82629, 40045, 69379, 54418, 72730, 66458, 86245, 71478, 169354, 87153, 115464, 121075, 185484, 132604, 181977, 161785, 141265, 81617, 127534, 96715, 124798, 88976, 142132, 119972, 146634, 70386, 138687, 108826, 120613, 83221, 151320, 124265, 143397, 101046, 142798, 113355, 157871, 127662, 184714, 139727, 145782, 75135, 123826, 119074, 151834, 112839, 165783, 137309};
    memset(m3, 0, sizeof(element_t) * 64);
    dim_t matrixs_size = 128;
    matrix_t matrixs = malloc(sizeof(element_t) * matrixs_size);
    cw(m3, m1, m2, 4);
    if ((memcmp(m3, expected, sizeof(element_t) * 16)) != 0) {
        return false;
    } else {
        return true;
    }
}

int main() {
    printf("main test: ");
    if (main_test()) {
        printf("pass\n");
    } else {
        printf("faild\n");
    }

    printf("add test: ");
    if (add_test()) {
        printf("pass\n");
    } else {
        printf("faild\n");
    }

    printf("sub test: ");
    if (sub_test()) {
        printf("pass\n");
    } else {
        printf("faild\n");
    }

    printf("part test: ");
    if (part_test()) {
        printf("pass\n");
    } else {
        printf("faild\n");
    }

    printf("comb test: ");
    if (comb_test()) {
        printf("pass\n");
    } else {
        printf("faild\n");
    }

    printf("cw test: ");
    if (cw_test()) {
        printf("pass\n");
    } else {
        printf("faild\n");
    }
    
    return 0;
}
