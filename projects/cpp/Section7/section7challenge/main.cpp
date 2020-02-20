#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    vector <int> vector1 {};
    vector <int> vector2 {};
    
    vector1.push_back(10);
    vector1.push_back(20);
    
    cout << "vector1 index 0 is " << vector1.at(0) << endl;
    cout << "vector1 index 1 is " << vector1.at(1) << endl;
    cout << "vector1 size is " << vector1.size() << endl;
    
    vector2.push_back(100);
    vector2.push_back(200);
    
    cout << "vector2 index 0 is " << vector2.at(0) << endl;
    cout << "vector2 index 1 is " << vector2.at(1) << endl;
    cout << "vector2 size is " << vector2.size() << endl;
    
    vector <vector<int>> vector_2d {};
    
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);
    
    cout << "vector_2d index 0,0 is " << vector_2d.at(0).at(0) << endl;
    cout << "vector_2d index 0,1 is " << vector_2d.at(0).at(1) << endl;
    cout << "vector_2d index 1,0 is " << vector_2d.at(1).at(0) << endl;
    cout << "vector_2d index 1,1 is " << vector_2d.at(1).at(1) << endl;
    
    vector1.at(0) = 1000;
    
    cout << "vector_2d index 0,0 is " << vector_2d.at(0).at(0) << endl;
    cout << "vector_2d index 0,1 is " << vector_2d.at(0).at(1) << endl;
    cout << "vector_2d index 1,0 is " << vector_2d.at(1).at(0) << endl;
    cout << "vector_2d index 1,1 is " << vector_2d.at(1).at(1) << endl;
    
    cout << "vector1 index 0 is " << vector1.at(0) << endl;
    cout << "vector1 index 1 is " << vector1.at(1) << endl;

    return 0;
}