// Descompuneti in factori_primi un numar introdus de la tastatura


#include <iostream>
using namespace std;
int main()
{
	int n, d=2, p; // 2 - primul posibil factor prim
	cout << "n:"; cin >> n;

	while (n > 1) //cand n=1 se opreste
	{
		p = 0; // odata cu fiecare factor prim, puterea se reseteaza
		while (n % d == 0)
		{
			p++; //creste puterea
			n = n / d; //numarul se imparte la factor
		}
		if (p > 0) //daca s-a schimbat p, implicit avem factori primi
			cout << d << "^" << p << " ";
		d = d + 1; //factorul creste dupa while-ul anterior
	}
}

