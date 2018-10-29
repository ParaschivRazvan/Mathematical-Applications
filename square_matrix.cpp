#include "square_matrix.h"
#include <matrix.h>
#include <complex.h>
#include <stdlib.h>

template <class T>
std::istream& operator>>(std::istream& i, square_matrix<T>&A) {
    
    matrix<T> *B=&A;
    i>>(*B);

    return i;
}

template <class T>
std::ostream& operator<<(std::ostream& o, square_matrix<T> A) {

    matrix<T> *B=&A;
    o<<(*B);
    
    return o;
 }

template <class T>
complex<T> square_matrix<T>::determinant() {
    unsigned int n = this->dim1;
    complex<T> det=0;
    BKT(0,det,n,this->mat);

    return det;
}

bool verify(int k, int*x ) {
    int i;
    for (i = 0 ; i < k ; i ++)
        if(x[k] == x[i])
            return false;
    return true;
}

int parity(int n,int*x) {
    int inv=0,i,j;
    for(i = 0; i < n; i++)
        for(j = i - 1; j >= 0; j--)
            if(x[j] > x[i])
                
                inv++;
    return inv;
}

template <class T>
complex<T> product(int n,int *x, complex<T> **&m) {
    
    int i;
    complex<T> p(1);
    
    for (i = 0; i < n; i++)
        
        p = p * m[i][x[i]];

    if(parity(n,x)%2)

        return -p;

    return p;
}

template <class T>
void BKT(unsigned int k,complex<T> &s, unsigned int &n, complex<T>**&m) {
    
    unsigned int i;
    static int x[100];

    for(i = 0; i < n; i++) {
        
        x[k] = i;

        if(verify(k,x)) {
            if(k == n-1) 
                s = s + product(n,x,m);
            else
                BKT(k+1,s,n,m);
        }
    }
}