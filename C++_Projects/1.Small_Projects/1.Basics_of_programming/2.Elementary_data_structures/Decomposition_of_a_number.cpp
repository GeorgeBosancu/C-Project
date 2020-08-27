//Algoritm pentru descompunerea unui numar in cifre 

#include <iostream>
using namespace std;

int  main()
{
	int nr, cifra;

	cout << "n:"; cin >> nr;

	while (nr > 0)
	{
		cifra = nr % 10;
		nr = nr / 10;
		cout << "Cifra:" << cifra << endl;
	}
}

