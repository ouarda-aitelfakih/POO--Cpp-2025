#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class complexe{
	private:
		float reel;
		float imaginaire;
		
	public:
		//constructeur par défaut
		complexe(){
			reel=0;
			imaginaire=0;
		}
		//constructeur par paramétre
		complexe(float a, float b){
			reel=a;
			imaginaire=b;
		}
		//fonction pour saisir un nombre complexe
		void saisir(){
			cout<<"entrer la partie reel du nombre complexe"<<endl;
			cin>>reel;
			cout<<"entrer la partie imaginaire du nombre complexe"<<endl;
			cin>>imaginaire;
		}
		//fonction pour afficher un nombre complexe
		void afficher(){
			if(imaginaire>=0){
				cout<<reel<<"+"<<imaginaire<<"i"<<endl;	
			}
			else
			    cout<<reel<<"-"<<(-imaginaire)<<"i"<<endl;
		}
		//fonction pour afficher si deux nombre complexe sont egales ou non
		int egal(complexe c){
			if(reel==c.reel && imaginaire==c.imaginaire){
				return 1;
			}
			else
			    return 0;
		}
		//fonction pour afficher la somme de deux nombre complexe
		complexe addition(complexe c){
			complexe addition;
			addition.reel=reel+c.reel;
			addition.imaginaire=imaginaire+c.imaginaire;
			return addition;
		}
		//fonction pour afficher la soustraction de deux nombre complexe
		complexe soustraction(complexe c){
			complexe soustraction;
			soustraction.reel=reel-c.reel;
			soustraction.imaginaire=imaginaire-c.imaginaire;
			return soustraction;
		}
		//fonction pour afficher le produit de deux nombre complexe
		complexe multiplication(complexe c){
			complexe produit;
			produit.reel=(reel*c.reel)-(imaginaire*c.imaginaire);
			produit.imaginaire=(reel*c.imaginaire)+(imaginaire*c.reel);
			return produit;
		}
		//fonction pour afficher la division de deux nombre complexe
		complexe division(complexe c){
			complexe division;
			float denomirateur=(c.reel*c.reel)+(c.imaginaire*c.imaginaire);
			if(denomirateur==0){
				cout<<"la division par 0 est impossible"<<endl;
			}
			else{
				division.reel=(reel*c.reel)-(imaginaire*c.imaginaire)/denomirateur;
				division.imaginaire=(reel*c.imaginaire)+(imaginaire*c.reel)/denomirateur;
			 return division;
			
			}
		}	
};

int main (){
	int choix;
	complexe c1,c2,resultat;
	//saisir les nombres comlexes
	cout<<"entrer le premier nombre complexe"<<endl;
	c1.saisir();
	cout<<"entrer le deuxieme nombre complexe"<<endl;
	c2.saisir();
	
	//affichage des nombres complexes
	cout<<"c1=";c1.afficher();cout<<endl;
	cout<<"c2=";c2.afficher();cout<<endl;
	do{
		cout << "\n========== MENU DES OPÉRATIONS ==========" << endl;
    cout << "1. Verifier l'egalite" << endl;
    cout << "2. Addition" << endl;
    cout << "3. Soustraction" << endl;
    cout << "4. Multiplication" << endl;
    cout << "5. Division" << endl;
    cout << "==========================================" << endl;
    cout << "Votre choix: ";
    cin>>choix;
    
    switch(choix) {
            case 1:
                cout << "=== EGALITE ===" << endl;
                if (c1.egal(c2)) {
                    cout << "Les deux nombres complexes sont ÉGAUX" << endl;
                } else {
                    cout << "Les deux nombres complexes sont DIFFÉRENTS" << endl;
                }
                break;

            case 2:
                cout << "=== ADDITION ===" << endl;
                resultat = c1.addition(c2);
                cout << "c1 + c2 = ";
                resultat.afficher();
                cout << endl;
                break;

            case 3:
                cout << "=== SOUSTRACTION ===" << endl;
                resultat = c1.soustraction(c2);
                cout << "c1 - c2 = ";
                resultat.afficher();
                cout << endl;
                break;

            case 4:
                cout << "=== MULTIPLICATION ===" << endl;
                resultat = c1.multiplication(c2);
                cout << "c1 * c2 = ";
                resultat.afficher();
                cout << endl;
                break;

            case 5:
                cout << "=== DIVISION ===" << endl;
                resultat = c1.division(c2);
                cout << "c1 / c2 = ";
                resultat.afficher();
                cout << endl;
                break;
            
            case 0:
                cout << "Au revoir!" << endl;
                break;

            
            default:
                cout << "Choix invalide! Veuillez réessayer." << endl;
        }

        
	}while(choix!=0);
	
	
    
   
    	
		


return 0;
}
        














