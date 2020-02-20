#include <iostream>

using namespace std;

int main(){
    
    const int cost_per_small_room {25};
    const int cost_per_large_room {35};
    const float tax_rate {0.06};
    const int valid_timeframe {30};
    
    cout << "How many small rooms do you want cleaned? ";
    int number_of_small_rooms {0};
    cin >> number_of_small_rooms;
    
    cout << "How many large rooms do you want cleaned? ";
    int number_of_large_rooms {0};
    cin >> number_of_large_rooms;
    
    cout << "==============================="<< endl;
    cout << "Estimate for carpet cleaning services:" << endl;
    cout << "Number of small rooms: " << number_of_small_rooms << endl;
    cout << "Number of large rooms: " << number_of_large_rooms << endl;
    cout << "Price per small room: $" << cost_per_small_room << endl;
    cout << "Price per large room: $" << cost_per_large_room << endl;
    int room_cost {(number_of_small_rooms * cost_per_small_room) + (number_of_large_rooms * cost_per_large_room)} ;
    cout << "Room Cost: $" << room_cost << endl;
    float tax_cost {room_cost * tax_rate};
    cout << "Tax Cost: $" << tax_cost << endl;
    cout << "===============================" << endl;
    cout << "Total Estimate: $" << room_cost +  tax_cost << endl;
    cout << "This estimate is valid for " << valid_timeframe << " days" <<endl;
    
    return 0;
}