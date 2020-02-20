#include <iostream>

using namespace std;

void print(int *array, size_t size);
int * cross_prod(int *first_array, size_t first_size, int *sec_array, size_t sec_size);


int main(){
    
    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};
    
    cout << "Array 1: ";
    print(array1, 5);
    
    cout << "Array 2: ";
    print(array2, 3);
    
    int *result {nullptr};
    result = cross_prod(array1, 5, array2, 3);
    print(result, 15);
    
    delete [] result;
    return 0;
}


void print(int array[], size_t size){
    cout <<"[ ";
    for(size_t i{0}; i<size; i++){
        cout<<array[i]<<" ";
    }
    cout<<"]"<<endl;
}

int * cross_prod(int *first_array, size_t first_size, int *sec_array, size_t sec_size){
    int *array_ptr {nullptr};
    size_t result_size = first_size*sec_size;
    array_ptr = new int[result_size];
    int count{0};
    for(size_t i{0}; i<first_size; i++){
        for(size_t k{0}; k<sec_size; k++){
             array_ptr[count] = first_array[i] * sec_array[k];   
            count++;
        }
    }
    
    return array_ptr;
}