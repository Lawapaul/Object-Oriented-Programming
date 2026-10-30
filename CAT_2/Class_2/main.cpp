#include <iostream>
using namespace std;

class employ{
    private:
    int age,salary;
    public:
    void setdata(int a,int b){
        age=a;salary=b;
    }
    void display(){
        cout << "Age: " << age << "\nSalary: "<< salary;
    }
};
int main(){
    employ t1;
    t1.setdata(18,18000);
    t1.display();
}