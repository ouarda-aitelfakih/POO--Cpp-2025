#include<iostream>
#include<iterator>
#include<set>
#include<vector>
#include<list>
#include<string>
using namespace std;
//Q2.
     bool recherche(set<int>& S,int n){
        set<int>::iterator itr;
        for(itr=S.begin();itr!=S.end();itr++){
            if(*itr==n){
               return true;
            }
        }
        return false;
     }
    //Q3.
    bool recherche2(set<int>::iterator debut,set<int>::iterator fin,int n){
    
      for(set<int>::iterator itr= debut;itr!= fin;itr++){
        if(*itr==n){
            return true;
        }
    }
    return false;
    }
    //Q4.
    template<class T,class value> bool recherche3(T debut,T fin,value valeur){
    for(T itr= debut;itr!= fin;itr++){
        if(*itr==valeur){
            return true;
        }
    }
    return false;
}
int main(){
     //Q1.
     set<int> S1;
     for(int i=1;i<=100;i++){
        S1.insert(i);
     }

    set<int>::iterator itr;
    for(itr=S1.begin();itr!=S1.end();itr++){
        cout<<*itr<<" ";
    }
    cout<<endl;

    cout<<recherche(S1,101)<<endl;
     
vector<string> v ={"A","B","C","D"};
cout<<recherche3(v.begin(),v.end(),"D")<<endl;

list<int> l={1,2,3,4};
cout<<recherche3(l.begin(),l.end(),4)<<endl;


float tableau[]={2.3,1.67,5.0,7.92};
cout<<recherche3(tableau,tableau+2,2.3f);


return 0;


}




