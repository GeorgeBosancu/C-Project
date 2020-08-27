// Determinati oglinditul unui numar introdus de la tastatura

#include <iostream>
using namespace std;

int main()
{
	int n, mirror = 0;
	cout << "n:"; cin >> n;

	while (n)
	{
		mirror = mirror * 10 + n % 10;
		n = n / 10;
	}
	cout << "Oglinditul numarului introdus este:" << mirror;
}
