// Determinati numarul de aparitii a unui cuvant intr-un text

#include <iostream>
using namespace std;

int main()
{
	char a[100], cuv;
	int count = 0;
	cin.get(a, 100);
	cout << "Introduceti litera dorita: "; cin >> cuv;

	for (int i = 0; i < strlen(a); i++)
	{
		if (strchr(cuv, a[i]))
			count++;
	}
	cout << "Cuvantul apare in text de " << count << " ori.";
}

