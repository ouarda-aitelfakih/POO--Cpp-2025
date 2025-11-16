//a.On a créé une template de classe où on a déclaré un constructeur 
//pour la classe point qui a deux paramètres de type T et qui a pour méthode affiche().
// Ensuite, on a déclaré une méthode template qui affiche les coordonnées du point 
//selon le type T.
//comme on a déclaré un objet de type point<char>, les valeurs 60 et 65 
//sont stockées comme des caractères. Lorsque cout affiche un char, il affiche 
//le caractère ASCII correspondant et non la valeur numérique.
// Ainsi, 60 devient '<' et 65 devient 'A'.

//b.Pour afficher les valeurs numériques 60 et 65 au lieu des caractères,
// il faut convertir x et y en int dans la méthode affiche() en utilisant
// (int)x et (int)y.
#include<iostream>
using namespace std;
template <class T> class point{ 
T x, y ; // coordonnees
public :
point (T abs, T ord) { x = abs ; y = ord ; }
void affiche () ;
} ;

template <class T> void point<T>::affiche (){ 
    cout << "Coordonnees : " << (int)x << " " << (int)y << "\n" ;
}
int main(){

      point<char>p(60,65);
      p.affiche();

}