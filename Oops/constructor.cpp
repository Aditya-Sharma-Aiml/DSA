#include<bits/stdc++.h>
using namespace std;

class Customer{

    public:

    int balance = 0;
    int age;
    int rollNo ;    
    string name;

    Customer(int age, int rollNo, string name){
        this -> name = name;
        this -> age = age;
        this -> rollNo = rollNo;
    }
    void set(int amount){
        this->balance += amount;
    }
    void display(){
        cout << this;
    }

};

int main(){
    Customer s1(23, 12,"aadi");
    Customer s2(20, 21,"rahul");

    s2.name = "sharma";
    cout << "address of s2: "; 
    s2.display();
    
    cout << endl;
    cout << "address of s1: "; 
    s1.display();
    cout << endl;
    

    s1.set(1000);
    cout << s2.balance << endl;
    cout << s1.balance;



}