// Tipul Struct (Aplicatie).cpp :Studentii dintr-o facultate vor să facă un top al celor mai bune 10 melodii pentru fiecare săptămană. 
// Ajutaţi-i să realizeze un program prin care se introduc n date de forma: titlu melodie, interpret, număr puncte acumulate. 
// Sa se afiseze primele 10 titluri, in ordinea descrescătoare a punctelor


#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct melodii
{
	string titlu;
	string interpret;
	unsigned int puncte_acumulate;
}V[3];

void citire()
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Titlu melodie: "; 
		getline(cin, V[i].titlu);
		cout << "Interpretul melodiei:"; 
		getline(cin, V[i].interpret);
		cout << "Puncte acumulate:"; 
		cin>> V[i].puncte_acumulate;
	}
}

bool compara(melodii x, melodii y)
{
	if (x.puncte_acumulate > y.puncte_acumulate)
		return true;
	return false;
}
void sortare()
{
	sort(V, V + 3, compara);
}

void afisare()
{
	cout << "Ordinea descrescatoare a punctajelor este:" << endl;
		for (int i = 0; i < 3; i++)
			cout << "Melodia: " << V[i].titlu << " a obtinut: " << V[i].puncte_acumulate << " puncte." << endl;
}

int main()
{
	citire();
	sortare();
	afisare();
	return 0;
}

