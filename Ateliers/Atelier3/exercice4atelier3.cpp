#include<iostream>
#include<string>
using namespace std;
class Client{
    //les attributs
    private:
    int id;
    string nom;
    string prenom;
    
    public:
    //les constructeurs
    Client(){  //constructeur par défaut 
        id=0;
        nom="";
        prenom="";
    }
    Client(int i,string n,string p){ //constructeur paramétré
        id=i;
        nom=n;
        prenom=p;
    }
    Client(const Client&autre){//on n'a pas besoin de constructeur de copie profonde parce qu'on n'a pas de pointeurs pour allouer la mémoire
        id=autre.id;
        nom=autre.nom;
        prenom=autre.prenom;

    }
    ~Client(){
        //pas besoin de destructeur ici parce qu' on n'a pas de la mémoire à libèrer 
        cout<<"destructeur est appele"<<endl;
    }
    void afficher(){
        cout<<"=========================================="<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"nom: "<<nom<<endl;
        cout<<"prenom: "<<prenom<<endl;
        cout<<"============================================"<<endl;

    }
    //pour cette class on a pas besoin d'une copie profonde parce qu'on a pas un pointeur
    //donc pas d'allocation de la mémoire:le destructeur n'est pas indispensable
};



class Compte{
    //les attributs
    private:
    int numero;
    float solde;
    Client* client;
    static int nbr_de_compt;
    public:
    //les constructeurs
    Compte(){   //sans paramètre
        numero=0;
        solde=0;
        client=NULL;
        nbr_de_compt++;//incrémenter le compteur
    }
    Compte(int n,float s,Client* c){//avec paramètres
        numero=n;
        solde=s;
        if(c!=NULL){//vérification du cas où aucun client n'est fourni
            client=new Client(*c);
        }
        else{
            client=NULL;
        }
        nbr_de_compt++;//incrémentation de compteur

    }
    Compte(const Compte& autre){//constructeur de copie
        numero=autre.numero;
        solde=autre.solde;
        //ici on a une copie profonde parce qu'on a un pointeur
        //aussi on vérifie si la copie de client est NULL où pas
        if(autre.client != NULL){
            client=new Client(*(autre.client));
        }
        else{
            client=NULL;
        }
        nbr_de_compt++;//incrémenter le compteur
        

    }
    //ici on a besoin d'un destructeur pour libèrer la mémoire parce qu 'ona utiliser une copie profonde
    ~Compte(){
        delete client;
        nbr_de_compt--;//décrémenter le compteur
    }

    void affichage(){
        cout<<"============================="<<endl;
        cout<<"le numero de compte: "<<numero<<endl;
        cout<<"le solde : "<<solde<<endl;
        cout<<"les informations du client"<<endl;
        if(client!=NULL){
            client->afficher();
        }
        else{
            cout<<"aucun client existant"<<endl;
        }
        
    }
    static void nbr_de_compt_existant(){
        cout<<"le nombre de compte existant est :"<<nbr_de_compt<<endl;

    }
    //créer un getter pour pouvoir lire le variable solde pour la fonction calculInteret
    float getSolde() const { 
        return solde; 
    }
    //créer in setter pour pouvoir changer la valeur de la variable solde
    void setSolde(float s) { 
        solde = s; 
    }
    

};
//unitiaisaser la variable statique
int Compte::nbr_de_compt = 0;

//une fonction inline parce qu'on a une opération en un seul ligne ;calcul direct
inline float calculInteret(float solde,float taux){
        return solde+(solde*taux/100);
    }

int main (){
    cout<<"||=====================================||"<<endl;
    cout<<"||         creation des clients        ||"<<endl;
    cout<<"||=====================================||"<<endl;
    //par défaut
    Client client0;
    //paramètré
    Client client1 (1, "Alami", "Ahmed");
    Client client2 (2, "Bennani", "Fatima");
    Client client3 (3, "el alawi", "Karim");
    Client client4 (4, "Tazi", "Amina");
    //par copie
    Client client1_copie=client1;
    Compte::nbr_de_compt_existant();

    cout<<"||=====================================||"<<endl;
    cout<<"||         creation des comptes        ||"<<endl;
    cout<<"||=====================================||"<<endl;

    //par défaut
    Compte compte0;
    //paramètré
    Compte compte1 (1234567,20000,&client1);
    Compte compte2 (123456,30000,&client2);
    Compte compte3 (12345,40000,&client3);
    Compte::nbr_de_compt_existant();
    {
        Compte compte4 (1234,50000,&client4);//suppression automatique par le destructeur 
    }
    Compte::nbr_de_compt_existant();
    //de copie
    Compte compte1_copie=compte1;
    cout << "\nCompte original:" << endl;
    compte1.affichage();
    cout << "Compte copie:" << endl;
    compte1_copie.affichage();
    Compte::nbr_de_compt_existant();
    
    
    //Appliquer des intérêts sur certains comptes à l’aide de la fonction calculInteret()
    cout<<"appliquer 2,5 de l'interet sur le compte1"<<endl;
    float nouveauSolde = calculInteret(compte1.getSolde(), 2.5);  // Besoin d'un getter
    compte1.setSolde(nouveauSolde);  // Besoin d'un setter
    compte1.affichage();
    
    // Afficher le nombre de comptes
    Compte::nbr_de_compt_existant();
    
    return 0;
    //destructeur appele 10 fois pour 5 clients(on a 6 client mais le client associe au compte temporaire va être libèrer) et pour 5 comptes+compte(temporaire)
    
}
//===================================================================================
//                              questions de réflexion
//===================================================================================

//1.la diférence en le constructeur de copie superficielle et  profonde
//superficielle crée une  copie du pointeur et profonde crée une nouvelle copie de l'objet pointé

//2.Pourquoi le compteur doit être statique ?
//Pour être partagé entre toutes les objets de la classe

//3.Différence entre la méthode statique et la méthode normale 
// Méthode normale : liée à une instance (peut accéder aux attributs)
// Méthode statique : liée à la classe (ne peut accéder qu'aux variables statiques)

//4. Quand utiliser inline?
//  Fonctions simples courtes 

//5. Si on oublie delete dans le destructeur 
//on va avoir une fuite mémoire , la mémoire n'est jamais libérée


               
