// Pointeri - alocare dinamica a memoriei
//

#include <iostream>
using namespace std;

int main()
{
	int V[10] = { 1,2,3 };
	cout << *V << endl;  //afisez valoarea  primului element
	cout << *(V + 1) << endl;  //afisez valoarea celui de-al doilea element
	
	// alocarea dinamica a memoriei unui vector

	int *V = new int[5];
	for (int i = 0; i < 5; i++)
		*(V + i) = 4 - i;

	for (int i = 0; i < 5; i++)
		cout << V[i] << " ";
	delete[] V; //dezaloc memoria; este recomandat sa facem asta de fiecare data

}


