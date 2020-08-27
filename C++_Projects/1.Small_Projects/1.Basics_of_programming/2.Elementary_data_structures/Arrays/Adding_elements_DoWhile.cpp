// Calculati suma elementelor unui vector introdus de la tastatura, folosind instructiunea `do while`

#include <iostream>
using namespace std;
int const n = 5;
int main()
{
	int V[20], sum = 0;
	char cont;

	do
	{
		cout << "Elementele vectorului: ";
		for (int i = 0; i < n; i++)
			cin >> V[i];
		for (int i = 0; i < n; i++)
			sum = sum + V[i];
		cout << "Suma: " << sum;
		sum = 0;
		cout<<endl<< "Doriti sa repetati? (y - da, n - nu)"; cin >> cont;
	} while (cont =='y'||cont =='Y');
	
	return 0;
}
