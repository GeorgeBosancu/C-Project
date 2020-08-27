// Rrealizati o aplicatie prin intermediul in care sa realizati simplificarea unor fractii introduse de la tastatura

#include <iostream>
using namespace std;

int CMMDC(int a, int b);

int main()
{
	int numarator, numitor;

	cin >> numarator >> numitor;
	int divizor = CMMDC(numarator, numitor);

	if (divizor == 1)
		cout << "ireductibila" << endl;
	else
	{
		numarator = numarator / divizor;
		numitor = numitor / divizor;
		cout << "fractia:" << numarator << "/" << numitor;
	}
	return 0;
}

int CMMDC(int a, int b)
{
	if (!b) 
		return a;
	return CMMDC(b, a % b);
}

