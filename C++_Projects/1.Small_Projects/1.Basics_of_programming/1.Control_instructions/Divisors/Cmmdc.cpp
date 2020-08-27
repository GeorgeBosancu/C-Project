// Calculati cel mai mare divizor comun dintre doua numere introduse de la tastatura (numarator, numitor)

#include <iostream>
using namespace std;

int CMMDC(int a, int b);
int main()
{
	int a, b;
	cout << "Numarator:"; cin >> a;
	cout << "Numitor:"; cin>>b;
	cout << "CMMDC este: " << CMMDC(a, b);
}

int CMMDC(int a, int b)
{
	if (b == 0)
		return a;
	return CMMDC(b, a % b);
}
