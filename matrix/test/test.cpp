#include "matrix.h"

int main() {

    Matrix::Matrix2 mat(2, 2, {1.0, 2.0, 3.0, 4.0});
    mat = mat.inverse();
    Matrix::printMatrix(mat);

    Matrix::Matrix2 mat2(3,3, {1.0, 2.0, 3.0, 4.0, 9.0, 6.0, 7.0, 8.0, 9.0});
    mat2 = mat2.inverse();
    Matrix::printMatrix(mat2);
}