#include <iostream>
using namespace std ;

main () {
int i, j, n ;

i = 0 ;
n = i++ ;                                         //n=0 et i=1
cout << "A : i = " << i << " n = " << n << "\n" ;//A:i=1 n=0

i = 10 ;
n = ++ i ;                                        //n=11 et i=11
cout << "B : i = " << i << " n = " << n << "\n" ;//B:i=11 n=11


i = 20 ;
j = 5 ;                                          //i=21 ,j=6 et n=120
n = i++ * ++ j ;                                //C:i=21 j=6 n=120
cout << "C : i = " << i << " j = " << j << " n = " << n << "\n" ;

i = 15 ;                                       //i=18 n=18
n = i += 3 ;                                  //D:i=18 n=18
cout << "D : i = " << i << " n = " << n << "\n" ;
 
i = 3 ;
j = 5 ;                                      //i=12,j=4et n=12
n = i *= --j ;                              //E:i=12 j=4 n=12
cout << "E : i = " << i << " j = " << j << " n = " << n << "\n" ;
         //l'affichage:
        //A:i=1 n=0
        //B:i=11 n=11
        //C:i=21 j=6 n=120
        //D:i=18 n=18
        //E:i=12 j=4 n=12
return 0;
}
