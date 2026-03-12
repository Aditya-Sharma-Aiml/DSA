#include<bits/stdc++.h>
using namespace std;

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

    // declaration of the friend function:
    
    // We can declare friend function or function anywhere in the base class body whether its private, protected or public block. It works all the same.
    friend void globalFriendFunction(base &obj);
};

void globalFriendFunction(base &obj){

    obj.private_var *= 1000;
    obj.protected_var *= 1000;
    obj.public_var *= 1000;

    cout << "private: " << obj.private_var << endl;
    cout << "protected: " << obj.protected_var << endl;
    cout << "public: " << obj.public_var << endl;
}
int main(){

    base b(1,2,3);

    globalFriendFunction(b);

}