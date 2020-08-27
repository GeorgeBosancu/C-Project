// Calculati produsul elementelor unei matrice predefinite

#include <iostream>
using namespace std;
int const n = 3;
int const m = 3;
int main()
{
	int M[3][3] = { 1,2,3,4,5,6,7,8,9 }, prod=1;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			prod = prod * M[i][j];

	cout << "Produsul elementelor matricii este: " << prod;
}

