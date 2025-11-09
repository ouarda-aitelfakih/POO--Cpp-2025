#include<iostream>
#include<string>
using namespace std;

class Client{
    private:
       string nom;
       string CIN;
       int Identifiant_client;

    public:
    //constructeurs
      Client():nom(""),CIN(""),Identifiant_client(0){}
      Client(string n,string cin,int Id):nom(n),CIN(cin),Identifiant_client(Id){}
      
   friend class Banque;

};

class Compte{
     private:
      int nbr_compte;
      int solde;
      Client& client;
      int code_secret;
      friend class AgentBancaire;
      friend class Banque;

      //constructeurs
      public:
       Compte(int nbr,int s,Client c1,int c):nbr_compte(nbr),solde(s),client(c1),code_secret(c){}

};

class AgentBancaire{
    public:
    
     void consulter_le_code_secret(Compte& c){
         cout<<"le code secret est : "<<c.code_secret<<endl;
     }
     void transferer(Compte& source,Compte& destinataire,float montant){
        if(montant>source.solde){
            cout<<"impossible de transferer ce montant votre solde est inssuffisant"<<endl;
            return;
        }
        else{
            source.solde=source.solde-montant;
            destinataire.solde=destinataire.solde+montant;
        }
     }
     
      

};
class Banque{
    private:
    Client *client[100];
    Compte *compte[100];
    int nbr_client;
    int nbr_compte;
    public:
    Banque():nbr_client(0),nbr_compte(0){}


    void AjouterClient(Client& c){
        if(nbr_client<100){
           client[nbr_client]=&c;
                nbr_client++;
         }
         else{
            cout<<"le capacité est maximum"<<endl;
         }
         
        } 
    void AjouterCompte(Compte& C){
        if(nbr_compte<100){
           compte[nbr_compte]=&C;
                nbr_compte++;
         }
         else{
            cout<<"le capacité est maximum"<<endl;
         }
         
        } 

    void affichage(){
        cout<<"les clients:"<<endl;
        for(int i=0;i<nbr_client;i++){
            cout<<"client"<<i+1<<" : "<<endl;
            cout<<"le nom: "<<client[i]->nom<<endl;
            cout<<"CIN: "<<client[i]->CIN<<endl;
            cout<<"Identifiant client : "<<client[i]->Identifiant_client<<endl;
        }
        cout<<"les comptes:"<<endl;
        for(int i=0;i<nbr_compte;i++){
            cout<<"compte"<<i+1<<" : "<<endl;
            cout<<"numero de compte :"<<compte[i]->nbr_compte<<endl;
            cout<<"le solde : "<<compte[i]->solde<<endl;
            cout<<"le code secret : "<<compte[i]->code_secret<<endl;
            
        }
    }
       

};
int main (){
    //creation des clients et des comptes
    Client *client1=new Client("ahmed","L123456",123456789);
    Client *client2=new Client("salma","X654321",987654321);

    Compte *compte1=new Compte(1234,200000,*client1,0000);
    Compte *compte2=new Compte(5678,500000,*client2,1111);

    Banque banque;
    banque.AjouterClient(*client1);
    banque.AjouterClient(*client2);
    banque.AjouterCompte(*compte1);
    banque.AjouterCompte(*compte2);
    banque.affichage();

    AgentBancaire agentbancaire;
    agentbancaire.consulter_le_code_secret(*compte2);
    agentbancaire.transferer(*compte1,*compte2,10);
    cout<<"affichage apres transfer"<<endl;
    banque.affichage();

    return 0;


}