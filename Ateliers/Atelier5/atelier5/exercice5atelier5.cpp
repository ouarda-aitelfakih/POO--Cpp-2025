#include<iostream>
using namespace std;
template<class T>T carre(T x){
    return x*x;
}
int main(){
    int i=2;
    float j=4;
    cout<<"le carre de i est :"<<carre(i);
    cout<<endl;
    cout<<"le carre de j est :"<<carre(j);
    cout<<endl;
    return 0;
}