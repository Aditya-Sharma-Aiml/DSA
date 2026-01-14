#include<bits/stdc++.h>
using namespace std;

class Customer{

    public:
    string name;
    int acc_no;
    int balance;

    // default constructor
    Customer(){
        cout << "default constructor called..." << endl;
        name = "aadi";
        acc_no = 123;
        balance = 0;
    }


    // this pointer 
    Customer(string name , int acc_no, int balance){

        this->name = name;
        this->acc_no = acc_no;
        this->balance = balance;
    }

    Customer(Customer &copyConstructor){

        cout << "copy constructor : " <<endl;

        name = copyConstructor.name;
        acc_no = copyConstructor.acc_no;
        balance = copyConstructor.balance;
    }


    void display(){
        cout << name << " " << acc_no << " " << balance << endl;
    }

};

int main(){
   
    Customer A1;
    Customer A2("rahul",444,2000);
    A1.display();
    A2.display();

    // // default copy contructor
    // Customer A3(A2);
    // A3.display();

    // Customer A4;
    // A4 = A1;
    // A4.display();

    // custom constructor
    Customer exist ("Aditya", 111, 1000000);
    Customer custom (exist);
    custom.display();


    

}