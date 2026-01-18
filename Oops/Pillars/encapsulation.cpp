#include<bits/stdc++.h>
using namespace std;


class Customer{

    private: // we have encapsulated our data -> give control access to user not direct

    string name;
    int acc_no, balance;

    // user ko direct access dena 
    // public:
    // string name;
    // int acc_no, balance;

    public:

    Customer(string name, int acc_no, int balance){
        this->name = name;
        this->acc_no = acc_no;
        this-> balance = balance;

    }

    void display() const{
        cout << "name: " << name << " acc_no : " << acc_no << " balance: " << balance << endl;
    }

   
    void deposit(const int amount){

        if(amount > 0 ){

            balance += amount;
            
        }
        else{
            cout << "please enter valid amount for deposit!" <<endl;
        }
        
    }

    void withDraw(const int amount){

        if(amount >0 &&
             amount <= balance ){

                balance -= amount;
                
        }
        else{
            cout << "please enter valid amount to withdraw!" << endl;
        }
    }


};

int main(){
    Customer A1("Aditya", 111, 10000);
    Customer A2("rahul", 222, 20000);
    Customer A3("Shimpi", 333, 30000);

    // A1.balance = -1000000; // agar user ko direct access denge to galat data bhej skta hai isiliye apne data ko wrap krke safe banate hai and user ko controlled access dete hai

    
    A2.deposit(-3000);
    A3.withDraw(-300);
    A1.deposit(200);
    
    A1.display();
    A2.display();
    A3.display();

    // output :

    // please enter valid amount for deposit!
    // please enter valid amount to withdraw!
    // name: Aditya acc_no : 111 balance: 10200
    // name: rahul acc_no : 222 balance: 20000
    // name: Shimpi acc_no : 333 balance: 30000
    
    
    
}