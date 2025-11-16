//Le programme va donner :
//dans f : 999
//suite main
//Explication :
//On appelle la fonction f() dans le bloc try de main(). Dans f(), on crée un objet A(1)
//on a une exception . Cette exception est immédiatement attrapée par le catch dans f(), 
//qui affiche "dans f : 999"
//Quand on retourne dans main(), il n'y a plus d'exception à gérer, donc le catch 
//de main() n'est pas exécuté. Le programme continue alors avec l'instruction 
//suivante et affiche "suite main".
#include <iostream>
using namespace std ;
class erreur{ public :
int num ;
} ;
class A{ public :
A(int n){ if (n==1) { erreur er ; er.num = 999 ; throw er ; }
     }
};
void f(){
     try{ 
        A a(1) ;
     }
catch (erreur er){ 
    cout << "dans f : " << er.num << "\n" ;
}
}

int main(){ 
void f() ;
try{ 
    f() ;//on appelle la fonction f(),il va donner une exception il va être atrappé par catch et il affiche "dans f:999"
}
catch (erreur er){ 
    cout << "dans main : " << er.num << "\n" ;
}
cout << "suite main\n" ;
return 0;
} 

