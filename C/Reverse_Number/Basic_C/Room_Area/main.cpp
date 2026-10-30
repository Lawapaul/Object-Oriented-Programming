//Program to Calculate area of room

#include <iostream>

using namespace std;

int main(){
    
    int room_width;
    int room_lenght;
    cout << "Enter Room Width: ";
    cin >> room_width;
    cout <<"Enter Room lenght: ";
    cin >> room_lenght;
    
    cout << "Room area is: " << room_lenght*room_width << " Square feet " << endl;
    return 0;
    
}
