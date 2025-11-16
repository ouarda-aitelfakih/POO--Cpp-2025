#include<iostream>
#include"vectok.h"
using namespace std;
int main (){
    cout<<"=======creation des vecteurs========="<<endl;
    vectok V1(3);
    V1[0]=1;
    V1[1]=2;
    V1[2]=3;
    cout<<"V1:[";
    for(int i=0;i<V1.taille();i++){
        cout<<V1[i]<<" ";
    }
    cout<<"]"<<endl;
    cout<<"===========constructeur par copie============="<<endl;
    vectok V2=V1;
    cout<<"V2:[";
    for(int i=0;i<V2.taille();i++){
        cout<<V2[i]<<" ";
    }
    cout<<"]"<<endl;
    cout<<"modification de V2"<<endl;
    V2[0]=999;
    cout<<"V2[0]="<<V2[0]<<endl;
    cout<<"V1[0]="<<V1[0]<<endl;
    cout<<"la valeur de V1 est independate du V2 donc le consrtructeur de copie fonctionne correctement"<<endl;
    
    cout<<"===================test d'affectation============"<<endl;
    vectok V3(2);
    V3[0]=23;
    V3[1]=7;
    cout<<"V3 avant affectation"<<endl;
    cout<<"[";
    for(int i=0;i<V3.taille();i++){
        cout<<V3[i]<<" ";
    }
    cout<<"]"<<endl;
    V3=V1;//affectation
    cout<<"V3 aprés affectation"<<endl;
    cout<<"[";
    for(int i=0;i<V3.taille();i++){
        cout<<V3[i]<<" ";
    }
    cout<<"]"<<endl;
    
    

}