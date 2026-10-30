#include <iostream>
using namespace std;
class mark{
    private:
    int marks;
    int spi;
    public:
    void get(){
        cin >> marks >> spi;
    }
    void display(){
        cout << marks << " " << spi << endl;
    }
};
int main(){
    mark m1;
    m1.get();
    m1.display();
}
