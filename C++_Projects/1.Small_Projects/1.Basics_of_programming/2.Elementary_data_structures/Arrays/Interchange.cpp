// Sortati elementele unui vector, folosind metoda interschimbarii 

#include <iostream>
using namespace std;

void Interschimbare(int V[], int n);
void Afisare(int V[], int n);

int main()
{
	int V[10] = { 1, 33, 2, 6, 71, 16 }, n = 6;

	Interschimbare(V, n);
	Afisare(V, n);
	
	return 0;
}

void Interschimbare(int V[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (V[i] > V[j])
			{
				int aux = V[i];
				V[i] = V[j];
				V[j] = aux;
			}
		}
	}
}

void Afisare(int V[], int n)
{
	cout << "Vectorul nostru are acum aceasta ordine: ";
	for (int i = 0; i < n; i++)
		cout << V[i] << " ";
}