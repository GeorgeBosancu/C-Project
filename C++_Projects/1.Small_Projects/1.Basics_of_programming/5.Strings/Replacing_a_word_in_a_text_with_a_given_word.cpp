// Realizati o aplicatie in C++, prin care sa inlocuiti un cuvant dintr-un text introdus de la tastatura, cu un altul dorit.

#include <iostream>
using namespace std;

int main()
{
	char a[51], cuv_vechi[51], cuv_nou[51], ListaCuvinte[50][50], * p;
	int nrEl = 0;
	cout << "Introduceti textul: "; cin.get(a, 50);
	cin.get();
	cout << "Introduceti cuvantul pe care doriti sa-l inlocuiti :"; cin.get(cuv_vechi, 50);
	cin.get();
	cout << "Introduceti cuvantul dat: "; cin.get(cuv_nou, 50);

	p = strtok(a, " "); //copiem cuvintele in Lista de cuvinte
	while (p)
	{
		strcpy(ListaCuvinte[nrEl++], p);
		p = strtok(NULL, " ");
	}

	for (int i = 0; i < nrEl; i++)
	{
		if (strcmp(ListaCuvinte[i], cuv_vechi) == 0) // se regaseste cuvantul pe care vrem sa-l inlocuim in text?
		strcpy(ListaCuvinte[i], cuv_nou); //daca da copiem cuvantul nou in lista
	}

	strcpy(a, ListaCuvinte[0]); //nu stiu de ce

	for (int i = 0; i < nrEl; i++)
	{
		strcat_s(a, " ");
		strcat_s(a, ListaCuvinte[i]);
	}

	cout << "Noul text este: "<< a;
}

