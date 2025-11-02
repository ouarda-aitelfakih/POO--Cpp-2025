#include<iostream>
#include<string>
using namespace std;
class Pile{
    private:
    //les attributs
    int *tab ;
    int taille;
    int capacité;
    
    public:
    //les méthodes
    Pile(int n=100){       //constructeur par défaut 
        tab=new int [n];
        taille=0;
        capacité=n;
    }
    //push: empiler un élément sur la pile
    void push(int valeur){
        //verifier si la pile est pleine!
        if(taille>=capacité){
            cout<<"la pile est pleine"<<endl;
            return ;
        }
        tab[taille]=valeur;
        taille++;
    }
    //pop :dépiler un élément de la pile
    void pop(){
        if(taille<=0){
            cout<<"la pile est vide"<<endl;//verifier si la pile est vide
            return ;
        }
        taille--;
        cout<<"l'entier au sommet est retiré"<<endl;

    }
    //fonction pour afficher la pile
    void afficher(){
    if(taille <= 0){
        cout << "La pile est vide" << endl;
        return;
    }
    cout << "Contenu de la pile : ";
    for(int i = taille - 1; i >= 0; i--){
        cout<<endl;
        cout << tab[i] << " "<<endl;
    }
    cout << endl;
}
};
int main (){
    Pile P1,P2;
    P1.push(3);
    P1.push(5);
    P1.push(10);
    P1.push(15);

    P1.pop();
    P1.afficher();
    return 0;
}