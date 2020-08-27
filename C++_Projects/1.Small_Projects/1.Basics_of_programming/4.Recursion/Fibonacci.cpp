// Recursivitate - Sirul lui Fibonacci:

#include <iostream>
using namespace std;


//Fibonacci:

int fib(int n);
int main()
{
	int n=5, m = 0;

	while (m < 5)
	{
		cout << fib(m) << endl;
		m++;
	}
}

int fib(int n)
{
	if (n <= 1)
		return n;
	else
		return fib(n - 1) + fib(n - 2);
}

