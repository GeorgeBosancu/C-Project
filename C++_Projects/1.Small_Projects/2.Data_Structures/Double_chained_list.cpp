#include <iostream>
using namespace std;

///Memorarea unei liste dublu inlantuite
struct Nod
{
    int numar;
    Nod* urmator;
    Nod* anterior;
};
Nod* cap = NULL; ///declaram lista ca fiind vida

///Parcurgerea si afisarea elementelor
void afisareLista(Nod* cap)
{
    while (cap != NULL)
    {
        cout << cap->numar << "\n";
        cap = cap->urmator;
    }
}

///Inserarea la inceput a unui element
void inserareInceput(Nod* &cap, int valoare)
{
    //Creeam noul nod si ii atribuim valoarea din paramentru
    Nod *elem = new Nod;
    elem->numar = valoare;
    elem->urmator = cap; //Mutam sageata catre primul element din lista
    elem->anterior = NULL;
    if(cap != NULL)
        cap->anterior = elem; // Actualizam sageata primului element din lista

    cap = elem; //Inlocuim primul element din lista
}

///Stergerea unui element de pe o anumita pozitie
void stergereElementPozitie(Nod* &cap, int pozitie)
{
    if (pozitie == 0)
    {
        Nod* victima = cap;
        cap = cap->urmator;
        cap->anterior = NULL;
        delete victima;
    }
    else
    {
        Nod* predecesor = cautarePozitie(cap, pozitie);
        stergereElement(predecesor);
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
