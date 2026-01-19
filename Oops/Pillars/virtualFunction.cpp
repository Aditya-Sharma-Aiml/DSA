#include <bits/stdc++.h>
using namespace std;

class Animal{
    public:
    virtual void speak(){
        cout << "speaking.." << endl;
    }
};
class Dog : public Animal{
    public:
     void speak(){
        cout << "barking.." << endl;
    }
};
class Cat : public Animal{
    public:
     void speak(){
        cout << "meow.." << endl;
    }
};

int main(){
    
    // Animal *p; // pointer p animal type ki value to pint krega
    
    // p = new Dog(); // p ab Dog class ke object ko refer krega
    
    // p->speak(); //barking

    // parent class apne child class ke address ko store kr skta hai
    Animal *ptr;
    // parent class ka pointer isliye banate taki hum child class ke method ko call kr ske agar override ho gya ho toh
    vector<Animal*>animals;
    animals.push_back(new Dog());
    animals.push_back(new Cat());
    animals.push_back(new Animal());
    animals.push_back(new Cat());
    animals.push_back(new Dog());

    for (int i=0 ; i<animals.size() ; i++){

        ptr = animals[i];
        ptr->speak();
        cout << endl;
    }
}