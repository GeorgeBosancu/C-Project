// Citi si afisati o matrice introdusa de la tastatura intr-un fisier

#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("fisier.in");
ofstream fout("fisier.out"); //este foarte important ca dupa punct sa pun.in si .out (format fisier)


int main()
{
	int M[10][10], n, m;

	//citire:
	cout << "Cate linii sa contina matricea?: "; cin >> n;
	cout << "Cate coloane sa contina matricea?: "; cin >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> M[i][j];
			fin >> M[i][j];
		}
	}

	//afisare
	cout << "Matricea este:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << M[i][j] << " ";
			fout << M[i][j] << " ";
		}
		cout << endl;
		fout << endl;
	}
	fout.close();
	return 0;
}

