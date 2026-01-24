#include<bits/stdc++.h>
using namespace std;

struct Node1{
    int data;
    Node1* next;

    // constructor
    Node1(int val){
        data = val;
        next  = NULL;
    }

};
struct Node2{
    int data;
    Node2* next;

    // constructor
    Node2(int data){
        this->data = data;
        this->next  = nullptr;
    }

};
struct Node3{
    int data;
    Node3* next;

    // constructor
    Node3(int data, Node3* next){
        this->data = data;
        this->next  = nullptr;
    }

};
struct Node4{
    int data;
    Node4* next;

    // constructor
    Node4(int val, Node4* next){
        data = val;
        next  = nullptr;
    }

};
// diff b/w class and struct : in struct bu default all things are public but in class that is not true by default all are private 

class Node{

    public:

    int data;
    Node* next;

    // constructor
    Node(int data){
        this->data = data;
        next = nullptr;
    }
    // // constructor
    // Node(int val){
    //     val = data;
    //     next = nullptr;
    // }
};

int main(){

    Node1 x = Node1(10); // creating object only in stack
    Node1* y = &x; // y joh x ki memory location ko point kr rha hai
    cout << y->data << endl;
    cout << y->next << endl;

    vector<int>arr = {1,2,3,4,5,6};
    Node3* newNode3 = new Node3(arr[0], nullptr);

    Node2* newNode2 = new Node2(arr[1]);


    // for class
    Node* head = new Node(arr[2]); // dynamic 
    cout << head->data << endl;
    cout << head->next << endl;


}