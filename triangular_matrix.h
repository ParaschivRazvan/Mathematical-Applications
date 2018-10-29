#ifndef TRIANGULAR_MATRIX_H
#define TRIANGULAR_MATRIX_H
#include <square_matrix.h>
#include <complex.h>
#include <matrix.h>
#include <iostream>
#include <stdio.h>

template <class T>
class triangular_matrix;

template <class T>
std::istream& operator>>(std::istream& i,triangular_matrix<T>&A);

template <class T>
std::ostream& operator<<(std::ostream& o,triangular_matrix<T> A);

template <class T>
class triangular_matrix:public square_matrix<T>
{
public:

    triangular_matrix<T>(unsigned int p=1):square_matrix<T>(p) {};

    int test();

    complex<T> determinant();

    friend std::istream& operator>> <T>(std::istream&,triangular_matrix<T>&);

    friend std::ostream& operator<< <T>(std::ostream&,triangular_matrix<T>);

    ~triangular_matrix<T>() {};
};

#endif // TRIANGULAR_MATRIX_H
