//
// Created by itzRu on 01.09.2021.
//
#pragma once

#ifndef ARDUINO_H
#include "vector"
#include <ostream>
#endif

namespace Matrix {
    class Matrix2 {
    public:
        /**
        * Crates a matrix of size 0x0 whit no space allocated for values.
        */
        Matrix2();

        /**
         * Creates a matrix of size height*width whit a empty array of values.
         * @param height Height of the matrix.
         * @param width Width of the matrix.
         */
        Matrix2(int height, int width);

        /**
         * Crates a a matrix of size height*width, initialises the matrix with the past in values parameter.
         * @param height Height of the matrix.
         * @param width Width of the matrix.
         * @param values Values to initialise the matrix. must be of size height*width
         */
        Matrix2(int height, int width, const double *values);

#ifndef ARDUINO_H

        /**
         * Crates a a matrix of size height*width, initialises the matrix with the past in values parameter.
         * @param height Height of the matrix.
         * @param width Width of the matrix.
         * @param values Values to initialise the matrix. must be of size height*width
         */
        Matrix2(int height, int width, const std::vector<double> &values);

        /**
         * Crates a a matrix of size height*width, initialises the matrix with the past in values parameter.
         * @param height Height of the matrix.
         * @param width Width of the matrix.
         * @param values Values to initialise the matrix. must be of size height*width
         */
        Matrix2(int height, int width, const std::vector<std::vector<double>> &values);

#endif

        /**
         * Copy constructor.
         * @param other Matrix to copy.
         */
        Matrix2(const Matrix2 &old_obj);  // copy constructor

        /**
         * Move constructor.
         * @param other Matrix to move.
         */
        Matrix2(Matrix2 &&old_obj) noexcept;  // move constructor

        ~Matrix2();

        // #####################################
        // Operator overloads #################
        // #####################################
        /**
         * Copy assignment operator.
         * @param other Matrix to copy.
         * @return Reference to this.
         */
        Matrix2 &operator=(const Matrix2 &oldMatrix);

        /**
         * Assignment operator for scalar. if this is not a scalar matrix, it will be converted to a scalar matrix
         * @param value Scalar value
         * @return Reference to this
         */
        Matrix2 &operator=(double value);

        /**
         * Move assignment operator.
         * @param other Matrix to move.
         * @return Reference to this.
         */
        Matrix2 &operator=(Matrix2 &&oldMatrix) noexcept;

        /**
         * Returns true if the matrix's are the same or have the same size and values.
         * Rounds the values to 10 decimal places before comparing them to avoid floating point errors.
         * @param mat Matrix2 to compere with.
         * @return true if matrix's is equal.
         */
        bool operator==(const Matrix2 &mat) const;

        /**
         * Returns true if the matrix's are not the same or have different size or values.
         * Rounds the values to 10 decimal places before comparing them to avoid floating point errors.
         * @param mat Matrix2 to compere with.
         * @return true if matrix's is not equal.
         */
        bool operator!=(const Matrix2 &mat) const;

        friend std::ostream &operator<<(std::ostream &os, const Matrix2 &mat);

        // Matrix2 Operators ####################
        /**
         * Adds the matrix to the other matrix. The matrix's must be the same size.
         * @param other Matrix to add.
         * @return New matrix with the result.
         */
        Matrix2 operator+(Matrix2 const &mat) const;

        /**
         * Adds the matrix to the other matrix. The matrix's must be the same size.
         * @param other Matrix to add.
         * @return Reference to this.
         */
        Matrix2 operator+=(Matrix2 const &mat);

        /**
         * Subtracts the matrix to the other matrix. The matrix's must be the same size.
         * @param other Matrix to subtract.
         * @return New matrix with the result.
         */
        Matrix2 operator-(Matrix2 const &mat) const;

        /**
         * Subtracts the matrix to the other matrix. The matrix's must be the same size.
         * @param other Matrix to subtract.
         * @return Reference to this.
         */
        Matrix2 operator-=(Matrix2 const &mat);

        /**
         * Multiplies the matrix to the other matrix. The matrix's must be the same size.
         * @param other Matrix to multiply.
         * @return New matrix with the result.
         */
        Matrix2 operator*(Matrix2 const &mat) const;

        /**
         * Multiplies the matrix to the other matrix. The matrix's must be the same size.
         * @param other Matrix to multiply.
         * @return Reference to this.
         */
        Matrix2 operator*=(Matrix2 const &mat);
        // ######################################

        // Scaler Operators
        /**
         * Adds the scaler to the matrix.
         * @param scaler Scaler to add.
         * @return New matrix with the result.
         */
        Matrix2 operator+(double scalar) const;

        /**
         * Adds the scaler to the matrix.
         * @param scaler Scaler to add.
         * @return Reference to this.
         */
        Matrix2 operator+=(double scalar);

        /**
         * Subtracts the scaler to the matrix.
         * @param scaler Scaler to subtract.
         * @return New matrix with the result.
         */
        Matrix2 operator-(double scalar) const;

