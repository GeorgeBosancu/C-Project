#include<iostream>
#include<string>
#include "pch.h"

using namespace std;
using namespace System;

struct student {
    unsigned marca;
    string facult;
    unsigned varsta;
    char nume[20];
    char prenume[20];
};

struct student_master {
    int *marca;
    char *nume;
    float *media;
};

class Pers {
private:
    unsigned vs;
    string nume;
public:
    Pers() {};
    Pers(unsigned varsta, char* num)
    {
        this -> vs = varsta;
        this->nume = num;
    }
    unsigned arata_varsta() { return this->vs; }
    string arata_nume() { return this->nume;}
    void set_nume(string num) { this->nume = num;}
    void set_varsta(int vs) { this->vs = vs;}
};


int main() {

    Pers p1;
    Pers* pe = new Pers(23, "John");
    cout << "Nume: " << pe->arata_nume() << " si varsta: " << pe->arata_varsta() << endl;

    student s1;
    strcpy_s(s1.nume,8, "Popescu");
    strcpy_s(s1.prenume,4, "Ion");
    s1.facult = "Stiinte";
    s1.marca = 1;
    s1.varsta = 21;

    int* o_valoare_cu_steluta = new int(10);
    cout << *o_valoare_cu_steluta << ": valoarea alocata dinamic in heap" << endl;
    cout << o_valoare_cu_steluta << ": referinta implicita in heap" << endl;

    cout << s1.marca << ": " << s1.nume << ": " << s1.prenume << ": " << s1.varsta << endl;
    Console::WriteLine(L"Hello World");

    student_master s2;
    s2.nume = "Ionescu";
    cout << s2.nume << endl;
    s2.media = new float(7.4354);
    cout << *s2.media << endl;
    int o_val = 7;
    Console::WriteLine(o_val);
    Console::WriteLine("Am utilizat console::WriteLine");
    s2.marca = &o_val;
    cout << *s2.marca << endl;
    cout << s2.marca << endl;
    cout << "Adresa initiala este: " << &o_val << "Ssi valoarea este: " << *&o_val << " la afel ca: " << *s2.marca << endl;


    Pers* ArrayPers = new Pers[2]{ Pers(1,"John"), Pers(2,"Steve") };
    Console::WriteLine("Array of pers:");

    for (int i{ 0 }; i < 2; i++) {
        cout << ArrayPers[i].arata_nume() << ": " << ArrayPers[i].arata_varsta() << endl;
    }

    p1.set_nume("George");
    p1.set_varsta(20);

    return 0;
}