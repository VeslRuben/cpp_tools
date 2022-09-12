//
// Created by itzRu on 01.09.2021.
//

#include "matrix.h"
#include "iostream"
#include "cmath"

namespace Matrix {
    /**
     * Returns a matrix of size 0x0 whit no space allocated for values.
     */
    Matrix2::Matrix2() {
        width_ = 0;
        height_ = 0;
        values_ = nullptr;
    }

    /**
     * Returns a matrix of size height*width whit a empty array of values.
     * @param height Height of the matrix.
     * @param width Width of the matrix.
     */
    Matrix2::Matrix2(int height, int width) {
        width_ = width;
        height_ = height;
        values_ = new double[width * height]{};
    }

    /**
     * Returns a a matrix of size height*width, initialises the matrix with the past in values parameter.
     * @param height Height of the matrix.
     * @param width Width of the matrix.
     * @param values Values to initialise the matrix. must be of size height*width
     */
    Matrix2::Matrix2(int height, int width, const double *values) {
        width_ = width;
        height_ = height;
        values_ = new double[width_ * height_];
        for (int i = 0; i < width_ * height_; i++) {
            values_[i] = values[i];
        }
    }

    /**
     * Returns a a matrix of size height*width, initialises the matrix with the past in values parameter.
     * @param height Height of the matrix.
     * @param width Width of the matrix.
     * @param values Values to initialise the matrix. must be of size height*width
     */
    Matrix2::Matrix2(int height, int width, const std::list<double> &values) {
        height_ = height;
        width_ = width;
        values_ = new double[height * width];
        std::copy(values.begin(), values.end(), values_);
    }

    /**
     * Copy constructor
     * @param old_obj
     */
    Matrix2::Matrix2(const Matrix2 &old_obj) {
        height_ = old_obj.height_;
        width_ = old_obj.width_;
        values_ = new double[height_ * width_];
        for (int i = 0; i < height_ * width_; i++) {
            values_[i] = old_obj.values_[i];
        }
    }

    /**
     * Move constructor
     * @param old_obj
     */
    Matrix2::Matrix2(Matrix2 &&old_obj) noexcept {
        height_ = old_obj.height_;
        width_ = old_obj.width_;
        values_ = old_obj.values_;
        old_obj.values_ = nullptr;
        old_obj.height_ = 0;
        old_obj.width_ = 0;
    }

    /**
     * Destructor
     */
    Matrix2::~Matrix2() {
        delete[] values_;
        values_ = nullptr;
    }

    // #####################################
    // Operator overloads #################
    // #####################################
    /**
     * Creates and returns a new but identical oldMatrix from an existing one.
     * @param oldMatrix Old matrix the new is based on.
     * @return New matrix object
     */
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

    /**
     * Returns true if the matrix's are the same or have the same size and values.
     * Rounds the values to 10 decimal places before comparing them to avoid floating point errors.
     * @param mat Matrix2 to compere with.
     * @return true if matrix's is equal.
     */
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

    /**
     * Returns true if matrix's is not eaquel. se operator==().
     * @param mat Matrix2 to compere with.
     * @return true if matrix's is not equal.
     */
    bool Matrix2::operator!=(const Matrix2 &mat) const {
        return !this->operator==(mat);
    }

