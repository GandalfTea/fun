/*************************************
PROJECT: BANK MANAGEMENT SOFTWARE
BY: Rusu Octavian
DATE: 07.2020
FILE: Class CPP
**************************************/


#include "BankManagement.h"
#include <iostream>

BankAccount::BankAccount(string AccNum, double Money, string FirName, string LstName, char AccountType, bool Init){
    AccountNumber = AccNum;
    Balance = Money;
    FirstName = FirName;
    LastName = LstName;
    AccType = AccountType;
    Initialized = Init;
}
//ACCOUNT NUMBER
void BankAccount::setAccountNumber(string Num) {
    AccountNumber = Num;
}

string BankAccount::getAccountNumber(){
    return AccountNumber;
}

//BALANCE
void BankAccount::depositBalance(double Sum){
    Balance += Sum;
    //Maybe create a top-up limit.
}

void BankAccount::withdrawBalance(double Sum){
    if(Sum <= Balance){
        Balance -= Sum;
    }
}

double BankAccount::getBalance(){
    return Balance;
}

//ACCOUNT NAME
string BankAccount::getFirstName(){
    return FirstName;
}

void BankAccount::setFirstName(string Name){
    
    // Check if not previous name
    FirstName = Name;
}

string BankAccount::getLastName(){
    return LastName;
}

void BankAccount::setLastName(string Name){
    
    // Check if not previous name
    LastName = Name;
}

string BankAccount::getFullName(){
    return FirstName + " " + LastName;
}


//ACCOUNT TYPE
void BankAccount::setType(char a){
    AccType = a;
}

char BankAccount::getType(){
    return AccType;
}

//Initialization functions

void BankAccount::setInitialization(bool a){
    Initialized = a;
}

bool BankAccount::getInitialization(){
    return Initialized;
}
