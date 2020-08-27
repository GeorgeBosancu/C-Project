// Calculati suma si produsul elementelor - diagonala prinicipala matrice

#include <iostream>
using namespace std;
int main()
{
	int M[5][5], n, m, sum = 0;
	cout << "nr linii: "; cin >> n;
	cout << "nr coloane: "; cin >> m;
	cout << "Elemente Matrice:";
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cout << "M[" << i << "][" << j << "]= ";
			cin >> M[i][j];
		}

	for (int i = 1; i <= n; i++) //parcurgem doar acea diagonala
		sum = sum + M[i][i]; //mai exact i=j
	cout << "Suma elementelor de pe diagonala principala este: " << sum;
}
