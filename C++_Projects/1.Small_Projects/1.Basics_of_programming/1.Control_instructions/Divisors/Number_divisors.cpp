// Afisarea divizorilor proprii ai unui numar
//Divizorii improprii: 1 si numarul insusi.
//Divizorii proprii: numerelor care il divid, cuprinse intre[n, n / 2].

#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "n:"; cin >> n;

	cout << "Divizorii numarului introdus: ";

	for (int divizor = 1; divizor < n / 2; divizor++)
	{
		if (n % divizor == 0)
			cout << divizor << " ";
	}
}	