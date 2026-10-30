#include <iostream>
using namespace std;

class Mobile_Plan{
    protected:
    char name[100];
    int bprice=500;
    int datalimit;
    int voicecall;
    int text;
    public:
    void get(){
        cin >> voicecall;
        cin >> datalimit;
        cin >> text;
    }
};
class Silver_plan:public Mobile_Plan{
    public:
    int a=bprice;
    int total;
    int d2;
    void display(){
        if(datalimit>15){
            a+=(datalimit-15)*2;
        }
        if(text>100){
            a+=text-100;
        }
        total=a+(2*voicecall);
        if(total <1000){
            d2=30*total/100;
            cout << "SILVER" << endl << total << endl << d2 << endl << total - d2 << endl;
        }
        else if(total > 1000 && total < 2000){
            d2=40*total/100;
            cout << "SILVER" << endl << total << endl << d2 << endl << total - d2 << endl;
        }
        else{
            d2=5*total/100;
            cout << "SILVER" << endl << total << endl << d2 << endl << total - d2 << endl;
        }
    }
};
class Gold_plan:public Silver_plan{
    protected:
    int total;
    int d1;
    public:
    void display1(){
        total=1000+(voicecall*1);
        if(datalimit > 20){
            total+=2*(datalimit-20);
        }
        else if(text>200){
            total+=text-200;
        }
        if(total < 1000){
            d1=30*total/100;
            cout << "GOLD" << endl << total << endl << d1 << endl<< total -d1 << endl;
        }
        else if((total > 1000) && (total<2000)){
            d1=40*total/100;
            cout << "GOLD" << endl << total << endl << d1 << endl<< total -d1 << endl;
        }
        else{
            d1=5*total/100;
            cout << "GOLD" << endl << total << endl << d1 << total -d1 << endl;

        }
    }
};
class Diamond_plan:public Gold_plan{
    protected:
    int total2;
    int d;
    public:
    void display2(){
        total2=(0.5*voicecall)+2000;
        if(datalimit>50){
            total2+=(datalimit-50)*2;
        }
        if(text>500){
            total2+=text-500;
        }
        if(total2 < 1000){
            d=30*total2/100;
            cout << "DIAMOND" << endl << total2 << endl << d << endl<< total2 -d << endl;
        }
        else if((total2 > 1000) && (total2<2000)){
            d=40*total2/100;
            cout << "DIAMOND" << endl << total2 << endl << d << endl<< total2 -d<< endl;
        }
        else{
            d=5*total2/100;
            cout << "DIAMOND" << endl << total2 << endl << d <<endl<< total2 -d << endl;

        }
    }
};
int main(){
    Diamond_plan t1;
    t1.get();
    t1.display();
    t1.display1();
    t1.display2();
   
}