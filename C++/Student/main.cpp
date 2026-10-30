#include <iostream>
using namespace std;

class student{
    private:
    char name[50];
    int marks;
    public:
    int rollno;
    void get(){
        cin >> name >> marks >> rollno;
    }
    void display(){
        cout << name << " " << marks << " " << rollno << endl;
    }
};
int main(){
    student s1,s2,s3,*ptr,*ptr1,*ptr2;
    ptr=&s1;
    ptr1=&s2;
    ptr2=&s3;
    ptr->get();
    ptr1->get();
    ptr2->get();
    ptr->display();
    ptr1->display();
    ptr2->display();
}