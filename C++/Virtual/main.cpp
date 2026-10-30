#include <iostream>
using namespace std;

class shape{
    protected:
    int x;
    public:
    void get(){
        cin >>x;    }
    virtual int calculator() =0;
};
class square:public shape{
    public:
    int calculator(){
        cout << x*x << endl;
    }

};
class circle:public square{
    public:
    int calculator(){
        cout << 3.14*x*x << endl;
    }
};
int main(){
    circle c1,*ptr;
    square s1,*ptr1;
    ptr=&c1;
    ptr1=&s1;
    ptr->get();
    ptr1->get();
    ptr->calculator();
    ptr1->calculator();

}
