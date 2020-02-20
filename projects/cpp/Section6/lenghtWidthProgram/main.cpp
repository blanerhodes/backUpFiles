#include <iostream>

using namespace std;

int main(){
    int length;
    int width;
    cout << "Input length and width separated by a space:";
    cin >> length >> width;
    int area {length * width};
    cout << "The area of the room is " << area << endl;
    
    return 0;
}