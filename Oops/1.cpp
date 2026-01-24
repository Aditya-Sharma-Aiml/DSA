#include<bits/stdc++.h>
using namespace std;

class Hello{

    public :
    string name;

    Hello(string name){
        this->name = name;
    }
};

Hello* sayHello(string name){

    Hello* greet = new Hello(name);
    return greet;
}
int main(){
    string name;
    cin >> name;
    Hello* say = sayHello(name);
    cout <<"Hello "<<  say->name;

}