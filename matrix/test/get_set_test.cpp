#include "matrix.h"

int get_set_test(){
    Matrix::Matrix2 mat1(2,2, {1, 2, 3, 4});
    if (mat1.getHeight() != 2 || mat1.getWidth() != 2) {
        return 1;
    }

    if (mat1.get(0, 0) != 1 || mat1.get(0, 1) != 2 || mat1.get(1, 0) != 3 || mat1.get(1, 1) != 4) {
        return 1;
    }

    if (mat1.get(0, 0) != 1 || mat1.get(0, -1) != 2 || mat1.get(-1, 0) != 3 || mat1.get(-1, -1) != 4) {
        return 1;
    }

    mat1.put(5, 0, 0);
    mat1.put(6, 0, 1);
    mat1.put(7, 1, 0);
    mat1.put(8, 1, 1);

    if (mat1.get(0, 0) != 5 || mat1.get(0, 1) != 6 || mat1.get(1, 0) != 7 || mat1.get(1, 1) != 8) {
        return 1;
    }

    if (mat1[0] != 5 || mat1[1] != 6 || mat1[2] != 7 || mat1[3] != 8) {
        return 1;
    }

    if (mat1[0] != 5 || mat1[-3] != 6 || mat1[-2] != 7 || mat1[-1] != 8) {
        return 1;
    }

    if (mat1(0, 0) != 5 || mat1(0, 1) != 6 || mat1(1, 0) != 7 || mat1(1, 1) != 8) {
        return 1;
    }

    if (mat1(0, 0) != 5 || mat1(0, -1) != 6 || mat1(-1, 0) != 7 || mat1(-1, -1) != 8) {
        return 1;
    }

    mat1[0] = 1; mat1[1] = 2; mat1[2] = 3; mat1[3] = 4;

    if (mat1(0, 0) != 1 || mat1(0, 1) != 2 || mat1(1, 0) != 3 || mat1(1, 1) != 4) {
        return 1;
    }

    mat1[0] = 1; mat1[-3] = 2; mat1[-2] = 3; mat1[-1] = 4;

    if (mat1(0, 0) != 1 || mat1(0, 1) != 2 || mat1(1, 0) != 3 || mat1(1, 1) != 4) {
        return 1;
    }

    Matrix::Matrix2 row = mat1.row(0);
    if (row.getHeight() != 1 || row.getWidth() != 2) {
        return 1;
    }

    if (row(0, 0) != 1 || row(0, 1) != 2) {
        return 1;
    }

    Matrix::Matrix2 col = mat1.col(0);

    if (col.getHeight() != 2 || col.getWidth() != 1) {
        return 1;
    }

    if (col(0, 0) != 1 || col(1, 0) != 3) {
        return 1;
    }

    Matrix::Matrix2 sym(2, 2, {1, 2, 2, 1});

    if (!sym.isSymmetric()) {
        return 1;
    }

    Matrix::Matrix2 diag(2, 2, {1, 0, 0, 1});

    if (!diag.isDiagonal()) {
        return 1;
    }

    Matrix::Matrix2 ident(2, 2, {1, 0, 0, 1});

    if (!ident.isIdentity()) {
        return 1;
    }

    Matrix::Matrix2 upperTri(2, 2, {1, 2, 0, 1});

    if (!upperTri.isUpperTriangular()) {
        return 1;
    }

    Matrix::Matrix2 lowerTri(2, 2, {1, 0, 2, 1});

    if (!lowerTri.isLowerTriangular()) {
        return 1;
    }

    Matrix::Matrix2 tri(2, 2, {1, 0, 2, 1});

    if (!tri.isTriangular()) {
        return 1;
    }

    Matrix::Matrix2 zero(2, 2, {0, 0, 0, 0});

    if (!zero.isZero()) {
        return 1;
    }

    return 0;
}

int main() {
    return get_set_test();
}