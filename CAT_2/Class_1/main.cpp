#include <iostream>
using namespace std;
class rectange{
    private:
    int width,height;
    public:
    void setdata(int a,int b){
        width=a;height=b;
    }
    void area(){
        cout << width*height;
    }
};
int main(){
    rectange t1;
    t1.setdata(3,4);
    t1.area();
}