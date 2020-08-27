// Eliminati o linie linie si o coloana dintr-o matrice introdusa de la tastatura

#include <iostream>
using namespace std;
int const n=3;
int main()
{
	int M[20][20], l, c;

	for (int i=1; i<=n; i++)
		for (int j = 1; j <= n; j++)
		{
			cout << "M["<<i<<"]["<<j<<"]= ";
			cin >> M[i][j];
		}
	cout << "Ce linie doriti sa eliminati?"; cin >> l;

	for (int i = l; i <= n; i++)
		for (int j = 1; j <= n; j++)
			M[i][j] = M[i + 1][j];

	cout << "Matricea fara linie: ";
	for (int i = 1; i < n; i++) //scadem o linie (<n) - mergem doar pana la n-1
	{
		for (int j = 1; j <= n; j++)
			cout << M[i][j] << " ";
		cout << endl;
	}

	cout << "Ce coloana doriti sa eliminati?"; cin >> c;

	for (int i = 1; i <= n; i++)
		for (int j = c; j <= n; j++) //scadem o coloana (<n) - mergem doar pana la n-1
			M[i][j] = M[i][j+1];
	cout << "Matricea fara coloana: ";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < n; j++)
			cout << M[i][j] << " ";
		cout << endl;
	}
}

