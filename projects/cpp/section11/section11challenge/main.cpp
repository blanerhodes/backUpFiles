#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void trigger_p(vector <int>);
void trigger_a(vector <int> &v);
void trigger_r(vector <int> &v);
void trigger_n(vector <int> &v, int);
void trigger_i(vector <int> &v, int);
void trigger_c(vector <int> &v);
void trigger_m(vector <int>);
void trigger_f(vector <int>);
void trigger_s(vector <int>);
void trigger_l(vector <int>);
void trigger_q(vector <int> &v);

int main(){
    char selection {};
    vector <int> vec;
    do{
        cout << "=========================================" << endl;
        cout << "P - Print numbers from vector" << endl;
        cout << "A - Add numbers to vector" << endl;
        cout << "R - Remove a given or remove number at given index" << endl;
        cout << "C - Clear the vector of all numbers" << endl;
        cout << "M - Print mean of numbers in vector" << endl;
        cout << "F - Find a given number in vector" << endl;
        cout << "S - Print smallest number in vector" << endl;
        cout << "L - Print largest number in vector" << endl;
        cout << "Q - Quit program" << endl;
        cout << endl;
        cout << "Enter your selection: ";
        cin >> selection;
        cout << endl;
        
        if(selection == 'p' || selection == 'P'){
            trigger_p(vec);
            
        } else if(selection == 'a' || selection == 'A'){
            trigger_a(vec);
            
        } else if (selection == 'r' || selection == 'R'){
            trigger_r(vec);
            
        } else if(selection == 'c' || selection == 'C'){
            trigger_c(vec);
            
        }else if(selection == 'm' || selection == 'M'){
            trigger_m(vec);
        
        } else if(selection == 'f' || selection == 'F'){
            trigger_f(vec);
            
        }else if(selection == 's' || selection == 'S'){
            trigger_s(vec);
            
        }else if(selection == 'l' || selection == 'L'){
           trigger_l(vec);
            
        } else if(selection == 'q' || selection == 'Q'){
            trigger_q(vec);
            
        } else {
            cout << "Sorry, that's an illegal input. Try again." << endl;
        }
    } while(selection != 'q' && selection != 'Q');  
    
    return 0;
}


void trigger_p(vector <int> vec){
    cout << "[";
            if(vec.size() >= 1){
                for(size_t index {0}; index < vec.size()-1; index++){
                    cout << vec.at(index) << ", ";
                }
                cout << vec.at(vec.size()-1);
            }
            cout << "]"<< endl;
}

void trigger_a(vector <int> &vec){
    int add_num {0};
            cout << "Input an integer you wish to add: ";
            cin >> add_num;
            vec.push_back(add_num);
            cout << add_num << " was added to the vector." << endl;
}

void trigger_n(vector <int> &vec, int num){
    cout << "What number do you want to remove?: ";
    cin >> num;
    vec.erase(std::remove(vec.begin(), vec.end(), num), vec.end());
}

void trigger_i(vector <int> &vec, int num){
    cout << "What index do you want to remove from?:";
    cin >> num;
    if(num < vec.size() && num >=0){
        vec.erase(vec.begin()+num);
    } else{
        cout << "The vector doesn't contain that index try again."<<endl;
    }
}

void trigger_r(vector <int> &vec){
    char remove {};
    cout << "Press 'N' to remove a specific number and all instances of it. Press 'I' to remove a number at that index: ";
    cin >> remove;
    int remove_number {0};
    if(vec.size()>0){
        if(remove == 'n' || remove == 'N'){
            trigger_n(vec, remove_number);
        } else if(remove == 'i' || remove == 'I'){
            trigger_i(vec, remove_number);
        } else {
            cout << "Sorry, that's an illegal input." << endl;
        }
    } else{
        cout << "Add some numbers to the vector for me to work with first!"<<endl;
    }
}

void trigger_c(vector <int> &vec){
    vec.clear();
    cout << "Vector successfully nuked." << endl;
}

void trigger_m(vector <int> vec){
    int num_sum {0};
    double num_mean {0.0};
    if(vec.size() > 0){
        for(auto num : vec){
            num_sum += num;
        }
        num_mean = static_cast<double>(num_sum) / vec.size();
        cout << "The mean is " << num_mean << endl;
    } else {
        cout << "This vector is empty and has no mean." << endl;
    }
}

void trigger_f(vector <int> vec){
    int find_num {0};
    cout << "What number are you trying to find?: ";
    cin >> find_num;
    if(vec.size() > 0){
        for(size_t index {0}; index < vec.size(); index++){
            if(vec.at(index) == find_num){
                cout << "The number " << find_num << " is at index " << index << endl;
                break;
            } else if(index == vec.size()-1 && vec.at(index) != find_num) {
                cout << "Sorry, " << find_num << " isn't in the vector." << endl;
            }
        }
    } else {
        cout << "This vector has no numbers since it's empty." << endl;
    }
}

void trigger_s(vector <int> vec){
    int smallest {0};
    if(vec.size() > 0){
        smallest = vec.at(0);
        for(auto num : vec){
            if(num < smallest){
                smallest = num;
            }
        }
        cout << "The smallest number in the vector is " << smallest << endl;
    } else {
        cout << "This vector is empty so there's no smallest number." << endl;
    }
}

void trigger_l(vector <int> vec){
     int largest {0};
    if(vec.size() > 0){
        largest = vec.at(0);
        for(auto num : vec){
            if(num > largest){
                largest = num;
            }
        }
        cout << "The largest number in the vector is " << largest << endl;
    } else {
        cout << "This vector is empty so there's no largest number." << endl;
    }
}

void trigger_q(vector <int> &vec){
    vec.clear();
    cout << "Goodbye!" << endl;
}