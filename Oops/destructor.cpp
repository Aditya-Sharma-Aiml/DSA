#include<bits/stdc++.h>
using namespace std;

class Customer{

    public:
    string name;
    int *data;

    // default constructor
    Customer(){
        cout << "default constructor called..." << endl;
        name = "aadi";
        // dynamic memory allocation
        data = new int ;
        *data = 10;
    }

    // Destructor -> delete the dynammic memory not the object because object will autometically destrooyed from stack when main funcn end
    ~Customer(){
        delete data;
        cout << "data deleted and destructor called!";
    }

};

int main(){

    Customer A1;

}