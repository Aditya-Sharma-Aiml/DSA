#include<bits/stdc++.h>
using namespace std;

class Complex{

    int real , img;
    public:
    Complex(){

    }

    Complex(int real, int img){
        this->real = real;
        this->img = img;
    }

    void display(){
        cout << real << " + i" << img<< endl;
    }
    //operator overloading : making + to add user defined datatype

    Complex operator+(Complex &C){

        Complex ans; // call the default constructor
        ans.real = real + C.real;
        ans.img = img + C.img;

        return ans;
    }
};
int main(){

    Complex C1(3,4);
    Complex C2(4,6);

    Complex C3 = C1 + C2 ; // c1 is calling to function "+" and c2 pass as an argument 

    C3.display(); //7 + i10

}