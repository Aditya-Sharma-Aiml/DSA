#include<bits/stdc++.h>
using namespace std;
int main(){

    int i=3;
    int *ptr = &i;

    (*ptr)++; // value of i++

    cout<< "before : " << *ptr << endl; //4
    cout<< "before : " << ptr << endl; // address of i

    ptr++; // moves to 4 byte forward 

    cout<< "After : " << ptr << endl; // addresss of i + 4 byte 
    cout<< "After : " << *ptr << endl; // 4 nhi aayegi garbage value aayega 

    int firstvalue = 5, secondvalue = 15;
    char thirdvalue = 'a';
    
    int *p1 = & firstvalue; // p1 = address of firstvalue
    int *p2 = & secondvalue; // p2 = address of secondvalue 
    char *p3 = & thirdvalue; // p3 = address of thirdvalue
    *p1 = 10; // value pointed to by p1 = 10
    *p2 = *p1; // value pointed to by p2 = value pointed to by p1
    cout<< *p2 << " " << *p1 << endl;
    p1 = p2; // p1 = p2 (value of pointer is copied)
    cout<< p2 << " " << p1 << endl;
    * p1 = 20; // value pointed to by p1 = 20
    * p3 = 'b'; // value pointed to by p3 = ‘b ’
    cout << "firstvalue is " << firstvalue << endl;
    cout << "secondvalue is " << secondvalue << endl;
    cout << "thirdvalue is " << thirdvalue << endl;
    

    int arr[10]={2,8,5};
    cout << arr << endl; 
    cout<< arr+1 << endl;

    int j =2;
    cout << arr[j] << " = "  << *(arr+j) << endl;
    cout << j[arr] << " = "  << *(j+arr) << endl; // no error

}