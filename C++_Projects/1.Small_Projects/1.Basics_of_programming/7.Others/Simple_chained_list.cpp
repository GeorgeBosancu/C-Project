// Lista simplu inlantuita(2): cautare si stergere

#include <iostream>
using namespace std;

struct Nod
{
	int nr;
	Nod* urmator;
};

Nod* cap = NULL;

int main()
{

	return 0;
}

Nod* cautareValoare(Nod* cap, int valoare)
{
	while (cap != NULL && cap->nr != valoare)
		cap = cap->urmator;
	return cap;
}

Nod* cautarePozitie(Nod* cap, int pozitie) //functia este de tip Nod*, pentru ca returnam la final tip Nod
{
	int i = 0;  //Pozitia curenta

	//Parcurgem lista pana la pozitia curenta, sau
	//pana ajungem la ultimul element al listei
	while (cap != NULL && i < pozitie)
	{
		cap = cap->urmator;
		i++;
	}

	//In cazul in care am gasit pozitia ceruta, o returnam
	if (i == pozitie)
		return cap;
	else
		return NULL;
}

void StergereElementInterior(Nod* predecesor) //functia stergere merge doar cu predecesor
{
	Nod* victima = predecesor->urmator;
	predecesor->urmator = predecesor->urmator->urmator; //sarim efectiv nodul pe care vrem sa-l stergem

	delete victima;
}

void StergereElementPozitie(Nod* &cap, int pozitie)
{
	if (pozitie == 0) //In cazul in care primul element este cel ce trebuie sters

	{
		Nod* victima = cap;
		cap = cap->urmator;
		delete victima;
	}
	Nod* predecesor = cautarePozitie(cap, pozitie - 1);
	StergereElementInterior(predecesor);
}

void stergereElementValoare(Nod*& cap, int valoare)
{
	//In cazul in care elementul vizat este capul listei noastre
	if (cap->nr == valoare)
	{
		Nod* victima = cap;
		cap = cap->urmator;
		delete victima;
		return;
	}
	//Parcurgem lista si cautam elementul cerut
	Nod* elem = cap;
	while (elem->urmator != NULL && elem->urmator->nr != valoare)
		elem = elem->urmator;
	//Daca am gasit nodul, il stergem
	if (elem->urmator != NULL)
		StergereElementInterior(elem);

}


