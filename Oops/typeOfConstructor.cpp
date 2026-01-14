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

    // // parametrized constructor
    // Customer(string s, int a, int b){
    //     name = s;
    //     acc_no = a;
    //     balance = b;
    // }

    // // this pointer 
    // Customer(string name , int acc_no, int balance){

    //     this->name = name;
    //     this->acc_no = acc_no;
    //     this->balance = balance;
    // }

    // contructor overloading (same name diff parameter)
    Customer(string s, int a){
        name = s;
        acc_no = a;
        balance = 13724;
    }

    // inline constructor
    inline Customer (string s, int a, int b) : name(s) , acc_no(a), balance(b){

    }

    void display(){
        cout << name << " " << acc_no << " " << balance << endl;
    }

};

int main(){
   
    Customer A1;
    Customer A2("rahul",444,2000);
    Customer A3("ramu", 111);
    A1.display();
    A2.display();
    A3.display();
    

}