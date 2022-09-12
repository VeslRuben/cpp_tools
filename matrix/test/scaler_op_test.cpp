#include "matrix.h"

int scaler_op_test(){
    Matrix::Matrix2 mat1(2, 2, {1, 2, 3, 4});
    Matrix::Matrix2 mat2(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});

    double scalar = 2;

    Matrix::Matrix2 ans1p2(2, 2, {3, 4, 5, 6});
    Matrix::Matrix2 ans1m2(2, 2, {-1, 0, 1, 2});
    Matrix::Matrix2 ans1t2(2, 2, {2, 4, 6, 8});

    Matrix::Matrix2 ans2p2(3, 3, {3, 4, 5, 6, 7, 8, 9, 10, 11});
    Matrix::Matrix2 ans2m2(3, 3, {-1, 0, 1, 2, 3, 4, 5, 6, 7});
    Matrix::Matrix2 ans2t2(3, 3, {2, 4, 6, 8, 10, 12, 14, 16, 18});

    Matrix::Matrix2 mat1p2 = mat1 + scalar;
    Matrix::Matrix2 mat1m2 = mat1 - scalar;
    Matrix::Matrix2 mat1t2 = mat1 * scalar;

    Matrix::Matrix2 mat2p2 = mat2 + scalar;
    Matrix::Matrix2 mat2m2 = mat2 - scalar;
    Matrix::Matrix2 mat2t2 = mat2 * scalar;

    if (mat1p2 != ans1p2) {
        return 1;
    }

    if (mat1m2 != ans1m2) {
        return 1;
    }

    if (mat1t2 != ans1t2) {
        return 1;
    }

    if (mat2p2 != ans2p2) {
        return 1;
    }

    if (mat2m2 != ans2m2) {
        return 1;
    }

    if (mat2t2 != ans2t2) {
        return 1;
    }

    mat1 += scalar;
    mat2 += scalar;

    if (mat1 != ans1p2) {
        return 1;
    }

    if (mat2 != ans2p2) {
        return 1;
    }

    mat1 = Matrix::Matrix2(2, 2, {1, 2, 3, 4});
    mat2 = Matrix::Matrix2(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});

    mat1 -= scalar;
    mat2 -= scalar;

    if (mat1 != ans1m2) {
        return 1;
    }

    if (mat2 != ans2m2) {
        return 1;
    }

    mat1 = Matrix::Matrix2(2, 2, {1, 2, 3, 4});
    mat2 = Matrix::Matrix2(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});

    mat1 *= scalar;
    mat2 *= scalar;

    if (mat1 != ans1t2) {
        return 1;
    }

    if (mat2 != ans2t2) {
        return 1;
    }

    return 0;
}

int main() {
    return scaler_op_test();
}