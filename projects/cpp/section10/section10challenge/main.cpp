#include <iostream>
#include <string>

using namespace std;

int main(){
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    
    string message;
    cout << "Enter a message to encrypt: ";
    getline(cin, message);
    string new_message;
    
    for(char message_letter: message) {
        int alpha_index = alphabet.find(message_letter);
        if(alpha_index == -1){
            new_message.push_back(message_letter);
        } else{
            new_message.push_back(key.at(alpha_index));
        }
    }
    cout<<new_message<<endl;
    message.clear();
    
    for(char enc_letter: new_message){
        int enc_index = key.find(enc_letter);
        if(enc_index == -1) {
            message.push_back(enc_letter);
        } else{
            message.push_back(alphabet.at(enc_index));
        }
    }
    cout << message <<endl;
    return 0;
}