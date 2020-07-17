/*************************************
PROJECT: BANK MANAGEMENT SOFTWARE
BY: Rusu Octavian
DATE: 07.2020
FILE: Implementation.cpp
**************************************/


#include "BankManagement.h"
#include <iostream>
#include <vector>
#include <algorithm>    //for generating random AccNum.
#include <chrono>       // for the _sleep().
using namespace std;

//PROTOTYPES
void NewAccount();
void ClearScreen();
void DisplayMenu();
void DisplayAccount(BankAccount user);
void AccountName(BankAccount user);
void DisplayAccountSelection();
void InstanceSetUp(string FirstName, string LastName, string AccNumber, char AccountType, double InitialDeposit); //For NewAccount.
string random_string( size_t length );


//INSTANCE DEFINITION

//Create the instance universal and only modify it when creating an account.
//Limits account numbers and introduces alot of if statements and static ints.

BankAccount user1(" ", 0, "FirstName", "LastName", 'C');
BankAccount user2(" ", 0, "FirstName", "LastName", 'C');
BankAccount user3(" ", 0, "FirstName", "LastName", 'C');
BankAccount user4(" ", 0, "FirstName", "LastName", 'C');
BankAccount user5(" ", 0, "FirstName", "LastName", 'C'); 


//CHECKING INPUT VARIABLES
int temp{1}; // For different account creation.
vector< string > allNames{};


int main(){

    //INPUT VARIABLES
    int selection{};
    int selection2{};
    int MoneyTransaction{};

    do
    {
        //Bank Intro
        DisplayMenu();

        cin >> selection;

        switch(selection){

            case 1:
                NewAccount();
                break;

            case 2:
                //DEPOSIT AMOUNT
                break;
       
            case 3:
                //Withdraw
                DisplayAccountSelection();

                cin >> selection2;

                switch (selection2)
                {
                case 1:

                    DisplayAccount(user1);

                    cout << "\n\n How much would you like to withdraw?\n:";
                    cin >> MoneyTransaction;

                    if(user1.getBalance() >= MoneyTransaction){
                        user1.withdrawBalance(MoneyTransaction);
                    }else{
                        cout << "You cannot withdraw more than your current balance.";
                    }

                    break;
                case 2:
                    DisplayAccount(user2);
                case 3:
                    DisplayAccount(user3);
                case 4:
                    DisplayAccount(user4);
                case 5:
                    DisplayAccount(user5);
                default:
                    break;
                }

                break;

            case 4:
                //Balance Inquiry
                DisplayAccountSelection();

                cin >> selection2;

                switch (selection2)
                {
                case 1:
                    DisplayAccount(user1);
                    break;
                case 2:
                    DisplayAccount(user2);
                case 3:
                    DisplayAccount(user3);
                case 4:
                    DisplayAccount(user4);
                case 5:
                    DisplayAccount(user5);
                default:
                    break;
                }

                break;

            case 5:
                DisplayAccountSelection();
                break;

            case 6:
                //Close an account
                break;

            case 7:
                //modify an account
                break;
                
            default:
                cout << "no way Hose.";
                break;
        }


    } while (selection != 8);

    return 0;
}

void NewAccount(){

    string FirstName;
    string LastName;
    string FullName;
    string AccNumber{};
    double InitialDeposit{};
    char AccountType;

    ClearScreen();

    //CHECK IF YOU ALREADY HAVE THE MAX NUMBER OF ACCOUNTS
    if(temp == 6){
        cout << "You have created the maximum amount of accounts permitted. \nPlease delete one in order to create a new one.";
        return;
    }

    //INTRO SCREEN
    cout << "\n\n--- NEW ACCOUNT ENTERY FORM ---" << endl << endl;
    cout << "You can create a maximum of 5 different accounts. \nThis account is number " << temp << " out of 5.\n";

    //ASK FOR NAME
    cout << "\nEnter your FIRST NAME: ";
    cin >> FirstName;

    cout << "\nEnter your LAST NAME: ";
    cin >> LastName;

    //VERIFY IF ACCOUNT WITH NAME ALREADY EXISTS.
    FullName = FirstName + " " + LastName;
    
    for(int i{}; i < allNames.size(); ++i){
        if(allNames[i] == FullName){
            char answer;
            ClearScreen();
            cout << "\n\nThere is already an account with the name " << FullName << ".";
            cout << "\nWould you like to use another name? Y/N \n";
            cin >> answer;
            if(answer == 'Y' || answer == 'y'){
                NewAccount();
            }else if(answer == 'N' || answer == 'n'){
                return;
            }
        }
    }
    
    //INSERT NAME IN VECTOR FOR FUTURE CHECKING
    allNames.push_back(FullName);

    //GENERATE ALPHA-NUMERIC RANDOM ACCOUNT NUMBER.
    AccNumber = "RO0" + to_string(temp) + random_string(15);

    //ASK FOR TYPE OF ACCOUNT
    ClearScreen();
    char temp2{};
    cout << "Please state the type of account desired. Checking (C) or Savings (S): \n";
    cin >> temp2;

    if(temp2 == 'S' || temp2 == 's' || temp2 == 'C' || temp2 == 'c'){
        AccountType = temp2;

    }else{
        ClearScreen();
        cout << "That is not a valid account type.\nFor security reasons, you will be redirected to the start of the form in \n";
        
        //Countdown from 5 to 0.
        int counter = 5;
        for(int i{0}; i < counter; ){
            cout << counter << endl;
            _sleep(1000);
            --counter;
        }

        NewAccount();
    }
    

    //ASK FOR INITIAL DEPOSIT
    ClearScreen();
    cout << "Hello, " << FirstName << " " << LastName << ".";
    cout << "\nPlease enter the initial deposit: ";
    cin >> InitialDeposit;

    //SET-UP INSTANCE OF BankAccount.
    InstanceSetUp(FirstName, LastName, AccNumber, AccountType, InitialDeposit);

}

