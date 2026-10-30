#include <iostream>
using namespace std;
class salesorder{
    protected:
    int no[5];
    char type[5][20];
    int date[5];
    char address[5][20];
    public:
    void get(){
        for(int i=0;i<5;i++){
            cin >> no[i] >> type[i] >> date[i] >> address[i];
        }
    }
};
class salesperson:public salesorder{
    protected:
    char name[20];
    int order[3];
    int count=0;
    int date1;
    public:
    void getdata(){
        cin >> name;
        for(int i=0;i<3;i++){
            cin >> order[i];
        }
        cin>>date1;
    }
    void compare(){
        int i=0;
        int count=0;
        while(i<3){
            for(int j=0;j<5;j++){
                if(no[j]==order[i]){
                    count++;
                }
            }
            i++;
        }
        if(count>0){
            cout << name << endl;
            for(int k=0;k<5;k++){
                if(date[k]==date1){
                    cout<<type[k]<<endl;
                }
            }
        }
        
    }
    
};
int main(){
    salesperson t2;
    t2.get();
    t2.getdata();
    t2.compare();

}
