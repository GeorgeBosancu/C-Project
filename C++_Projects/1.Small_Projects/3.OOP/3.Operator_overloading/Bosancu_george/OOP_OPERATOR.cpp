#include "pch.h"
#include<iostream>
#include<string>
using namespace System;
using namespace std;

class Pers {
private:
    string nume;
    double salariu;
public:
    Pers(string n = "Anonim", double s = 0):salariu{s}, nume{n}{}
    string arata_nume() { return this->nume; }
    double arata_salariu() { return this->salariu; }

    friend double operator+(Pers&, double);
    friend double operator+(double,Pers&);
    friend const double operator--(Pers&); //decrementare
    friend double operator-(Pers&, double); //scadere


    double operator+(Pers&);
    double operator+=(double);
    double operator-=(double);
};

double operator+(Pers& p, double spor) { return p.salariu + spor; };
double operator+(double spor, Pers& p) { return p.salariu + spor; };
double operator-(Pers& p, double spor) { return p.salariu - spor; };
const double operator--(Pers& p) { p.salariu--; return p.salariu; };

double Pers::operator+(Pers& p) { return salariu + p.salariu; };
double Pers::operator+=(double spor) { return salariu += spor; };
double Pers::operator-=(double spor) { return salariu -= spor; };

int main()
{
    double spor = 100;
    cout << "Sporul este: " << spor << " de lei" << endl;
    Pers p1("Catana Viorel", 5673), p2 = Pers("Vasilescu Marian", 7654);
    Pers p3("Ciucasu Ion", 5643);

    cout << "Dupa spor," << p3.arata_nume() << " ar avea: " << p3 + spor<<" lei.";
    p3 += spor;

    cout << "\n" << p3.arata_nume() << " chiar are acum " << p3.arata_salariu() << " lei";
    cout << "\nFamilia " << p1.arata_nume() << " are " << p1 + p2 << " lei\n";

    cout << "Salariul decrementat al lui " << p3.arata_nume() << " este acum: " << --p3;
    
    cout << "\n" << p3.arata_nume() << " chiar are acum " << p3.arata_salariu() << " lei"<<endl;
    cout << "Fara spor," << p3.arata_nume() << " ar avea: " << p3 - spor << " lei."<<endl;
    p3 -= spor;
    cout << p3.arata_nume() << " chiar are acum " << p3.arata_salariu() << " lei" << endl;

    Console::ReadKey(); //imi afiseaza doar ouput consola
    return 0;
}
