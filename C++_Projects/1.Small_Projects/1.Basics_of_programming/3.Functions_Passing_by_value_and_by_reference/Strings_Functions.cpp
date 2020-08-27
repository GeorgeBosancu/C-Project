// Functii pentru operatii cu siruri

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char a[50] = "primul sir ", b[40] = "al doilea sir";
	
	strlen(a)= 18; //returneaza lungimea efectiva a unui sir - fara \0
	strcpy(a, b); //copiaza (se simuleaza atribuirea a = b)
				  //acum: a = ”al doilea sir”; b=”al doilea sir”;
	strcat(a, b); //Operatia de concatenare. Sirul b[40] ramane nemodificat.
				  // - > a = ”primul sir al doilea sir”;
	strncat(a, b, 4); //adauga sirului dest primele nr caractere din sirul sursa
					// -> a = ”primul sir al d”;
	strchr(a, c); //cauta caracterul c in sirul a

	//etc.
}

