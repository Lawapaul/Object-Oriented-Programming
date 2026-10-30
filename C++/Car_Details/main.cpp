#include <iostream>
using namespace std;
class mark{
    private:
    char Company[50];
    int ts;
    public:
    void get(){
        cin >> Company >> ts;
    }
    void display(){
        cout << Company << " " << ts << endl;
    }
};
int main(){
    mark m1;
    m1.get();
    m1.display();
}
