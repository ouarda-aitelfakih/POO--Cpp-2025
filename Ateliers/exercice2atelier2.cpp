#include<iostream>
#include<string>
using namespace std;

//fonction1
int multiple_de_2(int n){
	if(n%2==0){
		return 1;
	}
	else 
	    return 0;
	
}
//fonction2
int multiple_de_3(int n){
	if(n%3==0)
	   return 1;
    else 
       return 0;
}

int main (){
	int n;
	cout<<"entrer un entier"<<endl;
	cin>>n;
	
	if(multiple_de_2(n)==1){
		cout<<n<<" est pair"<<endl;
	}
	if(multiple_de_3(n)==1){
		cout<<n<<" est multiple de 3"<<endl;
	}
	if(multiple_de_2(n)==1 && multiple_de_3(n)==1){ //si un entier est multiple de 2 et 3 alors il est multiple de 6 PGCD(2,3)=1;
		cout<<n<<" est multiple de 6"<<endl;
	}
	
	return 0;
}
