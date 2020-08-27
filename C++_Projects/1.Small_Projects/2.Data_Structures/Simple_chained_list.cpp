#include <iostream>
using namespace std;

///Memorarea unei liste simplu inlantuite
struct Nod
{
    int numar;
    Nod* urmator;
};
Nod* cap = NULL;    ///Declaram lista ca fiind vida

///Parcurgerea si afisarea elementelor
void afisareLista(Nod* cap)
{
    while (cap != NULL)
    {
        cout << cap->numar << "\n";
        cap = cap->urmator;
    }
}

///Inserarea unui element la inceput
void inserareInceput(Nod* &cap, int valoare)
{
    Nod *elem = new Nod;
    elem->numar = valoare;
    elem->urmator = cap;
    cap = elem;
}

///Stergerea unui element
void stergereElement(Nod* predecesor)
{
    Nod* victima = predecesor->urmator;

    predecesor->urmator = predecesor->urmator->urmator;

    delete victima;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
