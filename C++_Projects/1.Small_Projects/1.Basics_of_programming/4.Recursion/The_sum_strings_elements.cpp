// Recursivitate: Avand un sir cu n elemente numere reale, sa se scrie o functie recursiva care calculeaza suma elementelor sirului

#include <iostream>
using namespace std;
int suma(int V[], int i);
int main()
{
	int V[10], n = 9, i=0;
	cout << "Cate nr sa contina sirul "; 
	for (int i = 0; i < n; i++)
		cin >> V[i];

	cout<<suma(V, i);
}

int suma(int V[], int i)
{
	if (i == -1)
		return 0;
	return V[i] + suma(V, i - 1);
}
