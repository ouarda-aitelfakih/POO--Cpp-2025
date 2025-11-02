#include<iostream>
#include<string>
using namespace std;
class Fichier{
    //attributs
    private:
    int *adresse ;
    int longueur;
    public:
    //les méthodes:

    //constructeur par défaut pour initialiser les paramètres 
    Fichier(){
        adresse=NULL;
        longueur=0;  
    }
    void creation(int taille){
        adresse=new int[taille];
        longueur=taille;
    }
    void remplir(){
        adresse[0]=1;
        adresse[1]=2;
        adresse[2]=3;
        adresse[3]=4;
        adresse[4]=5;
    }
    
    void afficher(){
        for(int i=0;i<longueur;i++){
            cout<<"adresse["<<i<<"]="<<adresse[i]<<endl;
        }
    }
    
    //destructeur
    ~Fichier(){
        delete[] adresse;
    } 
};
int main (){
    Fichier *f=new Fichier();
    f->creation(6);
    f->remplir();
    f->afficher();
    delete f;//détruire notre objet f
    return 0;
    //destructeur appelé à la fin du programme 
}