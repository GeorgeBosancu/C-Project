// Determinati aria unui triunghi, utilizand formula lui Heron


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
int main()
{
	float a, b, c;

	cout << "a:";
	cin >> a;

	cout << "b:";
	cin >> b;

	cout << "c:";
	cin >> c;
	cout << endl;

	cout << "Aria triunghiului este:" << FunctieHeron(a, b, c) << endl;

}
