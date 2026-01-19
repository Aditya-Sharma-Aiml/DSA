#include<bits/stdc++.h>
using namespace std;

// Runtime Polymorphism : 

// RULE of method overriding:
//                         1). same function name 
//                         2). same number of partameter
//                         3). Inheritance must
class Animal{

    public:
    void speak(){
        cout << "Animal speaking..." << endl;
    }
};
class Dog : public Animal{

    public:
    void speak(){
        cout << "Dog barking..." << endl;
    }
};

int main(){
    
    Dog d;
    d.speak(); // phle apne object me check krta hai agar function nhi  hota tb parent me jata uss fuction ke passs 

}