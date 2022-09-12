#include "matrix.h"

int helper_func_test() {
    Matrix::Matrix2 mat1(2, 2, {0, 0, 0, 0});
    Matrix::Matrix2 mat2(3, 3, {0, 0, 0, 0, 0, 0, 0, 0, 0});
    Matrix::Matrix2 mat3(2, 2, {1, 1, 1, 1});
    Matrix::Matrix2 mat4(3, 3, {1, 1, 1, 1, 1, 1, 1, 1, 1});
    Matrix::Matrix2 mat5(2, 2, {1, 0, 0, 1});
    Matrix::Matrix2 mat6(3, 3, {1, 0, 0, 0, 1, 0, 0, 0, 1});

    if (mat1 != Matrix::zeros(2, 2)) {
        return 1;
    }

    if (mat2 != Matrix::zeros(3, 3)) {
        return 1;
    }

    if (mat3 != Matrix::ones(2, 2)) {
        return 1;
    }

    if (mat4 != Matrix::ones(3, 3)) {
        return 1;
    }

    if (mat5 != Matrix::eye(2, 2)) {
        return 1;
    }

    if (mat6 != Matrix::eye(3, 3)) {
        return 1;
    }


    return 0;
}

int main() {
    return helper_func_test();
}