    // Matrix2 Operators ####################
    /**
     * Adds to matrix's together it they are of the same size. Dos noting is the size dont match.
     * @param mat Matrix2 to add
     * @return Result of the addition as a new matrix.
     */
    Matrix2 Matrix2::operator+(Matrix2 const &mat) const {
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

    /**
    * Adds to matrix's together it they are of the same size. Dos noting is the size dont match.
    * @param mat Matrix2 to add
    * @return Update this matrix with the result of the addition an returns this pointer.
    */
    Matrix2 Matrix2::operator+=(Matrix2 const &mat) {
        Matrix2 temp = this->operator+(mat);
        *this = this->operator=(temp);
        return *this;
    }

    /**
     * Subtracts mat from this matrix if the are of the same size Dos noting is the size dont match.
     * @param mat Matrix2 to subtract form this.
     * @return Result of the subtraction as a new Matrix2.
     */
    Matrix2 Matrix2::operator-(Matrix2 const &mat) const {
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

    /**
     * Subtracts mat from this matrix if the are of the same size Dos noting is the size dont match.
     * @param mat Matrix2 to subtract form this.
     * @return Update this matrix with the result of the subtraction an returns this pointer.
     */
    Matrix2 Matrix2::operator-=(Matrix2 const &mat) {
        Matrix2 temp = this->operator-(mat);
        *this = this->operator=(temp);
        return *this;
    }

    /**
     * Multiples this with mat if the sizes are compatible else dos noting.
     * @param mat Matrix2 to multiply with this.
     * @return Result of the multiplication as a new Matrix2.
     */
    Matrix2 Matrix2::operator*(Matrix2 const &mat) const {
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

    /**
     * Multiples this with mat if the sizes are compatible else dos noting.
     * @param mat Matrix2 to multiply with this.
     * @return Update this matrix with the result of the multiplication an returns this pointer.
     */
    Matrix2 Matrix2::operator*=(Matrix2 const &mat) {
        Matrix2 temp = this->operator*(mat);
        *this = this->operator=(temp);
        return *this;
    }
    // #################################

    // Scaler Operators
    /**
     * Adds the scalar to this matrix.
     * @param scalar Scalar to add to the matrix.
     * @return Result as a new matrix.
     */
    Matrix2 Matrix2::operator+(const double scalar) {
        Matrix2 result = *this;
        return result += scalar;
    }

    /**
     * Adds the scalar to the matrix.
     * @param scalar Scalar to add to this matrix.
     * @return Updates this matrix wit the result and returns this pointer.
     */
    Matrix2 Matrix2::operator+=(const double scalar) {
        for (int i = 0; i < height_ * width_; ++i) {
            values_[i] += scalar;
        }
        return *this;
    }

    /**
     * Subtracts the scalar from this matrix.
     * @param scalar Scalar to add to the matrix.
     * @return Result as a new matrix.
     */
    Matrix2 Matrix2::operator-(const double scalar) {
        Matrix2 result = *this;
        return result -= scalar;
    }

    /**
     * Subtracts the scalar from this matrix.
     * @param scalar Scalar to subtracts from this matrix.
     * @return Updates this matrix wit the result and returns this pointer.
     */
    Matrix2 Matrix2::operator-=(const double scalar) {
        for (int i = 0; i < height_ * width_; ++i) {
            values_[i] -= scalar;
        }
        return *this;
    }

    /**
     * Multiples the scalar to this matrix.
     * @param scalar Scalar to add to the matrix.
     * @return Result as a new matrix.
     */
    Matrix2 Matrix2::operator*(const double scalar) {
        Matrix2 result = *this;
        return result *= scalar;
    }

    /**
     * Multiples the scalar to this matrix.
     * @param scalar Scalar to multiply from this matrix.
     * @return Updates this matrix wit the result and returns this pointer.
     */
    Matrix2 Matrix2::operator*=(const double scalar) {
        for (int i = 0; i < height_ * width_; ++i) {
            values_[i] *= scalar;
        }
        return *this;
    }
    // ###################################

    /**
     * Returns the value at index i of the matrix. The indexing is in row major.
     * @param i Index
     * @return Value at index
     */
    double Matrix2::operator[](int i) {
        return values_[i];
    }

    /**
     * Returns the value at position row, col.
     * @param row Row
     * @param col Col
     * @return Value at the position.
     */
    double Matrix2::operator()(int row, int col) const {
        return get(row, col);
    }
    // #####################################
    // #####################################

    /**
     * Not implemented properly. Do not use! FIXME
     * @param height New height
     * @param width New width
     */
    void Matrix2::resize(int height, int width) {
        height_ = height;
        width_ = width;
        delete[] values_;
        values_ = new double[height_ * width_];
    }

    /**
     * Returns the transpose of the matrix as a copy.
     * @return transpose of the matrix.
     */
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

    /**
 * Returns the determinant of the matrix.
 * @return determinant of the matrix.
 */
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


    /**
     * Returns the inverse of the matrix as a copy.
     * Returns zero matrix if the matrix is not invertible.
     * @return inverse of the matrix.
     */
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


    /**
     * Returns the submatrix of this matrix without the row and col.
     * @param row Row to remove
     * @param col Col to remove
     * @return Submatrix
     */
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


/**
 * Returns the value at position row, col.
 * @param row Row
 * @param col Col
 * @return Value at the position.
 */
    double Matrix2::get(int row, int col) const { return values_[row * width_ + col]; }

/**
 * Updates the newValue at the position row, col newValue
 * @param newValue New value.
 * @param row Row
 * @param col Col
 */
    void Matrix2::put(double newValue, int row, int col) {
        int index = row * width_ + col;
        values_[index] = newValue;
    }

/**
 * Returns the width of the matrix.
 * @return Width of the matrix
 */
    int Matrix2::getWidth() const { return width_; }

/**
 * Returns the height of the matrix.
 * @return Height of the matrix
 */
    int Matrix2::getHeight() const { return height_; }

    void printMatrix(Matrix2 &matrix) {
        for (int i = 0; i < matrix.getHeight(); i++) {
            for (int j = 0; j < matrix.getWidth(); j++) {
                std::cout << matrix.get(i, j) << " ";
            }
            std::cout << std::endl;
        }
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

}  // namespace Matrix2