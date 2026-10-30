#include <iostream>
using namespace std;

int main(){
    
    int choice{};
    cout <<"Enter Number: ";
    cin >> choice;
    
    if (choice==0){
        cout << "Neither Even nor Odd" << endl;
        
    }
        
    else{
       cout << "Number is: " << ((choice%2==0) ? "Even" : "Odd") << endl;
       
       
    }
    

    
    return 0;
}