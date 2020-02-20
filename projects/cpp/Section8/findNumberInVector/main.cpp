#include <iostream>
#include <vector>

using namespace std;


int main(){
    
    vector <int> vec {1,2,3,4,5};
    
    int count {0};
    while(count < vec.size()){
        if(vec.at(count) == -99){
            cout << "-99 is at index " << count << endl;
            break;
        } else {
            cout << vec.at(count) << " is at index " << count << endl;
        }
        count++;
    }
    return 0;
}