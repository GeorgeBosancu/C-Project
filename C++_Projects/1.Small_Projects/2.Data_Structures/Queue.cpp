#include    <iostream>
using namespace std;
const int LIM = 100;

///verifica daca avem coada goala
bool isEmpty(int k) {
    if(k == 0)
        return true;
    return false;
}

///adauga un element in coada (la final – uneori aceasta functie mai este denumita si push_back() )
void push(int coada[], int &k, int numar) {
    k = k + 1;
    coada[k] = numar;
}

///afiseaza primul element din coada
int front(int coada[]) {
    return coada[1];
}

///sterge primul element din coada
int pop(int coada[], int &k) {
    int rezultat = coada[1];
    for(int i = 1; i < k - 1; i++)
        coada[i] = coada[i + 1];
    k = k - 1;
    return rezultat;
}

int size(int k) {
    return k;
}

int main() {

    int coada[LIM], k = 0;

    push(coada, k, 2);
    push(coada, k, 4);
    push(coada, k, 6);
    push(coada, k, 7);
    push(coada, k, 8);
    cout << pop(coada, k)<<" ";
    cout << pop(coada, k)<<" ";
    cout << pop(coada, k)<<" ";
    return 0;
}
