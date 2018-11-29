#include <iostream>

using namespace std;

class coada
{
    int a[30];
    int fata;
    int capat;
public:
    coada();
    void adaugaCapat(int x);
    int scoateFata();
    int CGoala();
    int CPlina();
    void afisCoada();
};

coada::coada()
{
    fata=0;
    capat=0;
}

void coada::adaugaCapat(int x)
{
    if(CPlina())
    {
        cout<<"Coada e plina.";
        return;
    }
    a[capat] = x;
    capat++;
}

int coada::CGoala()
{
    if(fata=capat)
        return 1;
    else
        return 0;

}

int coada::CPlina()
{
    if(capat == 30)
        return 1;
    else
        return 0;
}

int coada::scoateFata()
{
    return(a[fata++]);
}

void coada::afisCoada()
{
    for(int i=fata; i<capat;i++)
        cout<<a[i]<<" ";
}

int main()
{
    coada C;
    C->adaugaCapat(1);
    C->adaugaCapat(3);
    C->adaugaCapat(8);
    C->adaugaCapat(22);
    C->scoateFata();
    C->afisCoada();
    return 0;
}