void InstanceSetUp(string FName, string LName, string ANumber, char AccType, double IDeposit){

    //Shit, but it doesn't works.
    if(temp == 1){
        user1.setAccountNumber(ANumber);
        user1.setFirstName(FName);
        user1.setLastName(LName);
        user1.depositBalance(IDeposit);
        user1.setType(AccType);
        user1.setInitialization(true);
        ++temp;

        ClearScreen();
        cout << "Please confirm your details:";
        cout << "\n\nAccount name: " << user1.getFullName();
        cout << "\nAccount number: " << user1.getAccountNumber();
        cout << "\nAccount type: " << user1.getType();
        cout << "\nInitial deposit: " << user1.getBalance();
        cout << "\n\nPlease verify your details.";
        _sleep(5000);

    }else if(temp == 2){
        user2.setAccountNumber(ANumber);
        user2.setFirstName(FName);
        user2.setLastName(LName);
        user2.depositBalance(IDeposit);
        user2.setType(AccType);
        user2.setInitialization(true);
        ++temp;

        ClearScreen();
        cout << "Please confirm your details:";
        cout << "\n\nAccount name: " << user2.getFullName();
        cout << "\nAccount number: " << user2.getAccountNumber();
        cout << "\nAccount type: " << user2.getType();
        cout << "\nInitial deposit: " << user2.getBalance();
        cout << "\n\nPlease verify your details.";
        _sleep(5000);

    }else if(temp == 3){
        user3.setAccountNumber(ANumber);
        user3.setFirstName(FName);
        user3.setLastName(LName);
        user3.depositBalance(IDeposit);
        user3.setType(AccType);
        user3.setInitialization(true);
        ++temp;

        ClearScreen();
        cout << "Please confirm your details:";
        cout << "\n\nAccount name: " << user3.getFullName();
        cout << "\nAccount number: " << user3.getAccountNumber();
        cout << "\nAccount type: " << user3.getType();
        cout << "\nInitial deposit: " << user3.getBalance();
        cout << "\n\nPlease verify your details.";
        _sleep(5000);

    }else if(temp == 4){
        user4.setAccountNumber(ANumber);
        user4.setFirstName(FName);
        user4.setLastName(LName);
        user4.depositBalance(IDeposit);
        user4.setType(AccType);
        user4.setInitialization(true);
        ++temp;

        ClearScreen();
        cout << "Please confirm your details:";
        cout << "\n\nAccount name: " << user4.getFullName();
        cout << "\nAccount number: " << user4.getAccountNumber();
        cout << "\nAccount type: " << user4.getType();
        cout << "\nInitial deposit: " << user4.getBalance();
        cout << "\n\nPlease verify your details.";
        _sleep(5000);

    }else if(temp == 5){
        user5.setAccountNumber(ANumber);
        user5.setFirstName(FName);
        user5.setLastName(LName);
        user5.depositBalance(IDeposit);
        user5.setType(AccType);
        user5.setInitialization(true);
        ++temp;

        ClearScreen();
        cout << "Please confirm your details:";
        cout << "\n\nAccount name: " << user5.getFullName();
        cout << "\nAccount number: " << user5.getAccountNumber();
        cout << "\nAccount type: " << user5.getType();
        cout << "\nInitial deposit: " << user5.getBalance();
        cout << "\n\nPlease verify your details.";
        _sleep(5000);
    }
}

void DisplayAccount(BankAccount user){
//Display one account details
    if(user.getInitialization() == true){
        cout << "\n NAME: " << user.getFullName();
        cout << "\n ACCOUNT NUMBER: " << user.getAccountNumber();
        cout << "\n ACCOUNT TYPE: " << user.getType();
        cout << "\n BALANCE: " << user.getBalance() << "\n\n";
        _sleep(5000);
    }else{
        return;
    }
}

void DisplayAccountSelection(){
//Display all accounts for selection, if initialized
    ClearScreen();
    cout << "Please select an account: ";
    if(user1.getInitialization() == true){
        cout << "\n1. ";
        AccountName(user1);
    }
    if(user2.getInitialization() == true){
        cout << "\n2. ";
        AccountName(user2);
    }
    if(user3.getInitialization() == true){
        cout << "\n3. ";
        AccountName(user3);
    }
    if(user4.getInitialization() == true){
        cout << "\n4. ";
        AccountName(user4);
    }
    if(user5.getInitialization() == true){
        cout << "\n5. ";
        AccountName(user5);
    }
}

void AccountName(BankAccount user){
//Display only the account name, if the user is initialized
    if(user.getInitialization() == true){
        cout << "ACCOUNT NAME: " << user.getFullName() << "\n\n";
    }else{
        return;
    }
}


void DisplayMenu(){

    // ClearScreen();

    cout << "\nMAIN MENU";
    cout << "\n\n1. NEW ACCOUNT.";
    cout << "\n2. DEPOSIT AMOUNT.";
    cout << "\n3. WITHDRAW AMOUNT.";
    cout << "\n4. BALANCE ENQUIRY.";
    cout << "\n5. ALL ACCOUNT HOLDER LIST.";
    cout << "\n6. CLOSE AN ACCOUNT.";
    cout << "\n7. MODIFY AN ACCOUNT.";
    cout << "\n8. EXIT.\n\n";
}

void ClearScreen(){
    cout << string(100, '\n'); // Pathetic, but it works.
}

//GENERATE RANDOM ALPHA-NUMERIC ACCOUNT NUMBER
//From the InterWeb, haha
string random_string( size_t length )
