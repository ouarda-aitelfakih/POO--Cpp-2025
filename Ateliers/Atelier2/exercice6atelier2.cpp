#include<iostream>
#include<string>
using namespace std;


//méthode1:la transmession par adresse
void incrementer(int *x){
	(*x)++;
}
void permuter(int *a,int *b){
	*a=*a-*b;
	*b=*a+*b;
	*a=*b-*a;
}

//méthode2:la transmession par référence
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
	
	cout<<"==========aprés la méthode1=============="<<endl;
	cout<<"la valeur de a devient :"<<a<<endl;
	cout<<"la valeur de b devient :"<<b<<endl;
	
	incrementer_ref(a);
	permuter_ref(a,b);
	
	cout<<"===============aprés la méthode2============"<<endl;
	cout<<"la valeur de a devient :"<<a<<endl;
	cout<<"la valeur de b devient :"<<b<<endl;
	
	return 0;
}
