// Functii part 4 (Templates)


#include <iostream>
using namespace std;


int sum(int a, int b)
{
	return a + b;
}

float sum(float a, float b)
{
	return a + b;
}

double sum(double a, double b)
{
	return a + b;
}

//cream template:
template<typename T>
T add(T a, T b)
{
	return a + b;
}

//cream un tamplate cu 2 tipuri de parametri
template<typename A, typename B>
B multiply(A a, B b)
{
	return a + b;
}

int main()
{
	cout << sum(1, 4) << endl;
	cout << sum(2.3f, 4.3f) << endl;
	cout << sum(2.46666f, 4.3456f) << endl << endl;

	cout << add<int>(1, 4) << endl;
	cout << add<float>(2.3f, 4.3f) << endl;
	cout << add<double>(2.46666f, 4.3456f) << endl;
	cout << add<char>('d', '.') << endl; //la template-uri putem apela toat etipurile de valori

	cout << "multiply_int_float:" << multiply<int, float>(1, 4.2f) << endl;
	cout << "multiply_float_double:" << multiply<float, double>(1.2f, 4.2345456f) << endl;
	cout << "multiply_short_char:" << multiply<short, char>(22, 'n') << endl;

	return 0;
}
//putem copia si prototipurile, daca vrem