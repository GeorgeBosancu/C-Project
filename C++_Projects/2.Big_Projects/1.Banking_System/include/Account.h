#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<iostream>
using namespace std;

class InsuficientFunds{}; ///exceptie pentru fonduri insuficinte
class Account{
private:
    long accountNumber;
    string firstName;
    string lastName;
    float balance;
    static long NextAccountNumber;
public:
    ///constructors:
    Account(){};
    Account(string fname, string lname, float balance);

    ///getters
    long getAccNo(){return accountNumber;}
    string getFirstName(){return firstName;}
    string getLastName(){return lastName;}
    float getBalance(){return balance;}

    ///functions
    void Deposit(float amount);
    void Withdraw(float amount);
    ///functions for access static variable
    static void setLastAccountNumber(long accountNumber);
    static long getLastAccountNumber();

    ///operators:
    friend ofstream  & operator << (ofstream &ofs, Account &acc); ///pentru fisier
    friend ifstream & operator >> (ifstream &ifs, Account &acc);
    friend ostream & operator << (ostream & os, Account &acc); ///output normal (cout)
};

#endif // ACCOUNT_H
