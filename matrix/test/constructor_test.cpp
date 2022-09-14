#include "matrix.h"

int constructor_test() {

    Matrix::Matrix2 mat1;
    if (mat1.getHeight() != 0 || mat1.getWidth() != 0) {
        return 1;
    }

    Matrix::Matrix2 mat2(2, 2);
    if (mat2.getHeight() != 2 || mat2.getWidth() != 2) {
        return 1;
    }

    double values[4] = {1, 2, 3, 4};
    Matrix::Matrix2 mat3(2, 2, values);
    if (mat3.getHeight() != 2 || mat3.getWidth() != 2) {
        return 2;
    }
    if (mat3.get(0, 0) != 1 || mat3.get(0, 1) != 2 || mat3.get(1, 0) != 3 || mat3.get(1, 1) != 4) {
        return 3;
    }

    Matrix::Matrix2 mat4(2, 2, {1, 2, 3, 4});
    if (mat4.getHeight() != 2 || mat4.getWidth() != 2) {
        return 4;
    }
    if (mat4.get(0, 0) != 1 || mat4.get(0, 1) != 2 || mat4.get(1, 0) != 3 || mat4.get(1, 1) != 4) {
        return 5;
    }

    Matrix::Matrix2 mat5(2, 2, {{1, 2},
                                {3, 4}});
    if (mat5.getHeight() != 2 || mat5.getWidth() != 2) {
        return 6;
    }

    if (mat5.get(0, 0) != 1 || mat5.get(0, 1) != 2 || mat5.get(1, 0) != 3 || mat5.get(1, 1) != 4) {
        return 7;
    }

    Matrix::Matrix2 mat6(mat5);
    if (mat6.getHeight() != 2 || mat6.getWidth() != 2) {
        return 8;
    }
    if (mat6.get(0, 0) != 1 || mat6.get(0, 1) != 2 || mat6.get(1, 0) != 3 || mat6.get(1, 1) != 4) {
        return 9;
    }

    Matrix::Matrix2 mat7 = mat6;
    if (mat7.getHeight() != 2 || mat7.getWidth() != 2) {
        return 10;
    }
    if (mat7.get(0, 0) != 1 || mat7.get(0, 1) != 2 || mat7.get(1, 0) != 3 || mat7.get(1, 1) != 4) {
        return 1;
    }

    Matrix::Matrix2 mat8(std::move(mat7));
    if (mat8.getHeight() != 2 || mat8.getWidth() != 2) {
        return 12;
    }
    if (mat8.get(0, 0) != 1 || mat8.get(0, 1) != 2 || mat8.get(1, 0) != 3 || mat8.get(1, 1) != 4) {
        return 13;
    }
    if (mat7.getHeight() != 0 || mat7.getWidth() != 0) {
        return 14;
    }

    Matrix::Matrix2 mat9 = std::move(mat8);

    if (mat9.getHeight() != 2 || mat9.getWidth() != 2) {
        return 15;
    }

    if (mat9.get(0, 0) != 1 || mat9.get(0, 1) != 2 || mat9.get(1, 0) != 3 || mat9.get(1, 1) != 4) {
        return 16;
    }

    if (mat8.getHeight() != 0 || mat8.getWidth() != 0) {
        return 17;
    }

    Matrix::Matrix2 mat10(2, 2, {1, 2, 3, 4});
    mat10 = 5.;

    if (mat10.getHeight() != 1 || mat10.getWidth() != 1) {
        return 18;
    }

    if (mat10.get(0, 0) != 5.) {
        return 19;
    }

    return 0;
}


int main() {
    return constructor_test();
}