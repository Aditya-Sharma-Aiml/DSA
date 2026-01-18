#include<bits/stdc++.h>
using namespace std;

    //                Person
    //     ------------------------------
    //     |             |              |
    //  Student        Faculty         Staff

class Person {

    protected:
        string name;
        int age;

    public:
        Person(string name, int age) {
            this->name = name;
            this->age = age;
        }

        void display() {
            cout << "Person display" << endl;
            cout << "name : " << name << " age : " << age << endl;
        }
};

// ---------------- Student ----------------
class Student : public Person {

    int roll_no, fees;

public:
    Student(string name, int age, int roll_no, int fees)
        : Person(name, age) {

        this->roll_no = roll_no;
        this->fees = fees;
    }

    void display() {
        cout << "Student display" << endl;
        cout << "name : " << name
             << " age : " << age
             << " roll_no : " << roll_no
             << " fees : " << fees << endl;
    }
};

// ---------------- Faculty ----------------
class Faculty : public Person {

protected:
    int id;
    string department;

public:
    Faculty(string name, int age, int id, string department)
        : Person(name, age) {

        this->id = id;
        this->department = department;
    }

    void display() {
        cout << "Faculty display" << endl;
        cout << "name : " << name
             << " age : " << age
             << " id : " << id
             << " department : " << department << endl;
    }
};

// ---------------- Staff ----------------
class Staff : public Person {

public:
    string designation;

    Staff(string name, int age, string designation)
        : Person(name, age) {

        this->designation = designation;
    }

    void display() {
        cout << "Staff display" << endl;
        cout << "name : " << name
             << " age : " << age
             << " designation : " << designation << endl;
    }
};

// ---------------- main ----------------
int main() {

    Student s("Aditya", 21, 101, 40000);
    Faculty f("Dr Sharma", 45, 501, "CSE");
    Staff st("Ramesh", 38, "Clerk");

    s.display();
    cout << endl;

    f.display();
    cout << endl;

    st.display();

}

// OUTPUT:
    // Student display
    // name : Aditya age : 21 roll_no : 101 fees : 40000

    // Faculty display
    // name : Dr Sharma age : 45 id : 501 department : CSE

    // Staff display
    // name : Ramesh age : 38 designation : Clerk
