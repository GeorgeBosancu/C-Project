// Cititi si afisati intr-un fisier, un vector introdus de la tastatura

#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("fisier.in");
ofstream fout("fisier.out");


void Citire_si_Afisare();

int main()
{
	int V[10], n;

	Citire_si_Afisare();
	return 0;
	fout.close();
}

void Citire_si_Afisare()
{
	int n, V[10];

	//citire
	cout << "Cate elemente: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "V[i]=";
		cin >> V[i];
		fin >> V[i];
	}

	//afisare
	cout << "Elementele sunt:";
	for (int i = 0; i < n; i++)
	{
		cout << V[i] << " ";
		fout << V[i] << " ";
	}
}
