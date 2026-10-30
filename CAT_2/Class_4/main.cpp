#include <iostream>
using namespace std;

class complex{
    private:
    int real,imag;
    public:
    void get(){
        cin >> real;
        cin >> imag;
    }
    void add(complex c1,complex c2){
        complex c3;
        c3.real=c1.real+c2.real;
        c3.imag=c1.imag+c2.imag;
        cout << c3.real << "+" << c3.imag << "i";
    }
};
int main(){
    complex c1,c2,c3;
    c1.get();
    c2.get();
    c3.add(c1,c2);
}