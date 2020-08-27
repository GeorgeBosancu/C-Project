// Avand un vector cu n elemente numere reale, sa se scrie o functie recursiva care calculeaza suma elementelor vectorului:

#include <iostream>
using namespace std;


int sum(int n);
int main()
{
	int V[10] = { 1, 2, 3, 4 }, n =4;

	cout << sum(n);
}

int sum(int n)
{
	if (n == 0)
		return 0;
	return n + sum(n - 1);
}


