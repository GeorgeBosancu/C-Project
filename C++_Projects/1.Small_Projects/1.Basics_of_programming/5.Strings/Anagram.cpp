// Verificati daca doua cuvinte introduse de la tastatura sunt anagrame 

#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char a[100], b[100];
	cin.get(a, 100);
	cin.get();
	cin.get(b, 100);
	if (strlen(a) != strlen(b))
		cout << "Numerele nu sunt anagrame!";
	else //ordonam elementele sirurilor
	{
		for (int i = 0; i < strlen(a); i++)
			for (int j = i+1; j < strlen(a); j++)
			{
				if (a[i]>a[j])
				{
				char aux = a[i];
				a[i] = a[j];
				a[j] = aux;
				}
			}
		for (int i=0; i<strlen(b); i++)
			for (int j = i + 1; j < strlen(b); j++)
			{
				if(b[i]>b[j])
				{
				char aux = b[i];
				b[i] = b[j];
				b[j] = aux;
				}
			}
		if (strcmp(a, b) == 0) //pentru a compara sirurile, trebuie mai intai sa ordonam elementele
			cout << "Cuvintele sunt anagrame";
		else
			cout << "Cuvintele nu sunt anagrame!";
	}
}


