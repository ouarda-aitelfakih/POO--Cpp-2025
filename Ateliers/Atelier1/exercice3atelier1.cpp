#include<iostream>
using namespace std;

int main (){
	int n=5,p=9;
	int q;
	float x;
	
   	/*1*/ q=n<p;    //si (n<p)est vraie q=1 sinon q=0 
	cout<<q<<endl; //la valeur est 1 car (5<9)
	
	/*2*/q=n==p;   //si (n==p) est vraie q=1 sinon q=0
	cout<<q<<endl;//la valeur est 0 car 5!=9
	
	/*3*/q=p%n+p>n; //si (p%n+p)>n est vraie q=1 sinon q=0
	cout<<q<<endl;//la valeur est 1 car 4+9=13>5
	
	
	/*4*/x=p/n;    // 9/5=1
	cout<<x<<endl;//la valeur est :1
	
	/*5*/x=(float)p/n;  //la valeur est :1,8
	cout<<x<<endl;
	
	/*6*/x= (p+0.5) / n;   //p est de type int et 0,5 est de type float ,(p+0,5)->float 
	cout<<x<<endl;     //la valeur est :1,9
	
	
   /*7*/x=(int)(p+0,5)/n; //la valeur est :1
	cout<<x<<endl;
	
	/*8*/q=n*(p>n?n:p); //p>n donc q=n*n
	cout<<q<<endl;     //la valeur est :25
	
	/*9*/q=n*(p<n?n:p); //p<n est faux donc q=n*p
	cout<<q<<endl;     //la valeur est :45
	
	return 0;
}
