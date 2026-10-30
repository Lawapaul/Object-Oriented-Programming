#include <iostream>
using namespace std;

class yoga{
    protected:
    int duration;
    public:
    void get(){
        cin >> duration;
    }
};
class exercise:public yoga{
    protected:
    char type[50];
    int time;
    public:
    void get1(){
        cin >> type >> time;
    }
    void healthreport(){
        if (time>30 && type=="running" && duration>=15){
            cout << "Fitness is good" << endl;
        }
        else if((time<=30 && time>10)&& type=="running" && (duration<15 && duration >=10)){
            cout << "Fitness is average" << endl;
        }
        else{
            cout << "Fitness is bad" << endl;
        }
    }
};
class Meditation:public exercise{
    protected:
    int md;
    public:
    void get2(){
        cin >> md;
    }
    void check(){
        if((duration>=15) && (md>=2 && md<=3)){
            cout << "Nature of Meditation is Good" << endl;
        }
        else if((duration<15 && duration >=7)&&(md<2 && md>=1)){
            cout << "Nature of Meditation is Average" << endl;
        }
        else{
            cout << "Nature of Meditation is bad" << endl;;
        }
    }
};
int main(){
    int a;
    cin >> a;
    Meditation m1[a];
    for(int i=0;i<a;i++){   
        m1[i].get();
        m1[i].get1();
        m1[i].get2();
    }
    cout << endl;
    for(int i=0;i<a;i++){
        m1[i].healthreport();
        m1[i].check();
    }
}
