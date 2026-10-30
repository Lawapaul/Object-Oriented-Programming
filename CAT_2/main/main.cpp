#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int universityID;

public:
    Person(string name, int universityID) : name(name), universityID(universityID) {}

    virtual void display() const {
        cout << "Name: " << name << endl;
        cout << "University ID: " << universityID << endl;
    }
};

class Faculty : public Person {
private:
    string rank;

public:
    Faculty(string name, int universityID, string rank) : Person(name, universityID), rank(rank) {}

    void display() const override {
        Person::display();
        cout << "Rank: " << rank << endl;
    }
};

class UndergraduateStudent : public Person {
private:
    int yearOfStudy;

public:
    UndergraduateStudent(string name, int universityID, int yearOfStudy) : Person(name, universityID), yearOfStudy(yearOfStudy) {}

    void display() const override {
        Person::display();
        cout << "Year of Study: " << yearOfStudy << endl;
    }
};

class GraduateStudent : public Person {
private:
    int supervisorUniversityID;

public:
    GraduateStudent(string name, int universityID, int supervisorUniversityID) : Person(name, universityID), supervisorUniversityID(supervisorUniversityID) {}

    void display() const override {
        Person::display();
        cout << "Supervisor's University ID: " << supervisorUniversityID << endl;
    }
};

int main() {
    Faculty faculty("John Doe", 12345, "Associate Professor");
    UndergraduateStudent undergrad("Alice Smith", 54321, 2);
    GraduateStudent grad("Bob Johnson", 98765, 12345);
    cout << "Faculty Information:" << endl;
    faculty.display();

    cout << "\nUndergraduate Student Information:" << endl;
    undergrad.display();

    cout << "\nGraduate Student Information:" << endl;
    grad.display();

    return 0;
}
