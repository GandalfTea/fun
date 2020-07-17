/*************************************
PROJECT: BANK MANAGEMENT SOFTWARE
BY: Rusu Octavian
DATE: 07.2020
**************************************/


#ifndef BANK_H
#define BANK_H

using namespace std;
#include <string>

class BankAccount {
private:

    string AccountNumber{}; //Should I initialize?
    double Balance{};
    string FirstName;
    string LastName;
    char AccType;
    bool Initialized;

public:
    
    //Constructor.
    BankAccount(string AccountNumber = " ", double Balance = 0, string FirstName = "Uninitialized", string LastName = "Account", char AccType = 'C', bool Init = false);

    //Account number functions
    void setAccountNumber(string AccNum); //Prevent two acc with same number;
    string getAccountNumber();

    //Balance functions
    void depositBalance(double Sum);
    void withdrawBalance(double Sum);
    double getBalance();

    //AccName functions
    string getFirstName();
    void setFirstName(string name); //Prevent same names
    string getLastName();
    void setLastName(string name);
    string getFullName();

    //Account Type functions
    void setType(char a);
    char getType();

    //Initialization functions
    void setInitialization(bool a);
    bool getInitialization();

};

#endif
