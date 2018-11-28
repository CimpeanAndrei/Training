#include <iostream>

using namespace std;

typedef double TipCoada;

struct NodCoada
{
    TipCoada Date;
    NodCoada *Next, *Prev;
    NodCoada(TipCoada date, NodCoada *next=NULL, NodCoada* prev=NULL) :
        Date(date), Next(next), Prev(prev){} //contstructorul
};

typedef NodCoada *Coada; // pointer catre primu elem

Coada CdCreare()
{
    return NULL;
}

bool CdEGoala(Coada &coada)
{
    return coada==NULL;
}

void CdAdauga(Coada &coada, TipCoada date) //adauga la sf cozii
{
    if(CdEGoala(coada)) // daca coada e vida
    {
        coada = new NodCoada(date);
        coada->Prev=coada->Next=coada;
    }
    else
    {
        coada->Prev->Next=new NodCoada(date,coada,coada->Prev);
        coada->Prev=coada->Prev->Next;
    }
}

TipCoada CdExtrage(Coada &coada)
{
    TipCoada rez;
    if(CdEGoala(coada)) // coada nu are elemente
        return TipCoada();
    if(coada->Prev==coada)  // coada are un element
    {
        rez=coada->Date;
        delete coada;
        coada =NULL;
        return rez;
    }
    NodCoada *nodDeSters=coada;
    rez=coada->Date;
    coada=coada->Next;
    coada->Prev=coada->Prev->Prev;
    coada->Prev->Next=coada;
    delete nodDeSters;
    return rez;
}

int main()
{
    Coada coada=CdCreare();
    for(int i=0; i<30; i++)
        CdAdauga(coada, rand() % 30);
    NodCoada*i;
    i=coada;
    cout<<endl<<"Coada este compusa din urmatoarele elemente: "<<endl;
    while(i->Next!=coada)
    {
        cout<<i->Date<<"   ";
        i=i->Next;
    }
    cout<<endl<<"Da-ti un nr de elemente pe care doriti sa le extrageti: ";
    int nr, j;
    cin>>nr;
    for(j=0;j<nr;j++)
        CdExtrage(coada);
    i=coada;
    cout<<endl<<"Coada este compusa din urmatoarele elemente: "<<endl;
    while(i->Next!=coada)
    {
        cout<<i->Date<<"   ";
        i=i->Next;
    }
    return 0;
}
