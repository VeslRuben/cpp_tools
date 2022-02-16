//
// Created by itzRu on 01.09.2021.
//

#include <list>
#include "matrix.h"
#include "cmath"

namespace Matrix {
    /**
     * Returns a matrix of size 1*1.
     */
    Matrix2::Matrix2() {
        width_ = 1;
        height_ = 1;
        values_ = new double[1]{};
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

    Matrix2::Matrix2(const Matrix2 &old_obj) {
        height_ = old_obj.height_;
        width_ = old_obj.width_;
        values_ = new double[height_ * width_];
        for (int i = 0; i < height_ * width_; i++) {
            values_[i] = old_obj.values_[i];
        }
    }

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

    /**
     * Returns true if the matrix's are the same or have the same size and values.
     * @param mat Matrix2 to compere with.
     * @return true if matrix's is equal.
     */
    bool Matrix2::operator==(const Matrix2 &mat) const {
        if (this == &mat) return true;

        if (height_ == mat.height_ && width_ == mat.width_) {
            for (int i = 0; i < height_ * width_; ++i) {
                if (values_[i] != mat.values_[i]) return false;
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
    Matrix2 Matrix2::operator+(Matrix2 &mat) {
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
    Matrix2 Matrix2::operator+=(Matrix2 &mat) {
        Matrix2 temp = this->operator+(mat);
        *this = this->operator=(temp);
        return *this;
    }

    /**
     * Subtracts mat from this matrix if the are of the same size Dos noting is the size dont match.
     * @param mat Matrix2 to subtract form this.
     * @return Result of the subtraction as a new Matrix2.
     */
    Matrix2 Matrix2::operator-(Matrix2 &mat) {
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
    Matrix2 Matrix2::operator-=(Matrix2 &mat) {
        Matrix2 temp = this->operator-(mat);
        *this = this->operator=(temp);
        return *this;
    }

    /**
     * Multiples this with mat if the sizes are compatible else dos noting.
     * @param mat Matrix2 to multiply with this.
     * @return Result of the multiplication as a new Matrix2.
     */
    Matrix2 Matrix2::operator*(Matrix2 &mat) {
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
    Matrix2 Matrix2::operator*=(Matrix2 &mat) {
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
    double Matrix2::operator()(int row, int col) {
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
        values_ = new double[height_ * width_];;
    }

    /**
     * Transposes the matrix.
     */
    void Matrix2::transpose() {
        auto *newList = new double[height_ * width_];
        int newListIndex = 0;
        int newNumCols = height_;
        int newNumRows = width_;

        for (int col = 0; col < width_; col++) {
            for (int row = 0; row < height_; row++) {
                newList[newListIndex++] = get(row, col);
            }
        }

        height_ = newNumRows;
        width_ = newNumCols;
        for (int i = 0; i < height_ * width_; i++) {
            values_[i] = newList[i];
        }
        delete[] newList;
    }

    /**
     * Returns the value at position row, col.
     * @param row Row
     * @param col Col
     * @return Value at the position.
     */
    double Matrix2::get(int row, int col) { return values_[row * width_ + col]; }

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

}  // namespace Matrix2