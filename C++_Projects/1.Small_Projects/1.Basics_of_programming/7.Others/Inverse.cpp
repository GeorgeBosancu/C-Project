// Determinati inversul unui numar

#include <iostream>
using namespace std;

int main()
{
	//Descompunerea unui numar in cifre
	//Cate cifre are un numar
	//Inversul unui numar

	int nr, cifra, nr_cifra=0, invers = 0;

	cout << "nr:"; cin >> nr;
	
	cifra = 0;
	while (nr > 0)
	{
		cifra = nr % 10;
		nr = nr / 10;
		cout << "Cifra:" << cifra << endl;
		nr_cifra++;
		invers = invers * 10 + cifra;
	}
	cout << "Numarul are: " << nr_cifra << " cifre" << endl;
	cout << "Inversul numarului este:" << invers;


}
