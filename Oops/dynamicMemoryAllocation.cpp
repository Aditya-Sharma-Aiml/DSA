#include<bits/stdc++.h>
using namespace std;

class Student{
    public:
    int age;
    int rollNo ;    
    string name;
};
int main(){
    // int *p = new  int;
    Student *s = new Student;

    (*s).name = "aadi";
    (*s).age = 20;

    s->rollNo = 12; 

    cout << s->name << endl;
    cout << s->age << endl;
    cout << (*s).rollNo << endl;

}