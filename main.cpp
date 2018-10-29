#include <iostream>
#include <complex.h>
#include <Matrice.h>
#include <Matrice_patratica.h>
#include <Matrice_triunghiulara.h>
#include <new>
using namespace std;

int main()
{
  try{
      complex<int> z,b;


square_matrix<int> B(1000),A(B);
//cin>>A;
//cout<<A;
//cin>>A;
//cout<<A;
//cout<<A.determinant();


z/b;

}catch(int a)
{
    cout<<"Impartire la "<<a<<" nepermisa.\n";
}
catch(std::bad_alloc& e)
{
    std::cerr << "Bad allocation found: " << e.what() << '\n';

}
/*cin>>B;
cout<<B;

cout<<endl<<B.determinant();

Matrice_patratica<int> *C=&A,*D=&B;
cout<<C->determinant();
cout<<D->determinant();



  cout<<A.test();
z=z+b;
cout<<z;
cin>>A;
cout<<A;
*/

    return 0;
}
