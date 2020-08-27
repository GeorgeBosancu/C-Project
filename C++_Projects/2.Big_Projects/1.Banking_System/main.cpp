#include<iostream>
#include "Account.h"
#include "Bank.h"
using namespace std;

long Account::NextAccountNumber = 0; ///static member from Account class, defined outside

int main(){

    Bank b;
    Account acc;

    int choice;
    string fname, lname;
    long accountNumber;
    float balance;
    float amount;

    cout<<" ===> Banking System <=== "<<endl;
    do
    {
        cout<<"\n\tSelect one option below:"<<endl;
        cout<<"\t1 Open an account"<<endl;
        cout<<"\t2 Balance Enquiry"<<endl;
        cout<<"\t3 Deposit"<<endl;
        cout<<"\t4 Withdrawl"<<endl;
        cout<<"\t5 Close an Account"<<endl;
        cout<<"\t6 Show all Accounts"<<endl;
        cout<<"\t7 Quit"<<endl;
        cout<<"\n Enter your choice:"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter First Name:"; cin>>fname;
            cout<<"Enter Last Name:"; cin>>lname;
            cout<<"Enter initial balance:"; cin>>balance;
            acc=b.OpenAccount(fname, lname, balance);
            cout<<"-------------------------------------";
            cout<<endl<<"Congratulation!! Account is Created!"<<endl;
            cout<<acc;
            break;
        case 2:
            cout<<"Enter Account Number:";
            cin>>accountNumber;
            acc= b.BalanceEnquiry(accountNumber);
            cout<<"-------------------------------------";
            cout<<endl<<"Your Account Details:"<<endl;
            cout<<acc;
            break;
        case 3:
            cout<<"Enter Account Number:";
            cin>>accountNumber;
            cout<<"Enter Balance:";
            cin>>amount;
            acc=b.Deposit(accountNumber, amount);
            cout<<"-------------------------------------";
            cout<<endl<<"Amount is Deposited"<<endl;
            cout<<acc;
            break;
        case 4:
            cout<<"Enter Account Number:";
            cin>>accountNumber;
            cout<<"Enter Balance:";
            cin>>amount;
            acc=b.Withdraw(accountNumber, amount);
            cout<<"-------------------------------------";
            cout<<endl<<"Amount Withdraw"<<endl;
            cout<<acc;
            break;
        case 5:
            cout<<"Enter  Account Number:";
            cin>>accountNumber;
            b.CloseAccount(accountNumber);
            cout<<"-------------------------------------";
            cout<<endl<<"Account is Closed"<<endl;
            cout<<acc;
            break;
        case 6:
            cout<<"-------------------------------------"<<endl;;
            b.ShowAllAccounts();
            break;
        case 7:
            break;
        default:
            cout<<"-------------------------------------";
            cout<<"n Enter a correct choice";
            exit(0);
            }
        } while(choice != 7);
return 0;
}



