#include "triangular_matrix.h"
#include <square_matrix.h>
#include <complex.h>
#include <matrix.h>
#include <iostream>
#include <stdio.h>

template <class T>
std::istream& operator>>(std::istream&i, triangular_matrix<T>&A) {
    
    unsigned int l,j,k;
    std::cout<<"0->inferior triunghiulara//1->superior triunghiulara.\n";
    
    i >> k;
    
    for(j = 0;j < A.dim1;j++)
        delete [] A.mat[j];
    
    delete [] A.mat;
   
    i >> A.dim1 >> A.dim2;

    A.mat = new complex<T>* [A.dim1];
    
    for(j = 0; j < A.dim1; j++)
        A.mat[j] = new complex<T>[A.dim2];

    fflush(stdin);

    if(k)
        for (l = 0 ; l < A.dim1; l++)
            for  (j = 0 ; j <= l ; j++)

                i>>A.mat[l][j];
    else

        for (l = 0 ; l < A.dim1; l ++)
            for  (j = l ; j < A.dim1; j ++)

                i >> A.mat[l][j];

    return i;
}

template <class T>
std::ostream& operator<<(std::ostream& o,triangular_matrix<T> A) {
    matrix<T> *B=&A;
    o<<(*B);

    return o;
}

template <class T>
complex<T> triangular_matrix<T>::determinant() {
    unsigned int i;

    complex<T> p(1,0);
    for (i = 0; i < this->dim1; i++)
        p = p * this->mat[i][i];

    return p;
}

template <class T>
int  triangular_matrix<T>::test() {
    
    if(this->dim1 == 1)
        return 0;

    complex<T> p;
    unsigned int i,j;

    for(i = 0 ; i < this->dim1 ; i++)
        for(j = 0 ; j<this->dim1; j++)
            if(this->mat[i][j] != p && i != j)

                return -1;

    return 1;
}