// Realizati o agenda zilnica, folosind Switch

#include <iostream>
using namespace std;

int main(void)
{
	int zi_saptamana;
	char alta_zi;

	cout << "What day are you interested in?:";
	cin >> zi_saptamana;

	switch (zi_saptamana)
	{
	case 1:
		cout << "Today is Monday" << endl;
		break;
	case 2:
		cout << "Today is Tuesday" << endl;
		break;
	case 3:
		cout << "Today is Wednesday" << endl;
		break;
	case 4:
		cout << "Today is Thursday" << endl;
		break;
	case 5:
		cout << "Today is Friday" << endl;
		break;
	case 6:
		cout << "Today is Saturday" << endl;
		break;
	case 7:
		cout << "Today is Sunday" << endl;
		break;
	default:
		cout << "I don't know what day is this! :("<<endl;
		break;
	}
	

	cout << "If you want to know something about another day, please press: y/Y"<<endl<<"->";
	cin >> alta_zi;

	if (alta_zi == 'y' || alta_zi == 'Y')
	{
		main();
	}
	else
	{
		return 0;
	}
}

