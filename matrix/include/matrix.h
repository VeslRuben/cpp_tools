//
// Created by itzRu on 01.09.2021.
//
#pragma once
#include "list"

namespace Matrix {
    class Matrix2 {
    public:
        Matrix2();

        Matrix2(int height, int width);

        Matrix2(int height, int width, const double *values);

        Matrix2(int height, int width, const std::list<double> &values);

        Matrix2(const Matrix2 &old_obj);  // copy constructor

        Matrix2(Matrix2 &&old_obj) noexcept ;  // move constructor

        ~Matrix2();

        // #####################################
        // Operator overloads #################
        // #####################################
        Matrix2 &operator=(const Matrix2 &oldMatrix);

        Matrix2 &operator=(Matrix2 &&oldMatrix) noexcept;

        bool operator==(const Matrix2 &mat) const;

        bool operator!=(const Matrix2 &mat) const;

        // Matrix2 Operators ####################
        Matrix2 operator+(Matrix2 const &mat) const;

        Matrix2 operator+=(Matrix2 const &mat);

        Matrix2 operator-(Matrix2 const &mat) const;

        Matrix2 operator-=(Matrix2 const &mat);

        Matrix2 operator*(Matrix2 const &mat) const;

        Matrix2 operator*=(Matrix2 const &mat);
        // ######################################

        // Scaler Operators
        Matrix2 operator+(double scalar);

        Matrix2 operator+=(double scalar);

        Matrix2 operator-(double scalar);

        Matrix2 operator-=(double scalar);

        Matrix2 operator*(double scalar);

        Matrix2 operator*=(double scalar);
        // ######################################

        double operator[](int i);

        double operator()(int row, int col) const;
        // #####################################
        // #####################################

        void resize(int height, int width);

        [[nodiscard]] Matrix2 transpose() const;

        [[nodiscard]] Matrix2 T() const { return transpose(); }

        [[nodiscard]] double determinant() const;

        [[nodiscard]] Matrix2 inverse() const;

        [[nodiscard]] Matrix2 subMatrixWithoutRowAndCol(int row, int col) const;

        [[nodiscard]] double get(int row, int col) const;

        void put(double newValue, int row, int col);

        [[nodiscard]] int getWidth() const;

        [[nodiscard]] int getHeight() const;

    private:
        double *values_;
        int width_, height_;
    };


    void printMatrix(Matrix2 &mat);

    Matrix2 inverse(Matrix2 const &mat);

    Matrix2 transpose(Matrix2 const &mat);

    Matrix2 zeros(int height, int width);
}

