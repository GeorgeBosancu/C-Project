// Determinati numarul de vocale dintr-un cuvant introdus de la tastatura


#include <iostream>
using namespace std;

int main()
{
	char a[100], vocale[] = "aeiou";
	int count = 0;
	cin.get(a, 100);

	
	for (int i = 0; i < strlen(a); i++)
	{
			if (strchr(vocale, a[i])) //conditia cauta fiecare vocala in parte
				count++;
	}
	if (count > 0)
		cout << "Cuvantul are " << count << " vocale";
	else
		cout << "Cuvantul nu contine vocale";
}

