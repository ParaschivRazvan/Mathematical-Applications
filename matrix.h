#ifndef MATRIX_H
#define MATRIX_H

template <class T>
class matrix;

template <class T>
std::istream& operator>>(std::istream& i,matrix<T>&A);

template <class T>
std::ostream& operator<<(std::ostream& o,matrix<T> A);

template <class T>
class matrix {

public:

    matrix<T>(unsigned int n=1,unsigned int m=1);

    matrix<T>(const matrix<T>&);

    matrix<T>& operator =(matrix<T>);

    virtual ~matrix<T>();

    friend std::istream& operator>>(std::istream&,matrix<T>&);

    friend std::ostream& operator<<(std::ostream&,matrix<T>);

protected:

    complex<T> **mat;

    unsigned int dim1,dim2;

};


#endif // MATRIX_H
