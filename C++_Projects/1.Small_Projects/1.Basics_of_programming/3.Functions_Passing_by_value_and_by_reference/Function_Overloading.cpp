// Functii part 3 (Supraincarcare functii)

#include <iostream>
using namespace std;

//incarcate functie:
float operate(float a, float b)
{
	return a / b;
}

//supraincarcare 1:

float operate(float a)
{
	return a / 2;
}

//supraincarcare 2:
float operate(float a, int b)
{
	return a / b;
}

//supraincarcare 3:
float operate(int a, int b)
{
	return (float)a / b;
}

//supraincarcare 4 (functie mai complexa):
float operate(float a, float b, char op)
{
	switch (op)
	{
	case '+':
		return a + b;
		break;
	case'-':
		return a - b;
		break;
	case'*':
		return a * b;
		break;
	case'/':
		return a / b;
		break;
	default: 
		cout << "Nu cunosc aceasta operatie" << endl;
		return 0;
		break;
	}
}


int main(void)
{
	cout<<operate(2.3f, 4.3f)<<endl;
	cout<<operate(2.6f)<<endl;
	cout << operate(2.4f, 2) << endl;
	cout << operate(2, 3) << endl;

	cout << operate(2.3f, 4.3f, '+') << endl;
	cout << operate(2.3f, 4.3f, '-') << endl;
	cout << operate(2.3f, 4.3f, '*') << endl;
	cout << operate(2.3f, 4.3f, '/') << endl;

	return 0;
}
