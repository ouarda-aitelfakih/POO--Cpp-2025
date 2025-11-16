#include<iostream>
#include<string>
#include<exception>
using namespace std;

class PilePleineException : public exception {
public:
    const char* what() const throw() {
        return "Erreur: La pile est pleine !";
    }
};

class PileVideException : public exception {
public:
    const char* what() const throw() {
        return "Erreur: La pile est vide !";
    }
};

class ArgumentInvalideException : public exception {
public:
    const char* what() const throw() {
        return "Erreur: L'argument doit etre positif !";
    }
};

class Stack{
    private:
    int *tab;
    int taille;
    int capacite;
    public:
    Stack(int n=20){
        if(n<=0){
            throw ArgumentInvalideException();
        }
        tab=new int[n];
        taille=0;
        capacite=n;
    }
    Stack(const Stack& autre){
        taille=autre.taille;
        capacite=autre.capacite;
        tab=new int [capacite];
        for(int i=0;i<taille;i++){
            tab[i]=autre.tab[i];
        }
    }
    ~Stack(){
        delete [] tab;
    }
    Stack& operator==(const Stack& )=delete;//interdit l'affectation
    Stack& operator<<(int n){
        //verifie si la pile est pleine
        if(taille>=capacite){
            throw PilePleineException();
            
        }
        tab[taille]=n;
        taille++;
        return *this;
    }
    Stack& operator>>(int& n){
        //verifie si la pile contient seulement l'element n
        if(taille==0){
            throw PileVideException();
            
        }
        n=tab[taille-1];
        taille--;
        return *this;
        }
        
    
    bool operator++()const{
        if(taille>=capacite){//pliene
            return true;
        }
        return false;
    }
    bool operator--()const{
        if(taille==0){//vide
            return true;
        }
        return false;
    }

};

int main(){
    try {
        Stack p(5);
        p << 1 << 2 << 3 << 4 << 5;
    }
    catch(PilePleineException& e){
        cout << e.what() << endl;
    }
    
    try {
        Stack p2(3);
        int x;
        p2>>x;
        
    }
    catch(PileVideException& e){
        cout << e.what() << endl;
    }
    
    return 0;
}
