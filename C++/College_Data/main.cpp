#include <iostream>
using namespace std;

class person{
    public:
    char name[50];
    int age;
    char address[50];
    int count;
    void get(){
        cin >> name >> age >> address;
    }
    void display(){
        cout << name  << " " << age << "  " << address << endl;
    }
};
class faculty:public person{
    protected:
    char department[50];
    public:
    void get1(){
        cin >> department;
    }
    void display1(){
        cout << department << endl;
    }
};
class staff:public faculty{
    protected:
    char designation[50];
    public:
    void get2(){
        cin >> designation;
    }
    void display2(){
        cout << designation << endl;
    }
};
class student:public staff{
    protected:
    char field[50];
    int id;
    public:
    void get3(){
        cin >> field >> id;
    }
    void display3(){
        cout << field << " " << id << endl;
    }
};
int main(){
    int a,b;
    cin >> a;
    int arr[a];
    student s[a];
    int sum=0;
    for(int i=0;i<a;i++){
        s[i].get();
        cout << "1. Faculty - 1\n2. Staff - 2\n3. Student -3\nEnter Choice: ";
        cin >> b;
        if(b==1){
            s[i].get1();
            arr[i]=1;
        }
        else if(b==2){
            s[i].get2();
            arr[i]=2;
        }
        else{
            s[i].get3();
            arr[i]=3;
        }
    }
    cout << "\n";
    cout << "Faculty: "<< endl;
    for(int i=0;i<a;i++){
        if(arr[i]==1){
            s[i].display();
        }
    }
    cout << "Staff: "<< endl;
    for(int i=0;i<a;i++){
        if(arr[i]==2){
            s[i].display();
        }
    }
    cout << "Student: "<< endl;
    for(int i=0;i<a;i++){
        if(arr[i]==3){
            s[i].display();
        }
    }
    printf("\nSum of Ages: \n");
    for(int i=0;i<a;i++){
        sum+=s[i].age;
    }
    cout << sum;
  

    
   
}