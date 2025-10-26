#include<iostream>
#include<string>
using namespace std;

int main (){
	
	//demander la taille
	int n;
	int i;
	cout<<"entrer la taille du premier tableau"<<endl;
	cin>>n;
	//créer et remplir le premier tableau
	int *tab1=new int[n];
	cout<<"remplir le tableau 1"<<endl;
	for(i=0;i<n;i++){          
		cout<<"tab1["<<i<<"]=";
		cin>>tab1[i];
	}
	//créer et remplir le deuxieme tableau avec le carré du premier
	int *tab2=new int[n];
	for(i=0;i<n;i++){
		tab2[i]=(tab1[i]*tab1[i]);
	}
	//supprimer le premier tableau
	delete [] tab1;
	//afficher le deuxieme tabeau 
	cout<<"le deuxieme tableau:"<<endl;
	for(i=0;i<n;i++){
		cout<<"tab2["<<i<<"]= "<<tab2[i]<<endl;
	}
	//supprimer le deuxieme tableau
	delete[] tab2;
	
	return 0;
}
