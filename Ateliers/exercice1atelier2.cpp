#include<iostream>
#include<string>
using namespace std;



void fonction(){
	static int n=1;//variable initialiser une seul fois ; on peut aussi le d�clarer comme un variable global
	cout<<"appel num�ro"<<n<<endl;
	n+=1;
}

int main (){
	//test
	fonction();
	fonction();
	fonction();
	return 0;
	
	//affichage : appel num�ro1
	//            appel num�ro2
	//            appel num�ro3
}
