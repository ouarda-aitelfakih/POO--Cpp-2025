#include<iostream>
#include<string>
using namespace std;

int main (){
	int a;
	int& ref_a=a;
	int* p_a=&a;
	

cout<<"entrer la valeur de a"<<endl;
cin>>a;
cout<<"========les valeurs============="<<endl;
cout<<"la valeur de a est :"<<a<<endl;
cout<<"la valeur de ref_a est :"<<ref_a<<endl;
cout<<"la valeur de p_a est :"<<p_a<<" (adresse stockee)"<<endl;
cout<<"la valeur pointée par p_a est :"<<*p_a<<" (valeur pointee)"<<endl;


cout<<"=========les adresses============="<<endl;
cout<<"l'adresse de a est :"<<&a<<endl;
cout<<"l'adresse de ref_a est :"<<&ref_a<<endl;
cout<<"l'adresse de p_a est :"<<&p_a<<endl;



return 0;
}
