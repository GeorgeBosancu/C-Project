// Realizati citirea si afisarea din/intr-un fisier

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("fisier.in");
ofstream fout("fisier.out");

int main()
{
	int a, b;

	fin >> a >> b;
	cout << a * b;
}

