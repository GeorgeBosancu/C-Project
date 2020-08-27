#include "Angajat.h"
#include <cstring>
#include <iostream>
using namespace std;

Angajat::Angajat(unsigned marca, char *nume, int s_baza, int ore_sup, int t_orar)
    :marca_emp{marca}, sal_baza{s_baza}, nr_ore_sup{ore_sup}, tarif_orar{t_orar}
{
    strcpy(this->nume, nume);
}

Angajat::Angajat (char *num, int sbaza)
    :sal_baza{sbaza}
{
    strcpy(this->nume, num);
}

int Angajat::calcul_sal_brut() ///aici putem folosi this pt ca nu avem parametri
{
    return this->sal_baza + this->nr_ore_sup * this->tarif_orar;
}

int Angajat::calcul_sal_brut(int sal_baza, int nr_ore_sup, int tarif_orar) ///aici fara this
{
    return sal_baza + nr_ore_sup * tarif_orar;
}

int Angajat::calcul_sal_net()
{return this->calcul_sal_brut() * 0.7;}

int Angajat::calcul_sal_net(int sal_baza)
{
    return this->calcul_sal_brut(sal_baza, this->nr_ore_sup, this->tarif_orar) * 0.7;
}

char *Angajat::spune_nume()
{
    return this->nume;
}

Inginer::Inginer(int bon, int indemn, char *num1, int sal1) :Angajat(num1, sal1) ///constr delegat
    {
        this->bonus = bon;
        this->indemnizatie = indemn;
    }
void Inginer::Arata_venit()
    {
        cout << "\nInginerul "<< this->spune_nume() <<" are venitul: "<< this->sal_baza +
        this->bonus + this->indemnizatie <<endl;
    }
Profesor::Profesor(char *num, int sal, int stres):Angajat(num, sal)
{
    this->spor_stres=stres;
};

void Profesor::Arata_venit()
    {
        cout<<"\nVenitul profesorului este: "<<this->sal_baza + this->spor_stres<<endl;
    }
