// Aplicatii (Jump Statements).cpp

#include <iostream>
using namespace std;

int main(void)
{
	int a = 10;

	do
	{
		cout << a << ",";
		--a;
		if (a == 4) {
			cout << "Nasol!";
			exit(EXIT_SUCCESS);
		}
	} while (a >= 1);

	return 0;
}