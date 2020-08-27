#include<iostream>
using namespace std;
const int LIM = 100;

///verifica daca stiva este goala
bool isEmpty(int k) {
    if(k == 0)
        return true;
    return false;
}

///adauga un element nou in stiva
void push(int stiva[], int &k, int numar) {
    k = k + 1;
    stiva[k] = numar;
}

///afiseaza varful stivei
int peek(int stiva[], int k) {
    return stiva[k];
}

///sterge varful stivei
int pop(int stiva[], int &k) {
    int rezultat = peek(stiva, k);
    k = k - 1;
    return rezultat;
}

int size(int k) {
    return k;
}

int main() {
    int stiva[LIM], k = 0;
    push(stiva, k, 2);
    push(stiva, k, 4);
    push(stiva, k, 6);
    push(stiva, k, 7);
    push(stiva, k, 8);
    cout << pop(stiva, k)<<" ";
    cout << pop(stiva, k)<<" ";
    cout << pop(stiva, k)<<" ";
    return 0;
}
