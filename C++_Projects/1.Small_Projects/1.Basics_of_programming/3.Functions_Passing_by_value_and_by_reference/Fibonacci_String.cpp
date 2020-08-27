// Realizati o aplicatie prin intermediul careia sa afisati numerele Sirului lui Fibonacci

#include <iostream>
using namespace std;

int Fibonacci(int n);
int main()
{
	int n;
	cout << "Cate elemente sa contina Sirul lui Fibonacci?"; cin >> n;

	int nr_0 = 0, nr_1 = 1;
	cout << nr_0 << endl;
	cout << nr_1 << endl;

	for (int i = 3; i <= n; i++)
	{
		int nr_2 = nr_0 + nr_1;
		nr_0 = nr_1;
		nr_1 = nr_2;
		cout << nr_2 << endl;
	}
	return 0;
}

// Varianta recursiva

int Fibonacci(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}
