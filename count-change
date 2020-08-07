#include <iostream>
using namespace std;

int value(int TypeCoin){
   switch (TypeCoin){
    case 5:
       return 50;
    case 4:
        return 25;
    case 3:
        return 10;
    case 2:
        return 5;
    case 1:
        return 1;
       break;
   default:
       break;
   }
    return 0;
}

int cc(int amount, int TypeCoin){

    if(amount < 0 || TypeCoin == 0){
        return 0;
    }
    if (amount == 0){
        return 1;
    }else{
        return cc(amount, (TypeCoin - 1)) + cc((amount - value(TypeCoin)), TypeCoin);
    }
}

int main(){
    int amount{};
    cin >> amount;
    cout << cc(amount, 5);
}
