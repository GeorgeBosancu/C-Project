// Realizati o aplicatie prin care sa inlocuiti prima cifra a unui numar introdus de la tastatura, cu ultima cifra a acestuia

#include <iostream>
using namespace std;

int main()
{
	int n, cn, p = 1, ultima;
	cout << "n:"; cin >> n;

	cn = n; //copie
	ultima = n % 10; //ultima cifra a lui n

	while (n>9) //eliminam cifre din numar pana cand n este egal cu prima sa cifra
	{
		p = p * 10; //se mareste puterea lui 10
		n = n / 10;
	}
	cn = ((ultima * p + cn % p) / 10) * 10 + n;
	// ultima*p- ultima cifra ia prima pozitie in noul numar
	// +cn%p - se adauga cifrele de pe restul pozitiilor la numar
	// /10)*10- se elimina ultima cifra din numar pentru a fi inlocuita cu prima
	// +n- ultima cifra devine prima cifra memorata in n

	cout << "Noul nr este:" << cn;
}

