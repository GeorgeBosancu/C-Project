// Determinati transpusa unei matrice introduse de la tastatura

#include <iostream>
using namespace std;
int const n = 3;
int main()
{
	int M[20][20], P[20][20]; //folosim o alta matrice pt transpusa

	cout << "Elem matricii: ";
	for (int i=1; i<=n; i++)
		for (int j = 1; j <= n; j++)
		{
			cout << "M[" << i << "][" << j << "]= ";
			cin >> M[i][j];
		}
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			P[i][j] = M[j][i]; // se inverseaza efectiv
		}
	cout << "Matricea noastra:"; cout << endl;
	for (int i=1; i<=n; i++)
	{
		for (int j = 1; j <= n; j++)
		cout << M[i][j] << " ";
	cout << endl;
	}
	cout << "Matricea patratica: "; cout << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << P[i][j] << " ";
		cout << endl;
	}
}

