#include "matrix.h"

int get_set_test(){
    Matrix::Matrix2 mat1(2,2, {1, 2, 3, 4});
    if (mat1.getHeight() != 2 || mat1.getWidth() != 2) {
        return 1;
    }

    if (mat1.get(0, 0) != 1 || mat1.get(0, 1) != 2 || mat1.get(1, 0) != 3 || mat1.get(1, 1) != 4) {
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

    if (mat1(0, 0) != 5 || mat1(0, 1) != 6 || mat1(1, 0) != 7 || mat1(1, 1) != 8) {
        return 1;
    }

    return 0;
}

int main() {
    return get_set_test();
}