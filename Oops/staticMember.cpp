#include<bits/stdc++.h>
using namespace std;

// Note : 
// 1). 👉 Static member function sirf static data members ko direct access kar sakta hai
// 2). 👉 Non-static data member ko tab access kar sakta hai jab object diya ho
// 3). ➡️ Non-static function dono ko access kar sakta hai

// 4). static -> 👉 Ye class ka member hai , Sirf ek hi copy hoti hai aor share object shre krte hai
// 5). static -> class ke member hote toh this pointer nhi hota this pointre kewal object kee pass hota hai

class Customer{

    string name;
    int acc_no, balance;

    
    public:

    //static data member : member of class shared by each object (only one copy created)
    static int totalCustomer;
    static int totalBalance;

    Customer(string name, int acc_no, int balance){
        this->name = name;
        this->acc_no = acc_no;
        this-> balance = balance;

        totalCustomer++;
        totalBalance += balance;
    }

    void display() const{
        cout << "name: " << name << " acc_no : " << acc_no << " balance: " << balance << endl;
    }

    // static function kewal static data member ko hi access kr skta hai why?
    // ans -> static data/fuction class ke member hote hai isliye woh isi ko access kr skte hai

    // And normal attribute private hote hai aor class ke nhi object ke member hote hai isiliye unhe access nhi kr skta ye
    static void showTotal() {

        cout << "Total Customers: "<< totalCustomer << endl;
        cout << "Total balance: "<< totalBalance << endl;;
    }

    void deposit(const int amount){

        if(amount > 0 ){

            balance += amount;
            totalBalance += amount;
        }
        else{
            cout << "please enter valid amount for deposit!" <<endl;
        }
        
    }

    void withDraw(const int amount){

        if(amount >0 &&
             amount <= balance ){

                balance -= amount;
                totalBalance -= amount;
        }
        else{
            cout << "please enter valid amount to withdraw!" << endl;
        }
    }


};

// initialization of static data/function member
// datatype class_name scope resolution operator(::) attribute_name = initialization

int Customer :: totalCustomer = 0;
int Customer :: totalBalance = 0;

int main(){
    Customer A1("Aditya", 111, 10000);
    Customer A2("rahul", 222, 20000);
    Customer A3("Shimpi", 333, 30000);
    
    // A1.showTotalCustomers();
    
    // Customer ::  totalCustomer++;  // only when accessible by class when static member is public
    
    A1.deposit(8000);
    A2.deposit(1000);
    A3.withDraw(8000);

    A2.withDraw(80000);

    A1.display();
    A2.display();
    A3.display();

    Customer :: showTotal();
    
}