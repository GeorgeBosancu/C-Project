// Realizati conversia unui sir introdus de la tastatura intr-un sir cu litere mici

#include <iostream>
#include <string.h>
using namespace std;

int main() 
{
	char a[100];
	cin.get(a, 100);

	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] >= 'A' && a[i] <= 'Z')
			a[i] = a[i] - 'A' + 'a'; //aici scadem si adunam majuscula si minuscula oricarui caracter 
	}
	cout << "Noul sir arata asa: " << a;
}
