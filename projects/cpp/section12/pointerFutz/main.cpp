#include <iostream>

using namespace std;

void swap(int *a, int *b);

int main(){
    
    int array1[]{1,2,3,4,5};
    int array2[]{10,20,30};
    
    int result_arr[15] = {};
    int count {0};
//    int *array_ptr {nullptr};
//    array_ptr = new int[15];
    
    for(size_t i{0}; i<5; i++){
        for(size_t k{0}; k<3; k++){
            result_arr[count] = array1[i] * array2[k];
            count++;
        }
    }
    for(size_t r{0}; r<15; r++){
        cout<<result_arr[r]<< " ";
    }
    cout<<endl;
    return 0;
}

void swap(int *a, int *b){
    int *temp = a;
    cout << "here" <<a <<endl;
    a = b;
    cout << "here" << a << endl;
    b = temp;
}