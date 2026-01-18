#include<bits/stdc++.h>
using namespace std;

// NOTE:
//     1). jb hum child class ke object banate hai toh PHLE PARENT CLASS KA CONSTRUCTOR CALL HOGA (TOP TO DOWN HIERARCHY)

//     2). jb hum child class ke object banate hai toh PHLE CHILD CLASS KA DESTRUCTOR CALL HOGA (BOTTOM TO UP HIERARCHY AND reverse of CONSTRUCTOR)

//     3). FUNCN EXIST IN SAME IN PARENT AND CHILD ALSO AND YOU MAKE THE THE CALL THROUGH CHILD OBJECT THEN YE OBJECT PHLE APNE CLASS ME CHECK KREGA TAGAR EXIST NHI KRTA TB HI PARENT ME JAYEGA 


class Person{

    protected:
    string name;
    int age;

    public:
    // Person(){
    //     cout << "Person ka constructor"<< endl;
    // }


    Person(string name, int age){

        cout << "Person ka constructor"<< endl;

        this -> name  = name;
        this -> age = age;
    }

    void display(){

        cout << "Person display" << endl;
        cout << "name : " << name<< " age : " << age << endl;
    }

    void working(){
        cout << "Person is working in child class also. " << endl;
    }

    ~Person(){
        cout << "Person ka Distructor" << endl;
    }

};

// child class Student which inherit the property of Person as a public 
class Student : public Person{

    int roll_no, fees;

    // phle Parent class ka constructor call hoga agar tum child ka object banate ho tb bhi kyun woh parent class ki property ko inherit kr rha hai (phle papa birth lenge tabhi toh bacha )
    public:
    // Student(string name, int age, int roll_no, int fees){

    //     cout << "Student ka constructor"<< endl;

    //     this -> name  = name;
    //     this -> age = age;        
    //     this -> roll_no = roll_no;        
    //     this -> fees = fees;        
    // }


    // manually calling the constructor of parent call -> ye phle jaake parent class ko call krega tb child me ghusega
    Student(string name, int age, int roll_no, int fees) : Person(name, age){

        cout << "Student ka constructor"<< endl;

        this -> roll_no = roll_no;        
        this -> fees = fees;        
    }

    void display(){

        cout << "Student display" << endl;
        cout << "name : " << name<< " age : " << age <<" roll_no : " << roll_no << " fees : " << fees << endl;
    }

    ~Student(){
        cout << "Student ka Distructor" << endl;
    }
};
int main(){

    Student S1("Aditya", 21, 12, 1500);

    // ye phle apne class me jis class ka object hai usme check krega display hai ya nhi tb jayega parent class me check krne  
    S1.display();

    // child class ke object se hum parent  class ke funcn ko call kr skte hai.
    S1.working();

}

// OUTPUT : 
//     Person ka constructor
//     Student ka constructor
//     Student display
//     name : Aditya age : 21 roll_no : 12 fees : 1500
//     Person is working in child class also.
//     Student ka Distructor
//     Person ka Distructor