        /**
         * Subtracts the scaler to the matrix.
         * @param scaler Scaler to subtract.
         * @return Reference to this.
         */
        Matrix2 operator-=(double scalar);

        /**
         * Multiplies the scaler to the matrix.
         * @param scaler Scaler to multiply.
         * @return New matrix with the result.
         */
        Matrix2 operator*(double scalar) const;

        /**
         * Multiplies the scaler to the matrix.
         * @param scaler Scaler to multiply.
         * @return Reference to this.
         */
        Matrix2 operator*=(double scalar);

        /**
         * Divides the scaler to the matrix.
         * @param scaler Scaler to divide.
         * @return New matrix with the result.
         */
        Matrix2 operator/(double scalar) const;

        /**
         * Divides the scaler to the matrix.
         * @param scaler Scaler to divide.
         * @return Reference to this.
         */
        Matrix2 operator/=(double scalar);
        // ######################################

        /**
         * Returns the value at index i of the matrix. The indexing is in row major.
         * @param i Index
         * @return Value at index
         */
        double operator[](int i) const;

        /**
         * Returns the addres of value at index i of the matrix. The indexing is in row major.
         * @param i Index
         * @return Reference to value at index
         */
        double &operator[](int i);

        /**
         * Returns the value at row and column of the matrix
         * @param row Row of the value.
         * @param col Column of the value.
         * @return Value at row and column.
         */
        double operator()(int row, int col) const;

        double &operator()(int row, int col);
        // #####################################

        /**
         * Gives the matrix a new shape without changing the values. The new size must be the same as the old size.
         * @param height New height of the matrix.
         * @param width New width of the matrix.
         * @return Reference to this.
         */
        Matrix2 reshape(int height, int width);

        /**
         * Returns the transpose of the matrix as a copy.
         * @return transpose of the matrix.
         */
        [[nodiscard]] Matrix2 transpose() const;

        /**
         * Returns the transpose of the matrix as a copy.
         * @return transpose of the matrix.
         */
        [[nodiscard]] Matrix2 T() const { return transpose(); }

        /**
         * Returns the determinant of the matrix.
         * @return Determinant of the matrix.
         */
        [[nodiscard]] double determinant() const;

        /**
         * Returns the inverse of the matrix as a copy.
         * Returns zero matrix if the matrix is not invertible.
         * @return inverse of the matrix.
         */
        [[nodiscard]] Matrix2 inverse() const;

        /**
         * Returns the submatrix of this matrix without the row and col.
         * @param row Row to remove
         * @param col Col to remove
         * @return Submatrix
         */
        [[nodiscard]] Matrix2 subMatrixWithoutRowAndCol(int row, int col) const;

        /**
         * Returns the value at position row, col.
         * @param row Row
         * @param col Col
         * @return Value at the position.
         */
        [[nodiscard]] double get(int row, int col) const;

        /**
         * Sets the value at position row, col.
         * @param row Row
         * @param col Col
         * @param value Value to set.
         */
        void put(double newValue, int row, int col);

        /**
         * Returns the number of rows in the matrix.
         * @return Number of rows.
         */
        [[nodiscard]] int getWidth() const { return width_; }

        /**
         * Returns the number of columns in the matrix.
         * @return Number of columns.
         */
        [[nodiscard]] int getHeight() const { return height_; }

        /**
         * returns the number of elements in the matrix
         * @return  Number of elements.
         */
        [[nodiscard]] int size() const { return width_ * height_; }

        /**
         * Returns the row vector at the given index.
         * @param row Row index.
         * @return Row vector.
         */
        [[nodiscard]] Matrix2 row(int row) const;

        /**
         * Returns the column vector at the given index.
         * @param col Column index.
         * @return Column vector.
         */
        [[nodiscard]] Matrix2 col(int col) const;

        [[nodiscard]] bool isSquare() const { return width_ == height_; }

        [[nodiscard]] bool isSymmetric() const;

        [[nodiscard]] bool isDiagonal() const;

        [[nodiscard]] bool isIdentity() const;

        [[nodiscard]] bool isUpperTriangular() const;

        [[nodiscard]] bool isLowerTriangular() const;

        [[nodiscard]] bool isTriangular() const { return isUpperTriangular() || isLowerTriangular(); }

        [[nodiscard]] bool isZero() const;

        [[nodiscard]] bool isVector() const { return width_ == 1 || height_ == 1; }

        [[nodiscard]] bool isRowVector() const { return height_ == 1; }

        [[nodiscard]] bool isColumnVector() const { return width_ == 1; }

    private:
        double *values_;
        int width_, height_;
    };


    void printMatrix(Matrix2 const &mat);

    Matrix2 inverse(Matrix2 const &mat);

    Matrix2 transpose(Matrix2 const &mat);

    Matrix2 zeros(int height, int width);

    Matrix2 ones(int height, int width);

    Matrix2 eye(int height, int width);

    Matrix2 random(int height, int width);
}

