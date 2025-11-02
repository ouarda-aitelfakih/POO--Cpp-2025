#include<iostream>
#include<string>
using namespace std;
//création de la structure
struct element{
       int valeur;
       element* next;
};
//création du class
class liste{
    private:
    element *p;//pointeur vers le premier élement
    public:
    //constructeur par défaut pour initialiser les paramètres
    liste(){
        p=NULL;
    }
    //méthode qui ajout un élément au début
    void ajouter(int value){
        element* newElement=new element;
        newElement->valeur= value;
        newElement->next =p;
        p=newElement;
    }
    //méthode qui supprime un élément au début 
    void supprimer(){
        if(p==NULL){//verifier si la liste est vide
            cout<<"la liste est vide!"<<endl;
            return ;
        }
        element *temp=p;//sauvegarder le premier élement
        p=p->next;//avancer le pointeur
        cout<<temp->valeur<<"est supprimer"<<endl;
        delete temp;//libèrer la mémoire
    }
    //méthode qui affiche les éléments de la liste
    void afficher(){
        element *temp=p;//pour ne pas perdre la valeur du premier élement 
        while(temp!=NULL){
            cout<<temp->valeur<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    //destructeur
    ~liste(){
        while(p!=NULL){
            element *temp=p;
            p=p->next;
            delete temp;//libère tous les élements de la liste 
        }
    }

};

int main (){
    liste liste1;
    liste1.ajouter(10);
    liste1.ajouter(20);
    liste1.ajouter(30);
    liste1.ajouter(40);
    liste1.ajouter(50);
    liste1.ajouter(60);
    liste1.supprimer();
    liste1.afficher();
    return 0;
    

}