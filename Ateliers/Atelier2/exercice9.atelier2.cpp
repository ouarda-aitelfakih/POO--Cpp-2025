#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Vecteur3d{
	private:
		float x, y ,z;
	public:
		//constructeur
		Vecteur3d(float a=0,float b=0,float c=0){
			x=a;
			y=b;
			z=c;
		}
		
		//afficher
		void afficher(){
			cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;
		}
		
		//somme de 2 vecteur (retour par valeur)
		Vecteur3d somme(Vecteur3d V){
			Vecteur3d somme;
			somme.x=x+V.x;
			somme.y=y+V.y;
			somme.z=z+V.z;
			
			return somme;
		}
		
		// produit scalaire (retour par valeur)
        float produitScalaire(Vecteur3d V) {
        	
         return (x * V.x + y * V.y + z * V.z);
    }
    
    // fonction permittant de savoir si 2 vecteurs ont mêmes composantes(retour par valeur)
    int coincide(Vecteur3d V) {
    	if((x == V.x && y == V.y && z == V.z)){
    		return 1;
		}
		else
		   return 0;
        
    }
	//la norme(retour par valeur)
	float norme(){
		return sqrt(x*x+y*y+z*z);
	}
	
	// fonction retourne la plus grande norme(retour par valeur)
	Vecteur3d normax(Vecteur3d V){
		if (norme() >= V.norme()) {
            return *this;  // Retourne le vecteur courant
        } else {
            return V;
        }
    }
    //somme de 2 vecteur (retour par adresse)
		Vecteur3d *somme_adr(Vecteur3d *V){
			Vecteur3d *somme=new Vecteur3d();
			somme->x=x+V->x;
			somme->y=y+V->y;
			somme->z=z+V->z;
			
			return somme;
		}
// produit scalaire (retour par adresse)
    float* produitScalaire_adr(Vecteur3d* V) {
        float* produit = new float;
        *produit= x * V->x + y * V->y + z * V->z;
        return produit;
    }
    
    // fonction coincide (retour par adresse)
    bool* coincide_adr(Vecteur3d* V) {
        bool* resultat = new bool;
        *resultat = (x == V->x && y == V->y && z == V->z);
        return resultat;
    }
    
    // norme (retour par adresse)
    float* norme_adr() {
        float* resultat = new float;
        *resultat = sqrt(x * x + y * y + z * z);
        return resultat;
    }
    // normax (retour par adresse)
    Vecteur3d* normax_adr(Vecteur3d* V) {
        if (norme() >= V->norme()) {
            return this;
        } else {
            return V;
        }
    }
// somme (retour par référence)
    Vecteur3d& somme_ref(Vecteur3d& V, Vecteur3d& somme) {
        somme.x = x + V.x;
        somme.y = y + V.y;
        somme.z = z + V.z;
        return somme;
    }

    // Produit scalaire (retour par référence)
    float& produitScalaire_ref(Vecteur3d& V, float& produit) {
      produit = x * V.x + y * V.y + z * V.z;
        return produit;
    }

    // fonction coincide (retour par référence)
    bool& coincide_ref(Vecteur3d& V, bool& resultat) {
        resultat = (x == V.x && y == V.y && z == V.z);
        return resultat;
    }

    // norme (retour par référence)
    float& norme_ref(float& resultat) {
        resultat = sqrt(x * x + y * y + z * z);
        return resultat;
    }

    // Normax (retour par référence)
    Vecteur3d& normax_ref(Vecteur3d& V) {
        if (norme() >= V.norme()) {
            return *this;
        } else {
            return V;
        }
    }
		
};

int main (){
	Vecteur3d V1(1,2,3);
	Vecteur3d V2(4,5,6);
	Vecteur3d V3(7,8,9);
	
	cout<<"====================les vecteurs=============="<<endl;
	
	cout<<"V1=";V1.afficher();cout<<endl;
	cout<<"V2=";V2.afficher();cout<<endl;
	cout<<"V3=";V3.afficher();cout<<endl;
	
	//par valeur
    cout << "\n========== RETOUR PAR VALEUR ==========\n";
    
    Vecteur3d s1 = V1.somme(V2);
    cout << "Somme v1 + v2 = "; s1.afficher(); cout << endl;

    float ps1 = V1.produitScalaire(V2);
    cout << "Produit scalaire v1 . v2 = " << ps1 << endl;

    int c1 = V1.coincide(V3);
    cout << "v1 coincide avec v3 ? " << (c1 ? "Oui" : "Non") << endl;

    float n1 = V1.norme();
    cout << "Norme de v1 = " << n1 << endl;

    Vecteur3d nmax1 = V1.normax(V2);
    cout << "Vecteur avec plus grande norme entre v1 et v2 = ";
    nmax1.afficher(); cout << endl;

    // par adresse
    cout << "\n========== RETOUR PAR ADRESSE ==========\n";

    Vecteur3d* s2 = V1.somme_adr(&V2);
    cout << "Somme v1 + v2 = "; s2->afficher(); cout << endl;

    float* ps2 = V1.produitScalaire_adr(&V2);
    cout << "Produit scalaire v1 . v2 = " << *ps2 << endl;

    bool* c2 = V1.coincide_adr(&V3);
    cout << "v1 coincide avec v3 ? " << (*c2 ? "Oui" : "Non") << endl;

    float* n2 = V1.norme_adr();
    cout << "Norme de v1 = " << *n2 << endl;

    Vecteur3d* nmax2 = V1.normax_adr(&V2);
    cout << "Vecteur avec plus grande norme entre v1 et v2 = ";
    nmax2->afficher(); cout << endl;

    // Libérer la mémoire allouée
    delete s2;
    delete ps2;
    delete c2;
    delete n2;

    // par réference
    cout << "\n=============RETOUR PAR REFERENCE ==========\n";

    Vecteur3d s3;
    V1.somme_ref(V2, V3);
    cout << "Somme v1 + v2 = "; s3.afficher(); cout << endl;

    float ps3;
    V1.produitScalaire_ref(V2, ps3);
    cout << "Produit scalaire v1 . v2 = " << ps3 << endl;

    bool c3;
    V1.coincide_ref(V3, c3);
    cout << "v1 coincide avec v3 ? " << (c3 ? "Oui" : "Non") << endl;

    float n3;
    V1.norme_ref(n3);
    cout << "Norme de v1 = " << n3 << endl;

    Vecteur3d& nmax3 = V1.normax_ref(V2);
    cout << "Vecteur avec plus grande norme entre v1 et v2 = ";
    nmax3.afficher(); cout << endl;

    return 0;
}











