#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string message;
    cout << "Enter a continuous line of text: ";
    cin >> message;
    
    for(size_t message_index{0}; message_index<message.length(); message_index++){
        size_t buffer_size = message.length() - (1+message_index);
        string buffer(buffer_size, ' ');
        string forward_substr {};
        string reverse_substr {};
        forward_substr = message.substr(0,message_index+1);
        reverse_substr =  message.substr(0,message_index);
        reverse(reverse_substr.begin(), reverse_substr.end());
        cout << buffer<< forward_substr<< reverse_substr<<endl;
    }
    
    
    return 0;
}