//
// Created by itzRu on 01.09.2021.
//

#include "matrix.h"
#include "iostream"
#include "random"

namespace Matrix {

    int mod(int a, int b) { return (a % b + b) % b; }

    Matrix2::Matrix2() {
        width_ = 0;
        height_ = 0;
        values_ = nullptr;
    }


    Matrix2::Matrix2(int height, int width) {
        width_ = width;
        height_ = height;
        values_ = new double[width * height]{};
    }


    Matrix2::Matrix2(int height, int width, const double *values) {
        width_ = width;
        height_ = height;
        values_ = new double[width_ * height_];
        for (int i = 0; i < width_ * height_; i++) {
            values_[i] = values[i];
        }
    }

#ifndef ARDUINO_H

    Matrix2::Matrix2(int height, int width, const std::vector<double> &values) {
        height_ = height;
        width_ = width;
        values_ = new double[width_ * height_];
        std::copy(values.begin(), values.end(), values_);
    }

    Matrix2::Matrix2(int height, int width, const std::vector<std::vector<double>> &values) {
        height_ = height;
        width_ = width;
        values_ = new double[height * width];
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                put(values[i][j], i, j);
            }
        }

    }

#endif

    Matrix2::Matrix2(const Matrix2 &old_obj) {
        height_ = old_obj.height_;
        width_ = old_obj.width_;
        values_ = new double[height_ * width_];
        for (int i = 0; i < height_ * width_; i++) {
            values_[i] = old_obj.values_[i];
        }
    }


    Matrix2::Matrix2(Matrix2 &&old_obj) noexcept {
        height_ = old_obj.height_;
        width_ = old_obj.width_;
        values_ = old_obj.values_;
        old_obj.values_ = nullptr;
        old_obj.height_ = 0;
        old_obj.width_ = 0;
    }

    Matrix2::~Matrix2() {
        delete[] values_;
        values_ = nullptr;
    }

    // #####################################
    // Operator overloads #################
    // #####################################
    Matrix2 &Matrix2::operator=(const Matrix2 &oldMatrix) {
        if (this != &oldMatrix) {
            height_ = oldMatrix.height_;
            width_ = oldMatrix.width_;
            delete[] values_;
            values_ = new double[height_ * width_];
            for (int i = 0; i < height_ * width_; i++) {
                values_[i] = oldMatrix.values_[i];
            }
        }
        return *this;
    }

    Matrix2 &Matrix2::operator=(const double value) {
        if (this->size() == 1) {
            values_[0] = value;
        } else {
            delete[] values_;
            values_ = new double[1]{value};
            height_ = 1;
            width_ = 1;
        }
        return *this;
    }


    Matrix2 &Matrix2::operator=(Matrix2 &&oldMatrix) noexcept {
        if (this != &oldMatrix) {
            height_ = oldMatrix.height_;
            width_ = oldMatrix.width_;
            delete[] values_;
            values_ = oldMatrix.values_;
            oldMatrix.values_ = nullptr;
            oldMatrix.height_ = 0;
            oldMatrix.width_ = 0;
        }
        return *this;
    }


    bool Matrix2::operator==(const Matrix2 &mat) const {
        if (this == &mat) return true;

        if (height_ == mat.height_ && width_ == mat.width_) {
            for (int i = 0; i < height_ * width_; ++i) {
                if (std::round(values_[i] * 10000000000.) / 10000000000. !=
                    std::round(mat.values_[i] * 10000000000.) / 10000000000.)
                    return false;
            }
        } else return false;
        return true;
    }


    bool Matrix2::operator!=(const Matrix2 &mat) const {
        return !this->operator==(mat);
    }

    std::ostream &operator<<(std::ostream &os, const Matrix2 &mat) {
        os << "[";
        for (int i = 0; i < mat.height_; i++) {
            for (int j = 0; j < mat.width_; j++) {
                os << mat.values_[i * mat.width_ + j];
                if (j != mat.width_ - 1) os << ", ";
            }
            if (i != mat.height_ - 1) os << ";" << std::endl;
        }
        os << "]";
        return os;
    }

    // Matrix2 Operators ####################
    Matrix2 Matrix2::operator+(Matrix2 const &mat) const {
        if (mat.size() == 1) {
            return this->operator+(mat.values_[0]);
        }

        Matrix2 result(this->getHeight(), this->getWidth());
        if (height_ == mat.height_ && width_ == mat.width_) {
            for (int r = 0; r < this->getHeight(); r++) {
                for (int c = 0; c < this->getWidth(); c++) {
                    result.put(this->get(r, c) + mat.get(r, c), r, c);
                }
            }
        }
        return result;
    }

    Matrix2 Matrix2::operator+=(Matrix2 const &mat) {
        if (mat.size() == 1) {
            return this->operator+=(mat.values_[0]);
        } else {
            Matrix2 temp = this->operator+(mat);
            *this = this->operator=(temp);
            return *this;
        }
    }


    Matrix2 Matrix2::operator-(Matrix2 const &mat) const {
        if (mat.size() == 1) {
            return this->operator-(mat.values_[0]);
        }

        Matrix2 result(this->getHeight(), this->getWidth());
        if (height_ == mat.height_ && width_ == mat.width_) {
            for (int r = 0; r < this->getHeight(); r++) {
                for (int c = 0; c < this->getWidth(); c++) {
                    result.put(this->get(r, c) - mat.get(r, c), r, c);
                }
            }
        }
        return result;
    }


    Matrix2 Matrix2::operator-=(Matrix2 const &mat) {
        if (mat.size() == 1) {
            return this->operator-=(mat.values_[0]);
        } else {
            Matrix2 temp = this->operator-(mat);
            *this = this->operator=(temp);
            return *this;
        }
    }


    Matrix2 Matrix2::operator*(Matrix2 const &mat) const {
        if (mat.size() == 1) {
            return this->operator*(mat.values_[0]);
        }
        Matrix2 result(this->getHeight(), mat.getWidth());
        if (width_ == mat.height_) {
            for (int i = 0; i < result.getHeight() * result.getWidth(); i++) {
                int row = i / result.getWidth();
                int col = i % result.getWidth();
                double sum = 0;
                for (int j = 0; j < this->getWidth(); j++) {
                    sum += this->get(row, j) * mat.get(j, col);
                }
                result.put(sum, row, col);
            }
        }
        return result;
    }


    Matrix2 Matrix2::operator*=(Matrix2 const &mat) {
        if (mat.size() == 1) {
            return this->operator*=(mat.values_[0]);
        } else {
            Matrix2 temp = this->operator*(mat);
            *this = this->operator=(temp);
            return *this;
        }
    }
    // #################################

    // Scaler Operators

    Matrix2 Matrix2::operator+(const double scalar) const {
        Matrix2 result = *this;
        return result += scalar;
    }


    Matrix2 Matrix2::operator+=(const double scalar) {
        for (int i = 0; i < height_ * width_; ++i) {
            values_[i] += scalar;
        }
        return *this;
    }


    Matrix2 Matrix2::operator-(const double scalar) const {
        Matrix2 result = *this;
        return result -= scalar;
    }


    Matrix2 Matrix2::operator-=(const double scalar) {
        for (int i = 0; i < height_ * width_; ++i) {
            values_[i] -= scalar;
        }
        return *this;
    }


    Matrix2 Matrix2::operator*(const double scalar) const {
        Matrix2 result = *this;
        return result *= scalar;
    }


    Matrix2 Matrix2::operator*=(const double scalar) {
        for (int i = 0; i < height_ * width_; ++i) {
            values_[i] *= scalar;
        }
        return *this;
    }

    Matrix2 Matrix2::operator/(const double scalar) const {
        Matrix2 result = *this;
        return result /= scalar;
    }

    Matrix2 Matrix2::operator/=(const double scalar) {
        for (int i = 0; i < height_ * width_; ++i) {
            values_[i] /= scalar;
        }
        return *this;
    }
    // ###################################


    double Matrix2::operator[](int i) const {
        int index = mod(i, (height_ * width_));
        return values_[index];
    }


    double &Matrix2::operator[](int i) {
        int index = mod(i, (height_ * width_));
        return values_[index];
    }


    double Matrix2::operator()(int row, int col) const {
        return get(row, col);
    }

    double &Matrix2::operator()(int row, int col) {
        row = mod(row, height_);
        col = mod(col, width_);
        return values_[row * width_ + col];
    }

    // #####################################
    Matrix2 Matrix2::reshape(int height, int width) {
        if (height * width == height_ * width_) {
            height_ = height;
            width_ = width;
        }
        return *this;
    }


    Matrix2 Matrix2::transpose() const {
        auto *newList = new double[height_ * width_];
        int newListIndex = 0;
        int newNumCols = height_;
        int newNumRows = width_;

        for (int col = 0; col < width_; col++) {
            for (int row = 0; row < height_; row++) {
                newList[newListIndex++] = get(row, col);
            }
        }
        Matrix2 result(newNumRows, newNumCols, newList);
        delete[] newList;
        return result;
    }


    double Matrix2::determinant() const {
        if (height_ == width_) {
            double det = 0;
            if (height_ == 1) {
                det = get(0, 0);
            } else if (height_ == 2) {
                det = get(0, 0) * get(1, 1) - get(0, 1) * get(1, 0);
            } else {
                int sign = 1;
                for (int i = 0; i < width_; i++) {
                    Matrix2 subMatrix = subMatrixWithoutRowAndCol(0, i);
                    det += sign * get(0, i) * subMatrix.determinant();
                    sign = -sign;
                }
            }
            return det;
        }
        return 0;
    }


    Matrix2 Matrix2::inverse() const {
        if (height_ == width_) {
            double det = determinant();
            if (det != 0) {
                Matrix2 result(height_, width_);
                if (height_ == 1) {
                    result.put(1 / get(0, 0), 0, 0);
                } else if (height_ == 2) {
                    result.put(get(1, 1) / det, 0, 0);
                    result.put(-get(0, 1) / det, 0, 1);
                    result.put(-get(1, 0) / det, 1, 0);
                    result.put(get(0, 0) / det, 1, 1);
                } else {
                    int sign = 1;
                    for (int i = 0; i < width_; i++) {
                        for (int j = 0; j < height_; j++) {
                            Matrix2 subMatrix = subMatrixWithoutRowAndCol(j, i);
                            result.put(sign * subMatrix.determinant() / det, i, j);
                            sign = -sign;
                        }
                    }
                }
                return result;
            }
        }
        return zeros(height_, width_);
    }


    Matrix2 Matrix2::subMatrixWithoutRowAndCol(int row, int col) const {
        if (height_ == 2 && width_ == 2) {
            return Matrix2(1, 1, new double[1]{get(1 - row, 1 - col)});
        }
        Matrix2 result(height_ - 1, width_ - 1);
        int resultRow = 0;
        int resultCol = 0;
        for (int i = 0; i < height_; i++) {
            if (i != row) {
                for (int j = 0; j < width_; j++) {
                    if (j != col) {
                        result.put(get(i, j), resultRow, resultCol);
                        resultCol++;
                    }
                }
                resultCol = 0;
                resultRow++;
            }
        }
        return result;
    }


    double Matrix2::get(int row, int col) const {
        row = mod(row, height_);
        col = mod(col, width_);
        return values_[row * width_ + col];
    }


    void Matrix2::put(double newValue, int row, int col) {
        row = mod(row, height_);
        col = mod(col, width_);
        values_[row * width_ + col] = newValue;
    }

    Matrix2 Matrix2::row(int row) const {
        row = mod(row, height_);
        Matrix2 result(1, width_);
        for (int i = 0; i < width_; i++) {
            result.put(get(row, i), 0, i);
        }
        return result;
    }

    Matrix2 Matrix2::col(int col) const {
        col = mod(col, width_);
        Matrix2 result(height_, 1);
        for (int i = 0; i < height_; i++) {
            result.put(get(i, col), i, 0);
        }
        return result;
    }

    bool Matrix2::isSymmetric() const {
        if (!isSquare()) {
            return false;
        }

        for (int i = 0; i < height_; ++i) {
            for (int j = 0; j < width_; ++j) {
                if (get(i, j) != get(j, i)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool Matrix2::isDiagonal() const {
        if (!isSquare()) {
            return false;
        }

        for (int i = 0; i < height_; ++i) {
            for (int j = 0; j < width_; ++j) {
                if (i != j && get(i, j) != 0) {
                    return false;
                }
            }
        }

        return true;
    }

    bool Matrix2::isIdentity() const {
        if (!isSquare()) {
            return false;
        }
        for (int i = 0; i < height_; ++i) {
            for (int j = 0; j < width_; ++j) {
                if (i == j && get(i, j) != 1) {
                    return false;
                } else if (i != j && get(i, j) != 0) {
                    return false;
                }
            }
        }

        return true;
    }

    bool Matrix2::isUpperTriangular() const {
        if (!isSquare()) {
            return false;
        }

        for (int i = 0; i < height_; ++i) {
            for (int j = 0; j < width_; ++j) {
                if (i > j && get(i, j) != 0) {
                    return false;
                }
            }
        }

        return true;
    }

    bool Matrix2::isLowerTriangular() const {
        if (!isSquare()) {
            return false;
        }

        for (int i = 0; i < height_; ++i) {
            for (int j = 0; j < width_; ++j) {
                if (i < j && get(i, j) != 0) {
                    return false;
                }
            }
        }

        return true;
    }

    bool Matrix2::isZero() const {
        for (int i = 0; i < height_; ++i) {
            for (int j = 0; j < width_; ++j) {
                if (get(i, j) != 0) {
                    return false;
                }
            }
        }

        return true;
    }


    void printMatrix(Matrix2 const &matrix) {
        std::cout << matrix << std::endl;
    }

    Matrix2 inverse(Matrix2 const &matrix) {
        return matrix.inverse();
    }

    Matrix2 transpose(Matrix2 const &matrix) {
        return matrix.transpose();
    }

    Matrix2 zeros(int height, int width) {
        double values[height * width];
        for (int i = 0; i < height * width; i++) {
            values[i] = 0;
        }
        return {height, width, values};
    }

    Matrix2 ones(int height, int width) {
        double values[height * width];
        for (int i = 0; i < height * width; i++) {
            values[i] = 1;
        }
        return {height, width, values};
    }

    Matrix2 eye(int height, int width) {
        double values[height * width];
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == j) {
                    values[i * width + j] = 1;
                } else
                    values[i * width + j] = 0;
            }
        }
        return {height, width, values};
    }

    Matrix2 random(int height, int width) {
        std::random_device rd;
        std::default_random_engine gen(rd());
        std::uniform_real_distribution<> dis(0, 1);
        double values[height * width];
        for (int i = 0; i < height * width; i++) {
            values[i] = dis(gen);
        }
        return {height, width, values};
    }

}  // namespace Matrix2