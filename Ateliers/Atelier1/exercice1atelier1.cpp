#include<iostream>
using namespace std;

int main (){
	char c='\x01';//\x signifie que c'est un nombre hexadecimal (c=01 en decimal)
	            //il ne s'affiche pas sur l'ecran (un caractere de controle)
			   //on doit ajouter (int)c pour afficher la valeur decimal de c
	              
	short int p=10;
	
	
	
	//la hierarchie complete des types numeriques: char < short < int < long< long long < float <double < long double
	
	/*1*/cout<<p+3<<endl;//p est de type short int et 3 est de type int ,les deux deviennent int d'apres l'Hierarchie des types numeriques
	               //le type resultant est : int 
	              //la valeur :13
	
	
	/*2*/cout<<(int)c+1<<endl;//c est de type char(hexadecimal)et 1 est de type int ,les deux deviennent int 
	                    //le type resultant est :int 
	                   //la valeur :2
	
	
	/*3*/cout<<p+(int)c<<endl;//p est de type short int et c de type char ,les deux deviennent int 
	                    //le type resultant est :int 
	                   //la valeur :11
	
	/*4*/cout<<3*p+5*(int)c<<endl;//(3*p)est de type int et (5*c)est de type int ,la somme devient int 
	                        //le type resultant est :int 
	                       // la valeur :35
	
	return 0;
}

