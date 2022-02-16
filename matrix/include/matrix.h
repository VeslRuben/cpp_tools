//
// Created by itzRu on 01.09.2021.
//

#ifndef MATRIX_H
#define MATRIX_H


namespace Matrix {
    class Matrix2 {
    public:
        Matrix2();

        Matrix2(int height, int width);

        Matrix2(int height, int width, const double *values);

        Matrix2(int height, int width, const std::list<double> &values);

        Matrix2(const Matrix2 &old_obj);  // copy constructor

        ~Matrix2();

        // #####################################
        // Operator overloads #################
        // #####################################
        Matrix2 &operator=(const Matrix2 &oldMatrix);

        bool operator==(const Matrix2 &mat) const;

        bool operator!=(const Matrix2 &mat) const;

        // Matrix2 Operators ####################
        Matrix2 operator+(Matrix2 &mat);

        Matrix2 operator+=(Matrix2 &mat);

        Matrix2 operator-(Matrix2 &mat);

        Matrix2 operator-=(Matrix2 &mat);

        Matrix2 operator*(Matrix2 &mat);

        Matrix2 operator*=(Matrix2 &mat);
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

        double operator()(int row, int col);
        // #####################################
        // #####################################

        void resize(int height, int width);

        void transpose();

        double get(int row, int col);

        void put(double newValue, int row, int col);

        [[nodiscard]] int getWidth() const;

        [[nodiscard]] int getHeight() const;

    private:
        double *values_;
        int width_, height_;
    };
}
#endif //MATRIX_H
