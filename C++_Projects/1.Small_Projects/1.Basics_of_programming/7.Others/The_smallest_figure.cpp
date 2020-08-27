// Stabiliti care este cea mai mica cifra a unui numar introdus de la tastatura

#include <iostream>
using namespace std;

int main()
{
	int n, min;
	cout << "n:"; cin >> n;

	min = n % 10; //initializam cu ultima cifra (cu 0 ar fi inutil)

	while (n != 0)
	{
		if (n%10<min)
			min = n % 10;
		n = n / 10;
	}
	cout << "Minim:" << min;
	return 0;
}

