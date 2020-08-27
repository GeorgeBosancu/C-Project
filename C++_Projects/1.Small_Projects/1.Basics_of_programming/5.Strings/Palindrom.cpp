// Palindrom - siruri (Se verifica daca un cuvant citit de la tastatura este sau nu palindrom)

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char a[200];
	cin.get(a,200);

	//prima data scoatem diacriticele
	for (int i = 0; i < strlen(a); i++) //strlen - lungimea efectiva a unui sir
		if (strchr(" ,!.?", a[i])) //strchr - cauta un caracter in sir
		{
			for (int j = i; j < strlen(a); j++)
			{
				a[j] = a[j + 1];
			}
		}
	//programul efectiv (comparam cele doua jumatati ale cuvantului
	int ok = 0;
	for (int i = 0; i < strlen(a) / 2 && ok == 0; i++)
	{
		if (tolower(a[i]) != tolower(a[strlen(a) - i - 1])) //tolower - returneaza litera mica
			ok = 1;
	}
	if (ok == 0)
		cout << "Textul este palindrom";
	else
		cout << "Textul nu este palindrom";
}

//Varianta mai usoara, dar incompleta:
/*
int main() {

	char a[201], b[201], aux[201];
	cin.get(a, 201);

	strcpy_s(aux, a); //copie din a in aux; progr cere _s
	_strrev(a); //inverseaza elem lui a; progr cere _
	strcpy_s(b, a);

	if (strcmp(aux, b) == 0) //asta inseamna ca nu a gasit nicio diferenta
		cout << "palindrom";
	else
		cout << "nu este palindrom";
}*/


