// Cuvantul cel mai lung (siruri) : Sa se afiseze cuvantul de lungime maxima, dintr-un text citit de la tastatura
//

#include <iostream>
using namespace std;

int main()
{
	char a[100], b[100];
	cin.get(a, 100);
	cin.get();
	cin.get(b, 100);

	if (strlen(a) == strlen(b))
		cout << "Cuvintele sunt egale ca lungime!";
	else
	{
		if (strlen(a) > strlen(b))
			cout << "Cuvantul cel mai lung este: " << a;
		else
			cout << "Cuvantul cel mai lung este: " << b;
	}
}
