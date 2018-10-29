#ifndef square_matrix_H
#define square_matrix_H
#include <matrix.h>
#include <complex.h>
#include <stdlib.h>
template <class T>
class square_matrix;

template <class T>
 std::istream& operator>>(std::istream& i  ,square_matrix<T>&A);

template <class T>
 std::ostream& operator<<(std::ostream& o,square_matrix<T> A);

template <class T>
void BKT(unsigned int,complex<T>&a,unsigned int&b,complex<T>**&c);

template <class T>
complex<T> product (int a,int*b,complex<T>**&c);

template <class T>
class square_matrix:public matrix <T> {

public:

    square_matrix<T> (unsigned int p=1):matrix<T>(p,p) {};

    square_matrix<T> (const square_matrix&A):matrix<T>(A){};

    virtual ~square_matrix<T>() {};

    virtual complex<T> determinant();

    friend void BKT<T>(unsigned int,complex<T>&,unsigned int&,complex<T>**&);

    friend complex<T> product <T>(int,int*,complex<T>**&);

    friend std::istream& operator>><T>(std::istream& ,matrix<T>&);

    friend std::ostream& operator<<<T>(std::ostream& ,matrix<T>);


};

#endif // square_matrix_H
