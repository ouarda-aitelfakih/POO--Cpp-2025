#include<iostream>
#include<string>
using namespace std;



void fonction(){
	static int n=1;//variable initialiser une seul fois ; on peut aussi le déclarer comme un variable global
	cout<<"appel numéro"<<n<<endl;
	n+=1;
}

int main (){
	//test
	fonction();
	fonction();
	fonction();
	return 0;
	
	//affichage : appel numéro1
	//            appel numéro2
	//            appel numéro3
}
