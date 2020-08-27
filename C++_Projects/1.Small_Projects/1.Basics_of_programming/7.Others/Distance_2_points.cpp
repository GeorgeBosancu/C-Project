// Calculati distanta dintre 2 puncte, ale caror coordonate sa le introduceti de la tastatura 

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int Xa, Ya, Xb, Yb;

	cout << "Introduceti coordonatele punctului A: " << endl;
	cout << "Xa="; cin >> Xa;
	cout << "Ya="; cin >> Ya;

	cout << "Introduceti coordonatele punctului B: " << endl;
	cout << "Xb="; cin >> Xb;
	cout << "Yb="; cin >> Yb;

	float distanta = sqrt((Xb - Xa) * (Xb - Xa) + (Yb - Ya) * (Yb - Ya));
	cout << "Distanta dintre cele doua numere este: " << distanta;
}

