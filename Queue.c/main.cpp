#include <iostream>
#include "coada.h"

using namespace std;

int main()
{
    coada Coada;
    while(true)
    {
        int optiune;
        int data;
        cout<<"\n\n===============================\n";
        cout<<"\t\tMENU\n";
        cout<<"===============================\n";
        cout<<"1. AfisCoada\n";
        cout<<"2. AdaugaCodaa\n";
        cout<<"3. ScoateCoada\n";
        cout<<"4. LungimeCoada\n";
        cout<<"5. OprireProgram\n";
        cout<<"================================\n";
        cout<<"Choose your option :";
        cin>>optiune;
        switch(optiune)
        {
            case 1:
                    Coada.afisCoada();
                    break;
            case 2:
                cout<<"Introdu elementul : ";
                cin>>data;
                Coada.adaugaCapat(data);
                cout<<"\nAdded successfully";
                break;
            case 3:
                Coada.scoateFata();
                break;
            case 4:
                cout<<"\n Lungimea este :"<<Coada.lungimeCoada();
                break;
            case 5:
                return 0;
            default:
                cout<<"Introdu o comanda valida";
                break;
        }
    }
    return 0;
}
