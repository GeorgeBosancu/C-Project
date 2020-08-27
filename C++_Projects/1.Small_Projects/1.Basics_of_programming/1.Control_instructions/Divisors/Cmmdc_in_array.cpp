// Calculati cel mai mare divizor comun (cmmdc) al elementelor unui vector

#include <iostream>
using namespace std;
int const n = 5;
int main()
{
	int V[20] = { 2,4,6,8,10 };
	int cmmdc = V[0]; //initializam cu primul element

	for (int i = 1; i < n; i++) //metoda scaderilor repetate (vezi numere)
	{
		int cpy = V[i]; //facem cate o copie pentru fiecare element
		while (cpy != cmmdc)
		{
			if (cmmdc > cpy)
				cmmdc = cmmdc - cpy;
			if (cpy > cmmdc)
				cpy = cpy - cmmdc;
		}
	}
	cout << "cmmdc:" << cmmdc;
}

