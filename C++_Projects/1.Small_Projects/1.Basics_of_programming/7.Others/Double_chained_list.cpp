// Liste dublu inlantuite

#include <iostream>
using namespace std;

struct Nod
{
	int nr;
	Nod* urmator;
	Nod* anterior;
};
Nod* cap = NULL;

void AfisareLista(Nod* cap)
{
	while (cap != NULL)
	{
		cout << cap->nr << endl;
		cap = cap->urmator;
	}
}

void InserareInceput(Nod* &cap, int valoare)
{
	Nod* elem_inceput = new Nod;
	elem_inceput->nr = valoare;
	elem_inceput->urmator = cap;
	elem_inceput->anterior = NULL; //in stanga nu avem nimic

	if (cap != NULL)
		cap->anterior = elem_inceput; //directionam si sageata anterioara a lui cap
	cap = elem_inceput; //elem nostru devine cap
}

void InserareFinal(Nod*& cap, int valoare)
{
	Nod* elem_final = new Nod;
	elem_final->nr = valoare;
	elem_final->urmator = NULL;
	elem_final->anterior = NULL; //niciun pointer nu duce nicaieri

	if (cap == NULL) //daca lista e vida, elementul nostru devine cap
	{
		cap = elem_final;
	}
	else
	{
		Nod* elem_cobai = cap;
		while (elem_cobai->urmator != NULL)
		{
			elem_cobai = elem_cobai->urmator;
		}
		elem_cobai->urmator = elem_final; //legam nodul de 2 ori
		elem_final->anterior = elem_cobai;
	}
}

void InserareDupaElementDat(Nod* &cap, Nod* elem_dat, int valoare)
{
	Nod* elem_creat = new Nod;
	elem_creat->nr = valoare;
	elem_creat->urmator = NULL;
	elem_creat->anterior = NULL;

	if (cap == NULL)
		cap = elem_creat;

	if (cap ==elem_dat) //daca elem dat este capul, prin exceptie, elem creat devine cap (bizar)
	{
		elem_creat->urmator = cap;
		cap->anterior = elem_creat;
		cap = elem_creat;
	}
	elem_creat->urmator = elem_dat->urmator; //elem_dat->urmator este „elementul de dupa elem_dat”
	elem_dat->urmator->anterior = elem_creat; //elem_dat-:urmator-:anterior este „pointerul anterior al elementului de dupa elem_dat”
	elem_creat->anterior = elem_dat;
	elem_dat->urmator = elem_creat;

}

Nod* CautareDupaValoare (Nod* cap, int valoare)
{
	while (cap != NULL && cap->nr != valoare)
		cap = cap->urmator;
	return cap;
}

Nod* CautareDupaPozitie(Nod* cap, int pozitie)
{
	int i = 0;
	while (cap != NULL && i < pozitie)
	{
		cap = cap->urmator;
		i++;
	}
	if (i == pozitie)
		return cap;
	else
		return NULL;
}

void StergereInterior(Nod* elem)
{
	elem->anterior->urmator = elem->urmator;
	elem->urmator->anterior = elem->anterior;

	delete elem;
}

void StergerePozitie(Nod* cap, int pozitie)
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
		Nod* elem = CautareDupaPozitie(cap, pozitie);
		StergereInterior(elem);
	}
}

void StergereDupaValoare(Nod* cap, int valoare)
{
	if (cap->nr == valoare)
	{
		Nod* victima = cap;
		cap = cap->urmator;
		cap->anterior = NULL;
		delete victima;
	}

	Nod* cobai = cap;
	while (cobai->urmator != NULL && cobai->urmator->nr != valoare)
		cobai = cobai->urmator;
	if (cobai->urmator != NULL)
		StergereInterior(cobai);
}

int main()	
{

}
