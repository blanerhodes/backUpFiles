#include <iostream>

using namespace std;

int main(){
    
    const float usd_per_eur {1.19};
    
    cout << "Input dollar amount to covert: ";
    float usd_input {0};
    cin >> usd_input;
    cout << "You have " << usd_input / usd_per_eur << " euros." << endl;
    
    return 0;
}