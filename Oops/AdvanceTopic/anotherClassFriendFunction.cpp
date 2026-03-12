#include<bits/stdc++.h>
using namespace std;

// Forward declaration of the class is needed if we want to make a member function of another class a friend inside that class.

// forward declaration 
class base;

// Note: The order in which we define the friend function of another class is important and should be taken care of. We always have to define both the classes before the function definition. Thats why we have used out of class member function definition.

class Dost{

    public:
        void friend_Function(base &obj);
};

class base{
     
    private:
        int private_var;
    protected:
        int protected_var;
    public:
        int public_var;

    base(int x, int y, int z){

        private_var = x;
        protected_var = y;
        public_var = z;

    }
    friend void Dost::friend_Function(base &obj);

};



void  Dost::friend_Function(base &obj){

    obj.private_var *= 1000;
    obj.protected_var *= 1000;
    obj.public_var *= 1000;

    cout << "private: " << obj.private_var << endl;
    cout << "protected: " << obj.protected_var << endl;
    cout << "public: " << obj.public_var << endl;
}

int main(){

    base b(1,2,3);
    Dost d;

    d.friend_Function(b);

}