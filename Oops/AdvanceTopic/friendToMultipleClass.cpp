#include<bits/stdc++.h>
using namespace std;

//forward declaration
class Alok;
class Aditya;
class Ayush;

class Alok{

    double cgpa;

    public:
    Alok(double data){
        cgpa = data;
    }

    friend void max(Alok &A1, Aditya &A2, Ayush &A3);
    
};
class Aditya{
    double cgpa;

    public:
    Aditya(double data){
        cgpa = data;
    }
    
    friend void max(Alok &A1, Aditya &A2, Ayush &A3);
};
class Ayush{
    double cgpa;

    public:
    Ayush(double data){
        cgpa = data;
    }
    
    friend void max(Alok &A1, Aditya &A2, Ayush &A3);
};

void max(Alok &A1, Aditya &A2, Ayush &A3){

    double result = max(A1.cgpa , max(A2.cgpa, A3.cgpa));
    cout <<"result: " << result;
}
int main(){
    Alok A1(5.6);
    Aditya A2(9.5);
    Ayush A3(8.7);

    max(A1,A2, A3);
}