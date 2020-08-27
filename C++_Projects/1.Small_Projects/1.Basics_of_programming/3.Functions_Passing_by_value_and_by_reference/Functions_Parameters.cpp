
// Functii part 4 (Transmitere parametri) 
//-> valoare (se fac copii temporare ale parametrilor)
//->referinta (se transmit locatiile de memorie ale parametrilor) (diferenta: & + const <<ca sa nu corupem acele date>) (pt int sau short nu are rost sa punem const)


#include <iostream>
using namespace std;

//transmitere prin valoare
double sum_valoare(int a, float b, double c)
{
	return a + b + c;
}

//transmitere prin referinta
double sum_referinta(int& a, const float& b, const double& c) //diferenta: & + const <<ca sa nu corupem acele date> (pt int sau short nu are rost sa punem const)
{
	return a + b + c;
}

int main()
{
	int a = 2;
	float b = 12.23f;
	double c = 12.123456789f;

	cout << "sum_valoare:" << sum_valoare(a, b, c) << endl;
	cout << "sum_referinta:" << sum_referinta(a, b, c) << endl;
	}

