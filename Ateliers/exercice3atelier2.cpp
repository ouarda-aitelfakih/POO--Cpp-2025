#include<iostream>
#include<string>
using namespace std;

int main(){
	
	int *tab=new int[10];
	int i;
	cout<<"remplir le tableau "<<endl;
	for(i=0;i<10;i++){          //lire le tableau
		cout<<"tab["<<i<<"]=";
		cin>>tab[i];
	}
	
	cout<<"==================================================="<<endl;
	cout<<"=========Méthode1:formalisme tableau =============="<<endl;
	cout<<"==================================================="<<endl;
	
	int max=tab[0];
	int min=tab[0];
	
	for(i=1;i<10;i++){
		if(max<tab[i]){
			max=tab[i];
		}
	}
	cout<<"la valeur maximal est :"<<max<<endl;
	
	for(i=1;i<10;i++){
		if(min>tab[i]){
			min=tab[i];
		}
	}
	cout<<"la valeur minimal est :"<<min<<endl;
	
	cout<<"==================================================="<<endl;
	cout<<"=========Méthode2:formalisme pointeur =============="<<endl;
	cout<<"====================================================="<<endl;
	
	
	int Max=*tab;
	int Min=*tab;
	
	for(i=1;i<10;i++){
		if(*(tab+i)>Max){
			Max=*(tab+i);
		}
	}
	cout<<"le maximum est :"<<Max<<endl;
	
	for(i=0;i<10;i++){
		if(*(tab+i)<Min){
			Min=*(tab+i);
		}
	}
	cout<<"le minimum est :"<<Min<<endl;
	delete [] tab;
	return 0;
	
}
