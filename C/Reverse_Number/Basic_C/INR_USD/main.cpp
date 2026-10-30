#include <iostream>
using namespace std;

int main(){
    
    int option {};
    float Usd_rate {0.012};
    float Inr_rate {83.09};
    float amount {};
    
    cout << "1. INR to USD" << "\n2. USD to INR"<< "\n3. Exit" << endl;
    cout << "\nAnswer: ";
    cin >> option;
    
    
    if (option ==1){
        
        cout<< "Enter Amount: ";
        cin >> amount;
        cout << "Rate: " << amount*Usd_rate << endl;
        
        }
    
    else if(option ==2){
        
        cout<< "Enter Amount: ";
        cin >> amount;
        cout << "Rate: " << amount*Inr_rate << endl;
        
        
        
        }
    
    else{
        cout <<"Thankyou! Have a great day!!!" <<endl;
        
        
        }
}