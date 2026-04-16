#include<bits/stdc++.h>
using namespace std;

class Friend2;

class Friend1{

    int f1_var;

    public:

    Friend1(int value){
        f1_var = value;
    }
    friend class Friend2;
    void f1(Friend2 obj);
};

class Friend2{
    int f2_var;
    
    public:
    
    Friend2(int value){
        f2_var = value;
    }
    friend class Friend1;
    void f2(Friend1 obj);
};

void Friend1::f1(Friend2 obj){
    cout << obj.f2_var << endl;;
}

void Friend2::f2(Friend1 obj){
    cout << obj.f1_var;
}
int main(){
    Friend1 F1(100);
    Friend2 F2(999);

    F1.f1(F2);
    F2.f2(F1);


}