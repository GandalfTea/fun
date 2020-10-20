#include <iostream>
#include "Login.h"

using namespace std;
UserLogin DickInButt;

int main(){
    
    size_t Answer{};
    
    do {
        cin >> Answer;
    
        switch(Answer){
            case 1:
            {
                string user;
                cout << "Username :";
                cin >> user;
                string pass;
                cout << "pass : ";
                cin >> pass;

                if (DickInButt.Register(user, pass)){
                    cout << "If you see this u are gay.";
                }else{
                    cout << "This shit has failed.";
                }

                break;
            }
            //Lecture tuesday 
            case 2:
            {
                string user1;
                cout << "Username :";
                cin >> user1;
                string pass2;
                cout << "pass : ";
                cin >> pass2;
                
                if (DickInButt.Login(user1, pass2)){
                    cout << "YOU SHALL ENTER, COMMONER!";
                }else{
                    cout << "This shit had omega-failed!";
                }
                break;
            }
        }
    }while (Answer != 69);

    return 0;
}