#include<iostream>
#include<string>
using namespace std;

class Ressource{
//attributs protégés
protected:
int id;
string titre;
string auteur;
int annee;


public:
//constructeur par défaut
Ressource(){
    id=0;
    titre="";
    auteur="";
    annee=0;
}
//constructeur de paramètre 
Ressource(int Id,string t,string a,int n):id(Id),titre(t),auteur(a),annee(n){}

//les méthodes
//on utilise virtual parceque les méthodes de la classe de base va être redéfiner dans la classe dérivée
virtual void afficherInfos(){
    cout<<"============================"<<endl;
    cout<<"l'identifiant:"<<id<<endl;
    cout<<"le titre:"<<titre<<endl;
    cout<<"auteur:"<<auteur<<endl;
    cout<<"annee:"<<annee<<endl;
    cout<<"============================"<<endl;
}
virtual void telecharger(){
    cout<<"telechargement en cours......"<<endl;
}
//getter pour acceder au variable titre
string get_titre() const{return titre;}
//getter pour acceder à la valeur de annee
int get_annee() const{return annee;}
//getter pour acceder au variable auteur
string get_auteur() const {return auteur;}

//surcharge de l'opérateur ==
bool operator ==(const Ressource& autre) const{//on utilise const pour s'assurer que la valeur de la  méthode et de l'Id ne seront pas changer
    return id==autre.id;
}

//destructeur
virtual ~Ressource(){}
};


class Telechargeable{
    public:
    void telecharger(){
        cout<<"telechargement ......"<<endl;
    }
    void afficherMessage(){
        cout<<"le fichier est telechargeable"<<endl;
    }

};
//classes dérivées de Ressource en ajoutant des attributs spécifiques et en redéfinir les méthodes 
class Livre:public Ressource,public Telechargeable{

    private:
    int nbrpage;
    public:
    //constructeur par paramètre
    Livre(int Id,string t,string a,int n,int nbr):Ressource(Id,t,a,n),nbrpage(nbr){}

    void afficherInfos(){
    cout<<"============================"<<endl;
    cout<<"l'identifiant:"<<id<<endl;
    cout<<"le titre:"<<titre<<endl;
    cout<<"l'auteur:"<<auteur<<endl;
    cout<<"l'annee:"<<annee<<endl;
    cout<<"le nombre de pages :"<<nbrpage<<endl;
    cout<<"============================"<<endl;
    }
    void telecharger(){
        cout<<"telechargement du PDF du livre en cours......."<<endl;
    }
};

class Magazine:public Ressource,public Telechargeable{
    private:
    int prix;
    public:
     //constructeur par paramètre
    Magazine(int Id,string t,string a,int n,int p ):Ressource(Id,t,a,n),prix(p){}

    void afficherInfos(){
    cout<<"============================"<<endl;
    cout<<"l'identifiant:"<<id<<endl;
    cout<<"le titre:"<<titre<<endl;
    cout<<"l'auteur:"<<auteur<<endl;
    cout<<"annee:"<<annee<<endl;
    cout<<"le l'prix :"<<prix<<"DH"<<endl;
    cout<<"============================"<<endl;
    }
    void telecharger(){
        cout<<"telechargement du PDF du magazine en cours......."<<endl;
    }

};
class Video:public Ressource,public Telechargeable{
    private:
    int duree;
    public:
    //constructeur par paramètre
    Video(int Id,string t,string a,int n,int d):Ressource(Id,t,a,n),duree(d){}

    void afficherInfos(){
    cout<<"============================"<<endl;
    cout<<"l'identifiant:"<<id<<endl;
    cout<<"le titre:"<<titre<<endl;
    cout<<"l'auteur:"<<auteur<<endl;
    cout<<"l'annee:"<<annee<<endl;
    cout<<"la duree:"<<duree<<"min"<<endl;
    cout<<"============================"<<endl;
    }
    void telecharger(){
        cout<<"telechargement du video en cours......."<<endl;
    }
};

class Mediatheque{

    private:
    Ressource *ressource[100];
    int count;
    public:
    //initialiser count à 0
    Mediatheque():count(0){}

    void Ajouter(Ressource *res){
        if(count<100){
            ressource[count]=res;
            count++;
        }
        else
        cout<<"la mémoire est plienne"<<endl;
    }
    void Afficher(){
        for(int i=0;i<count;i++){
            ressource[i]->afficherInfos();
        }
    }
    void Rechercher(string titre){
       int match=0;
       for(int i=0;i<count;i++){
          if(ressource[i]->get_titre()==titre){
             cout<<"la ressource recherché est :";
             ressource[i]->afficherInfos();
             cout<<endl;
             match=1;
          }
       }
       if(match==0){
        cout<<"la ressource contient le titre :"<<titre<<"n'est pas trouve"<<endl;
       }
    }

    void Rechercher(int annee){
        int match=0;
        for(int i=0;i<count;i++){
            if(ressource[i]->get_annee()==annee){
                cout<<"la ressource recherché est :";
                ressource[i]->afficherInfos();
                match=1;
            }
        }
        if(match==0){
            cout<<"la ressource recherché par l'annee : "<<annee<<"est pas trouvée"<<endl;
        }
    }

    void Rechercher(string auteur,int annee){
        int match=0;
        for(int i=0;i<count;i++){
            if(ressource[i]->get_auteur()==auteur && ressource[i]->get_annee()==annee){
                cout<<"la resource rechercher est :";
                ressource[i]->afficherInfos();
                match=1;
            }
        }
        if(match==0){
            cout<<"la ressource recherché par l'annee : "<<annee<<"et par l'auteur :"<<auteur<<"est pas trouvée"<<endl;
        }
    }
    

};
int main(){
    //creation des objets
    Ressource res1(1,"titre1","auteur1",2024);

    Livre livre1(1,"titre2","auteur2",2025,300);
    Magazine magazine1(3,"titre3","auteur3",2023,100);
    Video video1(4,"titre4","auteur4",2022,15);

    //tester afficherInfo()
    res1.afficherInfos();
    livre1.afficherInfos();
    magazine1.afficherInfos();
    video1.afficherInfos();

    //tester telecharger()
    res1.telecharger();
    //on spécifier la version de télécharger utiliser pour éviter toute confusion
    livre1.Ressource::telecharger();
    livre1.Telechargeable::telecharger();
    magazine1.Ressource::telecharger();
    magazine1.Telechargeable::telecharger();
    video1.Ressource::telecharger();
    video1.Telechargeable::telecharger();
    
    //tester opérateur==
    if(res1==livre1){
        cout<<"les deux ressources ont des Ids identiques"<<endl;
    }
    else{
        cout<<"les deux ressources n' ont pas des Ids identiques"<<endl;
    }

    return 0;
}