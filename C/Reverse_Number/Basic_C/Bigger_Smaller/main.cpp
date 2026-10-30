#include <iostream>
using namespace std;


int main(){
    
    int num1;
    int num2;
    
    cout << "Enter Number with space between them: ";
    cin >> num1 >> num2;
    
    if (num1==num2){
        
        cout<< "Numbers are equal";
        }
        
    else{
        cout << "Greatest Number: " << ((num1>num2) ? num1 : num2) << "\nSmallest Number: " << ((num1<num2) ? num1 : num2) << endl;
        
        }
    return 0;
}