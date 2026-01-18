#include<bits/stdc++.h>
using namespace std;
// parent
class Person{

    protected:
    string name;

    public:

    // default constructor
    Person(){
        cout << "hey, i am a person." << endl;
    }

    void intriduce(){
        cout << "my name is : " << name << endl;
    }

};

// child
class Employee :public  Person{

    protected:
    int salary , id;

    public:
    // isko tum grand child ke object se bhi call krwa skte ho
    Employee(int salary , int id){

        this-> salary = salary;
        this -> id = id;
    }

    void tellMeSalary(){
        cout << "my salary is : $"<< salary << endl;
    }

};

// grandchild
class Manager : public Employee{

    
    public:
    string role;

    // calling Employee ka constructor then it will go first for Person and come back to Employee then last call for manager (top -> bottom)
    Manager(string name, int id, int salary, string role) : Employee(salary, id){
        this-> name = name;
        this->role = role;
    }

    void work(){
        cout <<"I am working as " << role<< endl;
    }

};


int main(){

    Manager M1("Aditya", 1, 200000, "SDE");

    M1.role = "senior-SDE";

    M1.intriduce();
    M1.tellMeSalary();
    M1.work();

}
//OUTPUT:
    // hey, i am a person.
    // my name is : Aditya
    // my salary is : $200000
    // I am working as senior-SDE