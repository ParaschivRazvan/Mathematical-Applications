#include "complex.h"
#include <iostream>
#include <math.h>
#include <string.h>
#include <cstdlib>


template <class T>
bool complex<T>::operator ==(complex <T> x) {
    
     return Re == x.Re && Im == x.Im ;
}

template <class T>
bool complex<T>::operator !=(complex <T> x) {

    return Re != x.Re && Im != x.Im ;
}

template <class T>
complex<T>::complex(const complex<T> & x) {

    Re = x.Re;
    Im = x.Im;

}

template <class T>
std::istream& operator>>(std::istream& i,complex<T>& x) {
    
    char s[30],*f;
    i.getline(s,30);
    f = strchr(s,'i');
    
    if(!f) {
        x.Im = 0;
        x.Re = (T)atof(s);
    } 
    else {
        x.Re = (T)atof(s);

        if(f[1] == '*')
            x.Im=(T)atof(f+2);
        else
            x.Im=1;

        if(strchr(f-1,'-'))
            x.Im=-x.Im;
    }

    return i;
}

template <class T>
std::ostream& operator<<(std::ostream& o, complex<T> x) {
    
    if(x.Re || ( !x.Re  && !x.Im) ) o<<x.Re;
    
    if(x.Im>0 && x.Re ) o<<"+";
    else if(x.Im<0)
        o<<"-";
    
    if(x.Im==1) 
        o<<"i";
    else if(x.Im==-1) 
        o<<"i";
    else if(x.Im!=0)
        o<<"i*"<<std::abs(x.Im);
    return o;
}

template <class T>
complex<T> complex<T>::operator +(const complex<T> y) {

    complex<T> z;

    z.Re = Re + y.Re;
    z.Im = Im + y.Im;

    return z;
}

template <class T>
complex<T> complex<T>::operator -(const complex<T> y) {
    
    complex<T> z;

    z.Re = Re - y.Re;
    z.Im = Im - y.Im;

    return z;
}

template <class T>
complex<T> complex<T>::operator *( const complex<T> y) {

    complex<T> z;

    z.Re = Re * y.Re - Im * y.Im;
    z.Im=Im * y.Re + Re * y.Im;

    return z;
}

template <class T>
complex<T> complex<T>::operator / (const complex<T> y) {

    if(!y.Re&&!y.Im)

       throw 0;

    complex<T> z;

    z.Re = y.Re;
    z.Im = -y.Im;

    return ((*this)*z)/(z.Re*z.Re+z.Im*z.Im);
}

template <class T>
complex<T> complex<T>::operator +() {
    
    return *this;
}

template <class T>
complex<T> complex<T>::operator -() {
    complex<T> z;

    z.Re = -Re;
    z.Im = -Im;

    return z;
}

