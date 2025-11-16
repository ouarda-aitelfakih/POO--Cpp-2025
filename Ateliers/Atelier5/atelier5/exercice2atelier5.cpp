#include<iostream>
#include<exception>
using namespace std;
//les erreurs qu'on peut extrère du programme sont:
//1. X soit négative ou superieure à 9 (10 éléments dans le tableau)
//2. Y soit égale à 0 (division par 0 impossible)
//on va créer deux classes une pour gérer l'erreur de la division et une autre pour les valeurs de l'indice 
class MyexceptionDivision:public exception{
     public:
     const char* what() const throw(){
        return "la division par 0 est impossible";
     }

};
class MyexceptionIndice:public exception{
      public:
      const char* what() const throw(){
        return "l'indice doit etre entre 0 et 9(0<indice<9)";
      }
};
class Test{
      public:
      static int tableau[];
      public:
      static int division(int indice,int diviseur){
        if(indice<0 || indice>9){
          MyexceptionIndice z1;
          throw z1;
        }
        else if(diviseur==0){
          MyexceptionDivision z2;
          throw z2;
        } 
        
            return tableau[indice]/diviseur;
        
        
      }
   
};
int Test::tableau[] = {17, 12, 15, 38, 29, 157, 89, -22, 0, 5} ;

int main (){
  try{
     int x,y;
     cout<<"entrer l'indice de l'entier a diviser"<<endl;
     cin>>x;
     cout<<"entrer le diviseur"<<endl;
     cin>>y;
     cout << "Le resultat de la division est: "<< endl;
     cout <<Test::division(x,y) << endl;
     }
     catch(MyexceptionIndice &e){
      cout<<e.what();
      return 1;
     }
     catch(MyexceptionDivision &e){
      cout<<e.what();
      return 1;
     }

     
  
 return 0;
  
}