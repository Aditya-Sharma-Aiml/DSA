#include<bits/stdc++.h>
using namespace std;

class Customer{
    string name;
    
    public:
    Customer(){
        name  = "4";
        cout << "constructor is " << name << endl;
    }
    Customer(string name){
        this-> name = name;
        cout << "constructor is " << name << endl;
        
    }
    ~Customer(){   
        cout << "Destructor is " << name << endl;

    }


};

int main(){
    
    Customer A1("1"), A2("2"), A3("3");
    // dynamic 
    Customer *A4 = new Customer;
    // jb tk hum free nhi krenge iske resourse free nhi honge destructor ka kaam hai free krna 
    delete A4;


}
// constructor -> same order
// destructor rebverse order me call hota hai due to stack follow LIFO and also to safe dependecies -> 

// constructor is 1
// constructor is 2
// constructor is 3
// constructor is 4
// Destructor is 4
// Destructor is 3
// Destructor is 2
// Destructor is 1