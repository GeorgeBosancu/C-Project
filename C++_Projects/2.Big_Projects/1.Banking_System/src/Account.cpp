#include "Account.h"
#include<iostream>
#include<fstream>
using namespace std;
#define MIN_BALANCE 500

Account::Account(string fname, string lname, float balance):firstName{fname}, lastName{lname}
{
    NextAccountNumber++;
    accountNumber=NextAccountNumber;
    this->balance=balance;
}
void Account::Deposit(float amount)
{
    balance+=amount;
}

void Account::Withdraw(float amount)
{
    if (balance-amount<MIN_BALANCE)
        throw InsuficientFunds();
    balance-=amount;
}

void Account::setLastAccountNumber(long accountNumber)
{
    NextAccountNumber=accountNumber;
}
long Account::getLastAccountNumber()
{
    return NextAccountNumber;
}

ofstream &operator<<(ofstream &ofs, Account &acc)
{
    ofs<<acc.accountNumber<<endl;
    ofs<<acc.firstName<<endl;
    ofs<<acc.lastName<<endl;
    ofs<<acc.balance<<endl;
    return ofs;
}

ifstream &operator >>(ifstream &ifs, Account &acc)
{
    ifs>>acc.accountNumber;
    ifs>>acc.firstName;
    ifs>>acc.lastName;
    ifs>>acc.balance;
    return ifs;
}

ostream &operator <<(ostream & os, Account &acc)
{
    os<<"First Name:"<<acc.getFirstName()<<endl;
    os<<"Last Name:"<<acc.getLastName()<<endl;
    os<<"Account Number:"<<acc.getAccNo()<<endl;
    os<<"Balance:"<<acc.getBalance()<<endl;
    return os;
}

