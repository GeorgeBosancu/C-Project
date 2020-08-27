// Calculati factorialul unui numar, folosind recursivitatea

#include <iostream>
using namespace std;


//Ex: Factorial 
//Metoda: 9! =9*8*7*...=.. (inmultim 9 cu factorialul lui 8, apoi 8 cu factorialul lui 7 si tot asa... 

int Factorial(int n)


int main()
{
	int n;
	cout << "n="; cin >> n;
	cout << Factorial(n);
}


int Factorial(int n)

{
	if (n > 1)
	{
		return (n * Factorial(n - 1));
	}
	else
	{
		return 1;
	}
}