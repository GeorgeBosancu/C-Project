//Realizati o aplicatie prin intermediul careia sa introduceti intr-un fisier doar numerele pare introduse de la tastatura

#include <fstream>
#include <iostream>
using namespace std;

ifstream f("input.txt");
ofstream g("paritate.txt");
int main() {

	int a;
	
	while (f >> a) //cat timp se introduc numere in fisierul input
	{
		if (a % 2 == 0)
			g << a << endl;
	}
	cout << "Deschide fisierul paritate.txt :)" << endl;
}
