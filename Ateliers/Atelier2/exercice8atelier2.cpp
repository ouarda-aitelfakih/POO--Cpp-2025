#include<iostream>
#include<string>
using namespace std;

class Voiture{
	//attributs
	private:
	std::string marque;
	std::string modele;
	int annee;
	float kilometrage;
	float vitesse;
	
	//constructeur par défaut
	public:
	Voiture(){
		marque="inconnue";
		modele="inconnue";
		annee=2024;
		kilometrage=0.0;
		vitesse=0.0;
	}
	//constructeur par paramétre
	Voiture(string m,string mod,int a,float km,float v){
		marque=m;
		modele=mod;
		annee=a;
		kilometrage=km;
		vitesse=v;	
	}
	
	//Méthode accelerer
	void accelerer(float valeur){
		vitesse=vitesse+valeur;
		cout<<"la vitesse est acceleré par "<<valeur<<"km/h"<<endl;
	}
	
	//Méthode freiner
	void freiner(float valeur){
		vitesse=vitesse-valeur;
		if(vitesse<0){
			vitesse=0;
		}
		cout<<"freinage de"<<valeur<<"km/h"<<endl;
	}
	
	//Méthode afficherInfo
	void afficherInfo(){
		cout<<"=======================INFORMATION DE LA VOITURE=============="<<endl;
		cout<<"la marque:"<<marque<<endl;
		cout<<"le modele:"<<modele<<endl;
		cout<<"l'annee:"<<annee<<endl;
		cout<<"kilometrage :"<<kilometrage<<"km"<<endl;
		cout<<"vitesse:"<<vitesse<<"km/h"<<endl;
		cout<<"==================================================================="<<endl;
	}
	
	//Méthode avancer
	void avancer(float distance){
		kilometrage=kilometrage+distance;
		cout<<"la voiture est avancer par "<<kilometrage<<"km/h"<<endl;
	}
	
	//Destructeur
	void destructeur(){
		cout<<"la voiture"<<marque<<"du modele "<<modele<<"est detruite"<<endl;
	}
};

int main(){
	Voiture V1("Mercedes_Benz","classe G ",2025,250,0);
	V1.afficherInfo();
	V1.accelerer(100);
    V1.freiner(50);
    V1.avancer(500);
    V1.afficherInfo();
    V1.destructeur();
    
    return 0;
}
