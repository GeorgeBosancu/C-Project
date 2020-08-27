// Eliminarea cifrelor pare dintr-un numar (Se citeste de la tastatura un numar n. Eliminati cifrele pare ale acestuia si afisati numarul astfel obtinut.)

#include <iostream>
using namespace std;

int main()
{
	int n;
	int m = 0, p = 1; //m memoreaza nur format prin eliminarea cifrelor pare; p - ordin unitati, zeci sute
	cout << "n: "; cin >> n;
	
	while (n)
	{
		if (n % 2 == 1)
		{
			m = (n % 10) * p + m;
			p = p * 10;
		}
		n = n / 10;
	}

	if (p == 1)  //daca p ramane egal cu 1 inseamna ca if -ul nu a fost indeplinit
		cout << "Toate cifrele sunt pare";
	else
		cout << "Numarul obtinut din cifre impare este:" << m;
}

