#include<bits/stdc++.h>
using namespace std;

class Customer{

    string name;
    int balance, acc_no;

    public:
    Customer(string name, int acc_no, int balance){

        this->name = name;
        this->acc_no = acc_no;
        this->balance = balance;
    }

    void deposite(int amount){

        if (amount <= 0) throw "Amount should be greater than 0"; // agar ye case fail hua toh aage code nhi chalega yahi se error throw kr jayega 
        balance += amount;

        cout << amount << " rs amount credited\n";

    }
    void withdraw(int amount){

        if(amount <0 )
            throw "Amount should be greater than 0"; // agar ye case fail hua toh aage code nhi chalega yahi se error throw kr jayega 

        if (amount > balance) 
            throw "balance is low";

        balance -= amount ;
        cout << amount << " rs amount debited\n";

    }


////
};
int main(){

    Customer C1("Aditya", 0, 111);

    try{
        C1.deposite(500);
        C1.withdraw(1000);  // ye ek error throw krga 
    
        C1.deposite(1000); // ye code nhi chalega kyunki iskke uper wale ne error throw kiya hai  jo ki abb direct uss error ko catch handle karega

    }
    catch(const char* error){

        cout << "Exception Occured : " << error << endl;
    }


}