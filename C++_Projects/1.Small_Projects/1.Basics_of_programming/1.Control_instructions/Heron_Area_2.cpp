// Calculati aria unui triunghi, folosind Formula lui Heron (functii)


#include <iostream>
#include<math.h>
using namespace std;


//functie - Aria lui Heron

float FunctieHeron(float a, float b, float c)
{
	float s;
	float p;

	//calculam semiperimetrul
	p = (a + b + c) / 2;

	//calculam aria triunghiului
	s = sqrt(p * (p - a) * (p - b) * (p - c));

	return s;
}



//functia fara parametri poate inlocui si o serie de instructiuni care nu returneaza valori:

void Afisare_arie(float a, float b, float c)
{
	cout << "Aria triunghiului este:" << FunctieHeron(a, b, c) << endl;
}

//functie care inlocuieste tot

void CalculeazaAria()
{
	float a, b, c;

	cout << "Introduceti laturile:" << endl;

	cout << "a:";
	cin >> a;

	cout << "b:";
	cin >> b;

	cout << "c:";
	cin >> c;
	cout << endl;

	Afisare_arie(a, b, c);
}
void main()
{

	cout << endl;

	CalculeazaAria(); //Asta daca vreau sa calculez pentru mai multe triunghiuri
	CalculeazaAria();
	CalculeazaAria();
	CalculeazaAria();


}
