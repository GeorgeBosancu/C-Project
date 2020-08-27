// Refactorizare (cu functii): Restructuram codul astfel incat sa il facem mai usor de organizat (acum folosim functii).

#include    <iostream>
#include    <vector>
#include    <algorithm>
using namespace std;
int suma(const vector < int >& V)
{
	const unsigned int elemente = V.size();
	if (elemente == 0)
		throw domain_error("Vectorul nu are elemente");
	int sum = 0;
	for (unsigned int i = 0; i < V.size(); i++)
		sum = sum + V[i];
	return sum;
}
float media(const vector < int >& V)
{
	const unsigned int elemente = V.size();
	if (elemente == 0)
		throw domain_error("Vectorul nu are elemente");
	int sum = 0;
	for (unsigned int i = 0; i < V.size(); i++)
		sum = sum + V[i];
	return float(sum / V.size());
}
int median(vector < int > V)
{
	const unsigned int elemente = V.size();
	if (elemente == 0)
		throw domain_error("Vectorul nu are elemente");
	sort(V.begin(), V.end());
	const int mijloc = elemente / 2;
	if (elemente % 2 == 1) // daca numarul de elemente este impar
		return V[mijloc];
	else // daca numarul de elemente este par
		return (V[mijloc - 1] + V[mijloc]) / 2;
}
void citire(int& N, vector < int >& V)
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int val;
		cin >> val;
		V.push_back(val);
	}
}
int main()
{
	vector < int > Vector;
	int N;
	citire(N, Vector);
	//Suma numerelor
	cout << "Suma este: " << suma(Vector) << "\n";
	//Media numerelor
	cout << "Media este: " << media(Vector) << "\n";
	//Elementul din mijloc
	cout << "Elementul din mijloc este: " << median(Vector);
	return 0;
}



int name (const int& a, const int& b)

{
}