#include<iostream>
#include<string>
using namespace std;


//m�thode1:la transmession par adresse
void incrementer(int *x){
	(*x)++;
}
void permuter(int *a,int *b){
	*a=*a-*b;
	*b=*a+*b;
	*a=*b-*a;
}

//m�thode2:la transmession par r�f�rence
void incrementer_ref(int &x){
	x++;
}
void permuter_ref(int &a,int &b){
	a=a-b;
	b=a+b;
	a=b-a;
}


int main (){
	int a,b;
	cout<<"entrer la valeur de a et b"<<endl;
	cin>>a>>b;
	
	incrementer(&a);
	permuter(&a,&b);
	
	cout<<"==========apr�s la m�thode1=============="<<endl;
	cout<<"la valeur de a devient :"<<a<<endl;
	cout<<"la valeur de b devient :"<<b<<endl;
	
	incrementer_ref(a);
	permuter_ref(a,b);
	
	cout<<"===============apr�s la m�thode2============"<<endl;
	cout<<"la valeur de a devient :"<<a<<endl;
	cout<<"la valeur de b devient :"<<b<<endl;
	
	return 0;
}
