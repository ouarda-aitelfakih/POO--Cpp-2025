#include<iostream>
using namespace std;


//remplissage du tableau 
void remplir(int *arr,int n){
	int i;
	for(i=0;i<n;i++){
		cout<<"arr ["<<i<<"]=";
		cin>>*(arr+i);
	}
}
//affichage du tableau
void afficher(const int *arr,int n){
	int i;
	for(i=0;i<n;i++){
		cout<<*(arr+i)<<" ";
	}
	cout<<endl;
}

//trouver la valeur maximum du tableau
int & trouverMax(int *arr,int n){
	int *Max=arr,i;
	for(i=1;i<n;i++){
		if(*(arr+i)>*Max){
			Max=arr+i;
		}
	}
	return *Max;
}
//inverser avec un tableau intermediaire
void inverser(int *arr,int n){
	int i,j;
	int *tab=new int[n];
	for(i=0;i<n;i++){
		*(tab+i)=*(arr+i);
	}
	for(i=0,j=n-1;i<n;i++,j--){
		*(arr+i)=*(tab+j);
	}
	delete[] tab;
}
//inverser sans tableau intermediaire
void inverser1(int *arr,int n){
	int *p1=arr,*p2=arr+n-1;
	while(p1<p2){
		int temp=*p1;
		*p1=*p2;
		*p2=temp;
		p1++;
		p2--;
	}
	}

int main (){
	
	int n;
	cout<<"entrer la taille du tableau:";//demande a l'utilisateur la taille du tableau
	cin>>n;
	
	
	int *arr=new int[n];//alloue dynamiquement le tableau
	
	remplir(arr,n);//remplissage du tableau 
	cout<<"le tableau original"<<endl;
	afficher(arr,n);//affichage du tableau 
	
	cout<<endl;
	int &Max=trouverMax(arr,n);
	cout<<"le max est :"<<Max<<endl;//trouver le max actuel
	cout<<"entrer une nouvelle valeur pour remplacer le max :";//modifier la valeur maximal
	cin>>Max;
	
	cout<<"tableau apres modification du max "<<endl;
	afficher(arr,n);
	
	cout<<endl;
	inverser(arr,n);//inverser avec intermidiaire
	cout<<"tableau apres inversion "<<endl;
	afficher(arr,n);
	
	cout<<endl;
	inverser1(arr,n);//test de la fonction inverser sans intermediaire
	cout<<"tableau apres inversion sans intermediaire"<<endl;
	afficher(arr,n);//ne donne pas le tableau inverse
	
	delete[] arr;//libere la memoire alloue dynamiquement pour le tableau
	return 0;
}

