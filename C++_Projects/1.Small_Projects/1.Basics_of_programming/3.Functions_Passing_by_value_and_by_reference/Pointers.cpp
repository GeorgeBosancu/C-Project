// Pointeri - general

#include <iostream>
using namespace std;

int main()
{
	int *point, val=4;
	point = &val; //variabila pointer retine adresa unei alte variabile - doar daca pointerul este de acelasi tip cu variabila;

	cout << "Adresa retinuta de pointer: " << point << endl;
	cout << "Valoare pointer: " << *point << endl;
	cout << "Adresa pointer: " << &point << endl;

	return 0;
}

