#include<bits/stdc++.h>
using namespace std;
/*
Tkke the age fromm user and then decide acccordingly 
1. If age < 18 :
    print -> not eligible for job 
2. If age >= 18 and age <= 54:
    print -> eligible for job 
3. If age >= 55 and age  <= 57 :
    print -> eligible for job but retirement soon.
4. If age > 57:
    print -> retirement time 
    */
int main(){
    int age;
    // cout<<"Enter your age: ";
    cin >> age;
    if (age < 18){
        cout << "not eligible for job.";

    }
    //>=18
    else if (age <= 57){
        cout << "elible for job";
        if (age >=55){
            cout << ", but retirement soon.";
        }
    }
    else{
        cout << "retirement time!";
    }
}