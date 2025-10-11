#include<iostream>
using namespace std;

int main () {
	char c='\x05';//c est un caractere de controle ,en decimal c=05
	             //pour afficher sa valeur on ecris (int)c 
	            
	int n=5;
	long p=1000;
	float x=1.25;
	double z=5.5;      
	
	//la hierarchie complete des types numeriques: char < short < int < long< long long < float <double < long double
	/*1*/cout<<n+(int)c+p<<endl;//n est de type int ,c est de type char et p est de type long
	                      //le type resultant est :long
	                     //la valeur est :1010
	                     
	/*2*/cout<<2*x+(int)c<<endl;//(2*x) est de type float et c est de type char
	                      //la somme est de type:float
						 //la valeur est :7,5
						 
    /*3*/cout<<(char)n+(int)c<<endl;//n est de type int et c est de type char
	                          //le type resultant est :int 
							 //la valeur est :10
							 
    /*4*/cout<<(float)z+n/2<<endl;//z est de type double et n/2 est de type int 
                            //le type resultant est :float
                           //la valeur est :7,5
                           
    return 0;                      							 					                   
}

