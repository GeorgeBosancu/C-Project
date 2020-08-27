// Cifrele unui numar (ex 2) : Sa se verifice daca toate numerele unui numar natural sunt impare
//

#include <iostream>
using namespace std;

int main()
{
	int n;
	bool veridicitate; //acest tip (bool) de data stocheaza: true si false;

	cout << "n:";
	cin >> n;

	veridicitate = true;
	while ((n > 0) && (veridicitate == true))
	{
		if ((n % 10) % 2 == 0)
			veridicitate = false;
		else
			veridicitate = true;
		n = n / 10;
	}

	if (veridicitate == true)
		cout << "Da";
	else
		cout << "Nu";
	return 0;
}


