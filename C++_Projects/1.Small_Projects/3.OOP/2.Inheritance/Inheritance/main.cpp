#include <iostream>
#include <cstring>
#include "Angajat.h"
using namespace std;
int main()
{
    ///Angajat a1(123, "Cornel", 2000, 20, 3);
    ///cout<<a1.spune_nume();

    ///Inginer i1 (230, 100, "Maricel", 2000);
    ///i1.Arata_venit();

    Angajat *a1 = new Angajat(1, "Marinescu", 2000, 10, 50);
    cout<<"Angajatul "<<a1->spune_nume() <<" are salariul brut: "<<a1->calcul_sal_brut()<<endl;
    cout<<"Angajatul "<<a1->spune_nume() <<" are salariul net: "<<a1->calcul_sal_net()<<"\n\n";

    Angajat *a2 = new Angajat(1, "Iliescu", 2000, 10, 50);
    cout<<"Angajatul "<<a2->spune_nume() <<" are salariul brut: "<<a2->calcul_sal_brut()<<endl;
    cout<<"Angajatul "<<a2->spune_nume() <<" are salariul net: "<<a2->calcul_sal_net()<<"\n\n";

    Angajat *a3 = new Angajat("Gheorghita", 2000);
    cout<<"Angajatul "<<a3->spune_nume() <<endl;

    Inginer *ing1 = new Inginer(100, 200, "Marinescu", 4000);
    ing1->Arata_venit();

    Profesor *prof1 = new Profesor("Berhiu", 2700, 250);
    (*prof1).Arata_venit();
    return 0;
}

