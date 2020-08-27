// Calculati aria unui triunghi, folosind coordonatele varfurilor triunghiului.
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float Xa, Ya, Xb, Yb, Xc, Yc;

	cout << "Coordonatele lui A: " << endl; cin >> Xa >> Ya;
	cout << "Coordonatele lui B: " << endl; cin >> Xb >> Yb;
	cout << "Coordonatele lui C: " << endl; cin >> Xc >> Yc;

	float AB = sqrt((Xb - Xa) * (Xb - Xa) + (Yb - Ya) * (Yb - Ya));
	float BC = sqrt((Xc - Xb) * (Xc - Xb) + (Yc - Yb) * (Yc - Yb));
	float AC = sqrt((Xc - Xa) * (Xc - Xa) + (Yc - Ya) * (Ya - Ya));

	float p = (AB + BC + AC) / 2;
	float Aria = sqrt(p * (p - BC) * (p - AC) * (p - AB));

	cout << "Aria triungiului format este: " << Aria;

	return 0;
}

