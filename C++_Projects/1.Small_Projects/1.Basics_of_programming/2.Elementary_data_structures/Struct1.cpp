// Realizati comparatia dintre pretul a doua masini, folosind `Struct`

#include <iostream>
using namespace std;

struct masina
{
	char marca[6];
	int pret;
};

void Comparatie(masina x, masina y)
{
	cout << "Cea mai scumpa masina este: ";
	if (x.pret > y.pret)
		cout << x.marca;
	else
		cout << y.marca;
}

int main()
{
	masina M1, M2;

	cout << "Marca masina 1: "; cin >> M1.marca;
	cout << "Pret masina 1: "; cin >> M1.pret;

	cout << "Marca masina 2: "; cin >> M2.marca;
	cout << "Pret masina 2: "; cin >> M2.pret;

	Comparatie(M1, M2);

	return 0;
}

