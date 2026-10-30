#include <iostream>
using namespace std;

class complex{
    private:
    int real,imag;
    public:
    void get(){
        cin >> real >> imag;
    }
    complex operator + (complex);
    void display(){
        cout << real << "+" << imag <<"i"<<endl;
    }
};
complex complex::operator+(complex c1){
    complex c2;
    c2.real=real+c1.real;
    c2.imag=imag+c2.imag;
    return c2;
};
int main(){
    complex c1,c2,c3;
    c1.get();
    c2.get();
    c3=c1+c2;
    c3.display();

}