// Sortati elementele unui vector predefinit, folosind metoda bubble sort

#include <iostream>
using namespace std;
const int n = 5;
int main()
{
	int V[20] = { 17, 23, 99, 11, 9 }, sort = 0;

	do {
		sort = 1;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
			{
				if (V[i] > V[j])
				{
					int aux = V[i];
					V[i] = V[j];
					V[j] = aux;
					sort = 0;
				}
			}

	} while (sort == 0);

	for (int i = 0; i < n; i++)
		cout << V[i] << " ";

}
