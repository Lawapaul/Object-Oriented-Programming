#include <iostream>
using namespace std;

class clock{
    private:
    int h,m,s;
    public:
    void get(){
        cin >> h;
        cin >> m;
        cin >> s;
    }
    void add(clock c1,clock c2){
        clock c3;
        c3.s=c1.s+c2.s;
        int count=0;
        int count1=0;
        while(c3.s>60){
            c3.s-=60;
            count+=1;
        }
        c3.m=c1.m+c2.m+count;
        while(c3.m>60){
            c3.m-=60;
            count1+=1;
        }
        c3.h=c1.h+c2.h+count1;
        cout << c3.h << " " << c3.m << " " << c3.s;
    }
};
int main(){
    clock c1;
}