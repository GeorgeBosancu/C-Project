// Determinati care este frecventa unui caracter intr-un text introdus de la tastatura

#include <iostream>
#include <string>
using namespace std;
int main()
{
	char a[100], crt;
	int count=0;
	cin.get(a, 100);
	cout << "Introduceti caracterul: "; cin >> crt;
	for (int i = 0; i < strlen(a); i++)
	{
		if (crt == a[i])
			count++;
	}
	cout << "Caracterul dumneavoastra se regaseste in textul introdus de " << count << " ori.";
}

