#include "SHA_256.h"
#include<iostream>
#include <string>

using namespace std;


int main(){
    string msg;
    cout << "Tell me the string, pissface : ";
    cin >> msg;
    vector<string> holdString;

    // SHA_256 SHA_256;
    string i = EncryptFunction(msg);
    string j = EncryptFunction(msg);
    cout << i << endl;
    cout << j << endl;

    // for(string i; ; ){
    //     i = EncryptFunction(msg);
    //     cout << "\n" << i;
    //     for (string j : holdString) {
    //         if(j == i){
    //             cout << "1";
    //             return 0;
    //         }
    //         cout << "0";
    //     }
    //     cout << "\n";
    //     holdString.push_back(i);
    // }
    return 0;
}