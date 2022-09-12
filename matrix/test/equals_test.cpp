#include "matrix.h"


int equals_test(){
    Matrix::Matrix2 mat1(2,2, {1, 2, 3, 4});
    Matrix::Matrix2 mat2(2,2, {1, 2, 3, 4});
    Matrix::Matrix2 mat3(2,2, {1, 2, 3, 5});

    if (mat1 == mat3) {
        return 1;
    }

    if (mat1 != mat2) {
        return 1;
    }

    if (!(mat1 == mat2)) {
        return 1;
    }

    if (!(mat1 == mat1)) {
        return 1;
    }

    return 0;
}


int main() {
    return equals_test();
}