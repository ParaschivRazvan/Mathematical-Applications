#include "matrix.h"
#include <iostream>
#include <stdio.h>

template <class T>
std::istream& operator>>(std::istream& i, matrix<T>&A) {
    unsigned int k, j ;

    for(j = 0 ; j < A.dim1 ; j ++)
        
        delete [] A.mat[j];

    delete [] A.mat;


    i >> A.dim1 >> A.dim2;
    fflush(stdin);
    A.mat = new complex<T>* [A.dim1];

    for ( j = 0; j < A.dim1 ; j ++)

        A.mat[j]=new complex<T>[A.dim2];

    for(k = 0 ; k < A.dim1 ; k ++)
        for(j = 0 ; j < A.dim2 ; j ++)

            i>>A.mat[k][j];

    return i;
}

template <class T>
std::ostream& operator<<(std::ostream& o, matrix<T> A) {

    unsigned int i, j ;

    for(i = 0 ; i < A.dim1 ; i ++) {
        for(j = 0 ; j < A.dim2 ; j ++)
            
            o<<A.mat[i][j]<<" ";

        o<<"\n";
    }
    
    return o;
}

template <class T>
matrix<T>::matrix( unsigned int n,unsigned int m) {

    dim1=n;
    dim2=m;
    mat = new complex<T>*[dim1];
    unsigned int i;
    for ( i = 0; i < dim1 ; i ++)
        mat[i]=new complex<T> [dim2];
}

template <class T>
matrix<T>::matrix (const matrix<T> &A) {

    dim1=A.dim1;
    dim2=A.dim2;
    mat=new complex<T>*[dim1];
    unsigned int i,j;

    for ( i = 0; i < dim1 ; i ++)
        
        mat[i]= new complex<T> [dim2];

    for(i = 0 ; i < dim1 ; i++ )
        for(j = 0 ; j < dim2 ; j ++)

            mat[i][j]=A.mat[i][j];
}

template <class T>
matrix<T>& matrix<T>::operator =(matrix<T> A) {
    unsigned int i,j;
    for( i = 0 ; i < dim1; i ++)

       delete [] mat[i];

    delete [] mat;

    dim1=A.dim1;
    dim2=A.dim2;
    mat=new complex<T>*[dim1];

    for ( i = 0; i < dim1 ; i ++)
     
        mat[i]=new complex<T> [dim2];

    for(i = 0 ; i < dim1 ; i++ )
        for(j = 0 ; j < dim2 ; j ++)

            mat[i][j]=A.mat[i][j];

    return *this;
}

template <class T>
matrix<T>::~matrix() {

    unsigned  int i;

    for(i = 0 ; i < dim1 ; i ++)

       delete [] mat[i];

    delete [] mat;
}
