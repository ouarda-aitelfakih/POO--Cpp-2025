#ifndef VECT_H
#define VECT_H
class vect{
protected:
int nelem;
int *adr;
public:
vect(int n){
    nelem=n;
    adr=new int [nelem];
    for(int i=0;i<nelem;i++){
        adr[i]=0;
    }
}
~vect(){
    delete []adr;
}
int &operator[](int i){
    return adr[i];
}
};
#endif