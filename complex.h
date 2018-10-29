#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <math.h>
#include <string.h>
#include <cstdlib>


template <class T>
class complex;


template<class T>
std::istream& operator>>(std::istream& i, complex<T> &x);


template<class T>
std::ostream& operator<<(std::ostream& o, complex<T> x);


template <class T>
class complex {

    T Re,Im;

public:
    complex<T> (T i=0, T j=0):Re(i),Im(j) {};

    complex<T>(const complex<T>&);


    friend std::istream& operator >> <T>(std::istream&, complex<T>&) ;

    friend std::ostream& operator<< <T>(std::ostream&, complex<T>);

    complex<T> operator +(const complex<T>);

    complex<T> operator-(const complex<T>);

    complex<T> operator*(const complex<T>);

    complex<T> operator/(const complex<T>);

    complex<T> operator +();

    complex<T> operator -();

    bool operator == (complex<T>);

    bool operator != (complex<T>);

};

#endif // COMPLEX_H
