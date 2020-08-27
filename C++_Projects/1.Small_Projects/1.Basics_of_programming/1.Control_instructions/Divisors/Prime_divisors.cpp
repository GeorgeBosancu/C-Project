/*  Divizorii primi ai unui numar
ex: Pentru n = 24 avem divizorii primi 2 si 3 (deoarece 24 = 2^3 * 3)

Definitie: Un numar x este divizor al altui numar y, daca y se poate scrie ca produsul dintre x si un alt numar intreg t. 
In plus, daca x este un numar prim, acesta se numeste divizor prim al numarului y.
*/
#include <iostream>
using namespace std;

int main()
{
	int nr, divizor=2, putere=0;

	cout << "nr:"; cin >> nr;

	while (nr > 1)
	{
		if (nr % divizor == 0)
		{
			while (nr % divizor == 0)
			{
				nr = nr / divizor;
				putere = putere + 1;
			}
			cout << divizor << " la puterea " << putere << endl;
		
		divizor++;
	}
}

