#include <iostream>
using namespace std;

class salesorder{
    protected:
    int serial[5];
    char ordername[5][50];
    int date[5];
    char address[5][50];
    public:
    void getinfo(){
        for(int i=0;i<5;i++){
            cin>>serial[i]>>ordername[i] >> date[i]>>address[i];
        }
    }
    friend class salesperson;
};
class salesperson{
    protected:
    char name[50];
    int order[3];
    public:
    void get(){
        cin >> name;
        for(int i=0;i<3;i++){
            cin >> order[i];
        }
    }
    void display(){
        for(int i=0;i<5;i++){
            cout << serial[i] << e
        }
    }
};

int main(){
   compare t1;
   t1.getinfo();
   t1.get();
}