#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
            cout << "[";
            if(vec.size() >= 1){
                for(size_t index {0}; index < vec.size()-1; index++){
                    cout << vec.at(index) << ", ";
                }
                cout << vec.at(vec.size()-1);
            }
            cout << "]"<< endl;
            
        } else if(selection == 'a' || selection == 'A'){
            int add_num {0};
            cout << "Input an integer you wish to add: ";
            cin >> add_num;
            vec.push_back(add_num);
            cout << add_num << " was added to the vector." << endl;
            
        } else if ((selection == 'r' || selection == 'R')){
            char remove {};
            cout << "Press 'N' to remove a specific number and all instances of it. Press 'I' to remove a number at that index: ";
            cin >> remove;
            int remove_number {0};
            if(vec.size()>0){
                if(remove == 'n' || remove == 'N'){
                cout << "What number do you want to remove?: ";
                cin >> remove_number;
                vec.erase(std::remove(vec.begin(), vec.end(), remove_number), vec.end());
//                for(size_t number {vec.size()-1}; number>=0; number--){
//                    cout << vec.begin() + number <<endl;
//                    if(vec.at(number) == remove_number){
//                        vec.erase(vec.begin()+number);
//                    }
//                }
                
                } else if(remove == 'i' || remove == 'I'){
                    cout << "What index do you want to remove from?:";
                    cin >> remove_number;
                    if(remove_number < vec.size() && remove_number >=0){
                        vec.erase(vec.begin()+remove_number);
                    } else{
                        cout << "The vector doesn't contain that index try again."<<endl;
                    }
                    
                } else {
                    cout << "Sorry, that's an illegal input." << endl;
                }
            } else{
                cout << "Add some numbers to the vector for me to work with first!"<<endl;
            }
            
        } else if(selection == 'c' || selection == 'C'){
            vec.clear();
            cout << "Vector successfully nuked." << endl;
            
        }else if(selection == 'm' || selection == 'M'){
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
        
        } else if(selection == 'f' || selection == 'F'){
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
            
        }else if(selection == 's' || selection == 'S'){
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
            
        }else if(selection == 'l' || selection == 'L'){
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
            
        } else if(selection == 'q' || selection == 'Q'){
            vec.clear();
            cout << "Goodbye!" << endl;
            
        } else {
            cout << "Sorry, that's an illegal input. Try again." << endl;
        }
    } while(selection != 'q' && selection != 'Q');
    
    return 0;
}