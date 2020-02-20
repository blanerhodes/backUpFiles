#include <iostream>

using namespace std;

int main(){
    
    int cents {0};
    cout << "Enter an amount in cents :";
    cin >> cents;
    
    //THIS BLOCK DOESNT USE MODULO
    
    int dollars {}, quarters {}, dimes {}, nickels {}, pennies {}, change {};
//    dollars = cents / 100;
//    change = cents - dollars *100;
//    quarters = change / 25;
//    dimes = (change -25* quarters) / 10;
//    nickels = (change - 25 * quarters - 10 * dimes) / 5;
//    pennies = change - 25 *quarters - 10 * dimes - 5*nickels;
    
    //THIS BLOCK USES MODULO
    dollars = cents /  100;
    change = cents % 100;
    quarters = change / 25;
    dimes = change % 25 / 10;
    nickels = change % 25 % 10 / 5;
    pennies = change % 25 % 10 % 5;
    
    cout << "dollars: " << dollars << endl;
    cout << "quarters: " << quarters << endl;
    cout << "dimes: " << dimes << endl;
    cout << "nickels: " << nickels << endl;
    cout << "pennies: " << pennies << endl;
    
    return 0;
}