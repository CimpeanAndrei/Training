#include "coada.h"
#include <iostream>


coada::coada()
{
    fata=capat=NULL;
    lungime=0;
}

void coada::adaugaCapat(int data)
{
    Nod* tempNod=new Nod;
    tempNod->Data=data;
    if(fata==NULL)
        fata=capat=tempNod;
    else
    {
        capat->Next=tempNod;
        capat=capat->Next;
    }
    lungime++;
}

void coada::scoateFata()
{
    if(fata==NULL)
    {
        std::cout<<"Coada e goala";
        return;
    }
    Nod *tempNod=fata;
    std::cout<<"Stergem elementul: "<<fata->Data;
    if(lungime>0)
    {
        fata=tempNod->Next;
        lungime--;
        delete tempNod;
    }

}

int coada::lungimeCoada()
{
    return lungime;
}

void coada::afisCoada()
{
    if(fata==NULL)
    {
        std::cout<<"Coada e goala.";
        return;
    }
    Nod *tempNod=fata;
    while(tempNod!=NULL)
    {
        std::cout<<" "<<tempNod->Data;
        tempNod=tempNod->Next;
    }
    return;
}

coada::~coada()
{
    if(fata==NULL)
    {
        std::cout<<"Coada e goala ";
        return ;
    }
    Nod * tempNod=fata;
    if(lungime>0)
    {
        fata=tempNod->Next;
        lungime--;
        delete tempNod;
    }
}
