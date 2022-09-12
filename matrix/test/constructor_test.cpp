#include "matrix.h"

int constructor_test(){

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
        return 1;
    }
    if (mat3.get(0, 0) != 1 || mat3.get(0, 1) != 2 || mat3.get(1, 0) != 3 || mat3.get(1, 1) != 4) {
        return 1;
    }

    Matrix::Matrix2 mat4(2,2, {1, 2, 3, 4});
    if (mat4.getHeight() != 2 || mat4.getWidth() != 2) {
        return 1;
    }
    if (mat4.get(0, 0) != 1 || mat4.get(0, 1) != 2 || mat4.get(1, 0) != 3 || mat4.get(1, 1) != 4) {
        return 1;
    }

    Matrix::Matrix2 mat5(mat4);
    if (mat5.getHeight() != 2 || mat5.getWidth() != 2) {
        return 1;
    }
    if (mat5.get(0, 0) != 1 || mat5.get(0, 1) != 2 || mat5.get(1, 0) != 3 || mat5.get(1, 1) != 4) {
        return 1;
    }

    Matrix::Matrix2 mat6 = mat5;
    if (mat6.getHeight() != 2 || mat6.getWidth() != 2) {
        return 1;
    }
    if (mat6.get(0, 0) != 1 || mat6.get(0, 1) != 2 || mat6.get(1, 0) != 3 || mat6.get(1, 1) != 4) {
        return 1;
    }

    Matrix::Matrix2 mat7(std::move(mat6));
    if (mat7.getHeight() != 2 || mat7.getWidth() != 2) {
        return 1;
    }
    if (mat7.get(0, 0) != 1 || mat7.get(0, 1) != 2 || mat7.get(1, 0) != 3 || mat7.get(1, 1) != 4) {
        return 1;
    }
    if (mat6.getHeight() != 0 || mat6.getWidth() != 0) {
        return 1;
    }

    Matrix::Matrix2 mat8 = std::move(mat7);

    if (mat8.getHeight() != 2 || mat8.getWidth() != 2) {
        return 1;
    }

    if (mat8.get(0, 0) != 1 || mat8.get(0, 1) != 2 || mat8.get(1, 0) != 3 || mat8.get(1, 1) != 4) {
        return 1;
    }

    if (mat7.getHeight() != 0 || mat7.getWidth() != 0) {
        return 1;
    }

    return 0;
}


int main() {
    return constructor_test();
}