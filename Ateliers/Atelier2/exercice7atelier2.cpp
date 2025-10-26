#include<iostream>
#include<string>
using namespace std ;

int longueur(char chaine[]){
	int compteur=0;
	while(chaine[compteur]!='\0'){
		compteur++;
	}
	return compteur;
}

void echanger(char &a,char &b){
	char temp=a;
	a=b;
	b=temp;	
}

void permutation(char chaine[],int index){
	int i;
	int l=longueur(chaine);
	
	if(index==l-1){
		cout<<chaine<<endl;
		return;
	}
	
	for(i=index;i<l;i++){
		echanger(chaine[index],chaine[i]);
		permutation(chaine ,index + 1);
		cout<<endl;
		echanger(chaine[index],chaine[i]);
	}
}

int main (){
	char chaine[20];
	
	cout<<"entrer une chaine de caractère"<<endl;
	cin>>chaine;
	
	cout<<"tous les permutation possibles :"<<endl;;
	permutation(chaine,0);
	
	return 0;
	
	
}
