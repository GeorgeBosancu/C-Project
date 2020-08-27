// Maximul si minimul unui vector: Fiind dat un vector v de N elemente, atat N, cat si vectorul v, fiind citite de la tastatura, se cere sa se gaseasca minimul si maximul dintre elementele vectorului.


#include <iostream>
using namespace std;

int main()
{
	int n, V[20];
	int min = INT_MAX; //initializam cu cea mai mare valoare pe care o poate lua (infinit)
	int max = -INT_MAX; //initializam cu cea mai mica valoare pe care o poate lua (+infinit)
	cout << "Cate elemente sa contina vectorul? "; cin >> n;
	cout << "Introduceti elementele vectorului: ";
	for (int i = 0; i < n; i++)
		cin >> V[i];

	for (int i = 0; i < n; i++)
	{
		if (V[i] > max)
			max = V[i];

		if (V[i] < min)
			min = V[i];
	}

	cout << "Maximul din vector: " << max << endl;
	cout << "Minimul din vector: " << min;
}

