// Functii Part 3 (Prototipuri de functii)
// In acest caz, corpul functiei poate fi oriunde, atata timp cat prototipul functiei (prima linie) o inseram dupa using namespace std;

#include <iostream>
using namespace std;

float add(float a, float b);
float add(int a, int b);
float scd(float a, float b);
float impart(int a, int b);



int main()
{
	cout << add(2.3f, 4.1f) << endl; //punem f la urma ca s anu fie ambiguu pt compiler
	cout << add(2, 5) << endl;
	cout << scd(2.6f, 7.2f) << endl;
	cout << impart(4, 3) << endl;
	return 0;
}

//functie 1:
float add(float a, float b)
{
	return a + b;
}

//supraincarcare functie 1:
float add(int a, int b)
{
	return a * b;
}
//functie 2:
float scd(float a, float b)
{
	return a - b;
}

//functia 3:
float impart(int a, int b)
{
	return (float)a / b;
}