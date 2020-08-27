#ifndef ANGAJAT_H
#define ANGAJAT_H
#include<cstring>
using namespace std;

class Angajat{
private:
    unsigned marca_emp;
    char nume[20];
    int nr_ore_sup;
    int tarif_orar;
public:
    int sal_baza;
    Angajat(){}; ///empty construct
    Angajat(unsigned marca, char *nume, int s_baza, int ore_sup, int t_orar); ///construct 1 param
    Angajat (char *num, int sbaza);///construct 2 param

    int calcul_sal_brut();
    int calcul_sal_brut(int sal_baza, int nr_ore_sup, int tarif_orar);
    int calcul_sal_net();
    int calcul_sal_net(int sal_baza);
    char *spune_nume();
};

class Inginer:public Angajat{
public:
    int bonus;
    int indemnizatie;

    Inginer(int bon, int indemn, char *num1, int sal1);
    void Arata_venit();
};

class Profesor:public Angajat{
public:
    int spor_stres;
    Profesor(char *num, int sal, int stres);
    void Arata_venit();
};
#endif // ANGAJAT_H



