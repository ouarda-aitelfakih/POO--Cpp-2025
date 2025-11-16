#ifndef VECTOK_H
#define VECTOK_H
#include"vect.h"

class vectok:public vect{
    public:
    vectok(int n):vect(n){}
    vectok(const vectok &autre):vect(autre.nelem){
        for(int i=0;i<nelem;i++){
            adr[i]=autre.adr[i];//la transmission par valeur ;on a définie un constructeur de copie profonde
        }
    }

    vectok & operator=(const vectok &autre){
        if(this==&autre){//le cas ou on affecte le même vecteur(v1=v1)
            return *this;
        }
        delete []adr;//supprimer l'ancien adresse pour libérer la mémoire 

        nelem=autre.nelem;//copie le nombre des élements dans l'ancien vector 

        adr=new int [nelem];//créer une adreese convenable pour le nouveau vector

        for(int i=0;i<nelem;i++){
            adr[i]=autre.adr[i];
        }

        return *this;

    }
    //fonctionne taille retourn le nombre des élemnets 
    int taille()const{
        return nelem;
    }

};
#endif