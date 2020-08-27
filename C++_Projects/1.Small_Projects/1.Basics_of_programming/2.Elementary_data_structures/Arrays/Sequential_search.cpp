// Se introduc elementele unui vector de la tastatura si o valoare oarecare. Realizati o aplicatie prin intermediul careia se poate cauta acea valoare in vector.


#include <iostream>
using namespace std;
int const n = 5;
int main()
{
	int V[20], nr, ok = 0;

	cout << "Introduceti elementele vectorului: "; 
	for (int i = 1; i <= n; i++)
		cin >> V[i];
	cout << "Introduceti numarul pe care il cautati: "; cin >> nr;

	for (int i = 1; i <= n; i++)
	{
		if (V[i] == nr)
			ok=1;
	}

	if (ok==1)
		cout << "Numarul introdus se regaseste in vectorul nostru!";
	else
		cout << "Numarul introdus nu se regaseste in vectorul nostru!";

}


// Cautarea secventiala in vectori: Cautarea secventiala este un algoritm prin care putem sa cautam o anumita valoare in interiorul unui vector