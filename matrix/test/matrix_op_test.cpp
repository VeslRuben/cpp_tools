#include "matrix.h"
#include "iostream"

int matrix_op_test() {

    // ########################################
    // Test addition, subtraction, multiplication
    // ########################################
    Matrix::Matrix2 mat1(2, 2, {1, 2, 3, 4});
    Matrix::Matrix2 mat2(2, 2, {5, 6, 7, 8});

    Matrix::Matrix2 mat3(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
    Matrix::Matrix2 mat4(3, 3, {10, 11, 12, 13, 14, 15, 16, 17, 18});

    Matrix::Matrix2 mat1p2 = mat1 + mat2;
    Matrix::Matrix2 mat1m2 = mat1 - mat2;
    Matrix::Matrix2 mat1t2 = mat1 * mat2;

    Matrix::Matrix2 mat3p4 = mat3 + mat4;
    Matrix::Matrix2 mat3m4 = mat3 - mat4;
    Matrix::Matrix2 mat3t4 = mat3 * mat4;

    Matrix::Matrix2 ans1p2(2, 2, {6, 8, 10, 12});
    Matrix::Matrix2 ans1m2(2, 2, {-4, -4, -4, -4});
    Matrix::Matrix2 ans1t2(2, 2, {19, 22, 43, 50});

    Matrix::Matrix2 ans3p4(3, 3, {11, 13, 15, 17, 19, 21, 23, 25, 27});
    Matrix::Matrix2 ans3m4(3, 3, {-9, -9, -9, -9, -9, -9, -9, -9, -9});
    Matrix::Matrix2 ans3t4(3, 3, {84, 90, 96, 201, 216, 231, 318, 342, 366});

    if (mat1p2 != ans1p2) {
        return 1;
    }

    if (mat1m2 != ans1m2) {
        return 1;
    }

    if (mat1t2 != ans1t2) {
        return 1;
    }

    if (mat3p4 != ans3p4) {
        return 1;
    }

    if (mat3m4 != ans3m4) {
        return 1;
    }

    if (mat3t4 != ans3t4) {
        return 1;
    }

    mat1 += mat2;
    mat3 += mat4;

    if (mat1 != ans1p2) {
        return 1;
    }

    if (mat3 != ans3p4) {
        return 1;
    }

    mat1 = Matrix::Matrix2(2, 2, {1, 2, 3, 4});
    mat3 = Matrix::Matrix2(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});

    mat1 -= mat2;
    mat3 -= mat4;

    if (mat1 != ans1m2) {
        return 1;
    }

    if (mat3 != ans3m4) {
        return 1;
    }

    mat1 = Matrix::Matrix2(2, 2, {1, 2, 3, 4});
    mat3 = Matrix::Matrix2(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});

    mat1 *= mat2;
    mat3 *= mat4;

    if (mat1 != ans1t2) {
        return 1;
    }

    if (mat3 != ans3t4) {
        return 1;
    }

    // ########################################
    // Test transpose #########################
    // ########################################
    Matrix::Matrix2 mat2trans = mat2.transpose();
    Matrix::Matrix2 mat4trans = mat4.transpose();

    Matrix::Matrix2 ans2trans(2, 2, {5, 7, 6, 8});
    Matrix::Matrix2 ans4trans(3, 3, {10, 13, 16, 11, 14, 17, 12, 15, 18});

    if (mat2trans != ans2trans) {
        return 1;
    }

    if (mat4trans != ans4trans) {
        return 1;
    }

    // ########################################
    // Test determinant #######################
    // ########################################
    Matrix::Matrix2 mat6(4,4, {20, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 20});

    double mat2det = mat2.determinant();
    double mat4det = mat4.determinant();
    double mat6det = mat6.determinant();

    if (mat2det != -2) {
        return 1;
    }

    if (mat4det != 0) {
        return 1;
    }

    if (mat6det != -304) {
        return 1;
    }


    // ########################################
    // Test inverse ###########################
    // ########################################
    Matrix::Matrix2 mat5(3, 3, {1, 2, 3, 4, 9, 6, 7, 8, 9});
    Matrix::Matrix2 ans5inv(3, 3, {-11. / 16, -1. / 8, 5. / 16, -1. / 8, 1. / 4, -1. / 8, 31. / 48, -1. / 8, -1. / 48});
    Matrix::Matrix2 mat5inv = mat5.inverse();

    Matrix::Matrix2 ans2inv(2, 2, {-4, 3, 7. / 2, -5. / 2});
    Matrix::Matrix2 mat2inv = mat2.inverse();
    Matrix::printMatrix(mat5inv);
    std::cout << std::endl;
    Matrix::printMatrix(ans5inv);

    if (mat5inv != ans5inv) {
        return 1;
    }

    if (mat2inv != ans2inv) {
        return 1;
    }

    return 0;
}

int main() {
    return matrix_op_test();
}