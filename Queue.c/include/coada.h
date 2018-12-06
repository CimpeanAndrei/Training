#ifndef COADA_H
#define COADA_H
#include "Nod"


class coada
{
    public:
        coada();
        void adaugaCapat(int data);
        void scoateFata();
        void afisCoada();
        int lungimeCoada();
        virtual ~coada();
    protected:
    private:
        Nod *fata;
        Nod *capat;
        int lungime;
};

#endif // COADA_H
