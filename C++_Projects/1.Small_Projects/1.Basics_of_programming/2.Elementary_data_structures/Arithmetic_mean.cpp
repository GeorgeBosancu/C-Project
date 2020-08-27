// Calculati media aritmetica a cifrelor unui numar

#include <iostream>
using namespace std;

int main()
{
	int n, nr = 0;
	float sum=0, ma=0; //pun float si sum, ca sa imi conduca spre ma de tip float
	cout << "n:"; cin >> n;

	if (n == 0) //cazul 0
		cout << ma;
	else
	{
		while (n)
		{
			sum = sum + n % 10;
			nr++;
			n = n / 10;
		}
	}
	ma = sum / nr;
	if (nr>0) //sa nu-mi apara dublu mesaj atunci cand dau valoarea 0
	{
		cout << "Media aritmetica este:" << ma;
	}
}

	