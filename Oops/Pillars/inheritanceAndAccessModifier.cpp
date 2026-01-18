
#include <bits/stdc++.h>
using namespace std;

class Person{

    private:
        string ADHAAR;
    protected:
        int id;
    public:
        string name;
        int age, ph_no;

};
class Student : protected Person{ 
    // protected (Person) -> Protected(Student)
    // public (Person) -> Protected(Student)
    // Private (Person) -> Not Accessible (Student)

    public:
        int rollNo;

    private:
        static int fees;

    public:
    Student(string name, int id, int rollNo, int age, int ph_no,int fees){
        this->name = name;
        this-> id = id;
        this-> rollNo = rollNo;
        this-> age = age;
        this -> ph_no = ph_no;
        this -> fees = fees;
    }

    void display(){
        cout << "name: " << name << endl;
        cout << "id: " << id << endl;
        cout << "rollNo: " << rollNo << endl;
        cout << "age: " << age << endl;
        cout << "ph_no: " << ph_no << endl;
        cout << "fees: " << fees << endl;

    }


};
class Teacher : protected Person{
    // protected (Person) -> Protected(Teacher)
    // public (Person) -> Protected(Teacher)
    // Private (Person) -> Not Accessible (Teacher)

    private:
        static int salary;
    
    public:
        Teacher(string name, int id, int age, int ph_no){
            this->name = name;
            this-> id = id;
            this-> age = age;
            this -> ph_no = ph_no;
        }
    void display(){
        cout << "name: " << name << endl;
        cout << "id: " << id << endl;
        cout << "age: " << age << endl;
        cout << "ph_no: " << ph_no << endl;
        cout << "salary: " << salary << endl;

    }
 
};

// initialization of static member
int Student :: fees = 155000;
int Teacher :: salary = 15000;

int main(){
    Student S1("Aditya", 1 , 12, 21, 788000000,2000);
    Person P1;

    // P1.id = "1"; // not accessible
    // P1.ADHAAR = "1332-4334-3445"; // not accessible

    // S1.age = 30;// direcg not accessible beacuse age student class me aake protected treat ho rha hai

    Teacher T1("Rahul", 2, 40, 912345678);

    // T1.ph_no = 4244354332;// inaccessible


    S1.display();
    T1.display();

}
