// Sortati elementele unui vector prestabilit, folosind metdoa Quick Sort

#include <iostream>
#include <algorithm> //aici gasim sort()

using namespace std;

void AfisareVector(int V[], int N);

int main()
{
	int N = 7, V[10] = { 2, 4, 55, 6, 1, 99, 2 };

	sort(V, V+N); //pointeri pentru inceputul si finalul vectorului
	AfisareVector(V, N);
}

void AfisareVector(int V[], int N)
{
	cout << "Noile elemente ale vectorului:";
	for (int i = 0; i < N; i++)
		cout << V[i] << " ";
}