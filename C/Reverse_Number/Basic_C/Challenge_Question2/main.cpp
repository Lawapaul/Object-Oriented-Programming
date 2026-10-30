/*
 * Welcome to Page. This program helps users who run cleaning services. It helps them to calculate fair easily
 */ 

#include <iostream>

using namespace std;
int main(){
    
    const int small_price {25};
    const int large_price {35};
    const double fixed_taxt {0.066};
    const double tax {6.6};
    int small_rooms;
    int large_rooms;
    
    cout <<"Hello! Welcome to Frank's Cleaning Service" << endl;
    cout <<"\nEnter Number of Small Rooms: ";
    cin >> small_rooms;
    cout <<"Enter Number of Large Rooms: ";
    cin >>large_rooms;
    cout << "Price for small rooms: $" << small_price << endl;
    cout << "Price for large Rooms: $" << large_price << endl;
    cout << "Tax: " << tax <<"%" << endl;
    cout << "===================================================================" <<endl;
    cout << "Total Estimate: $" << (small_rooms*small_price)+(large_rooms*large_price) + ((small_rooms*small_price)+(large_rooms*large_price))* fixed_taxt << endl;
    cout << "This estimate is valid for 30 days only" << endl;
    return 0;
    
    
    
}