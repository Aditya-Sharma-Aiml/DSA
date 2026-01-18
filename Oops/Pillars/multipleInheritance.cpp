#include<bits/stdc++.h>
using namespace std;

// a class can innherit from more then two class

// parent-1
class Engineer{

    void who(){
        cout << "I am an unique Enginner.";
    }

    public:
    string specilization;

    //default constructor
    Engineer(){
        cout << "I am an Engineer default constructor." << endl;
    }
    //parameterised constructor
    Engineer(string specilization){

        cout << "I am a Engineer parameterised constructor." << endl;
        this->specilization = specilization;
    }

    void work(){
        cout << "I have specilization in " << specilization << endl;
    }

    //destructor
    ~Engineer(){
        cout << "I am an Engineer destructor." << endl;
    }

};

// Perent - 2
class YouTuber{

    public:
    int subscribers;

    //default constructor
    YouTuber(){
        cout << "I am a YouTuber default constructor." << endl;
    }
    //parameterised constructor
    YouTuber(int subscribers){

        cout << "I am a YouTuber parameterised constructor." << endl;
        this->subscribers = subscribers;
    }



    void subscriber(){
        cout << "I have a subscribers base of " << subscribers << endl;
    }

    //destructor
    ~YouTuber(){
        cout << "I am a YouTuber destructor." << endl;
    }

};

//child

// NOTE : 
// 1).yhn jis order me tum inherit kiye ho usi order me parent ka constructor call hoga 
// 2). destructor , constructor ke reverse order me call hota hai
class Teacher : protected YouTuber, public Engineer{

    public:
    string name;
    Teacher(){

        cout << "I am a Teacher default constructor." << endl;
    }
    
    Teacher(string name, string specilization, int subscribers ) : Engineer(specilization), YouTuber(subscribers){
        
        cout << "I am a Teacher parameterized constructor." << endl;
        this -> name = name;
        this -> specilization = specilization;
        this -> subscribers = subscribers;

    }

    void show(){
        cout << "All about me:" << endl;
        cout << "I am a teacher" << endl;
        work();
        subscriber();
        cout << "Thanks" << endl;

    }
    // destructor
    ~Teacher(){
        cout << "I am a Teacher destructor." << endl;
    }
};


int main(){
    Teacher T1;
    Teacher T2("Aditya", "Aiml", 1000);

    T2.show();
    // T1.who(); // not allowed
    

}

// OUTPUT:

    // I am a YouTuber default constructor.
    // I am an Engineer default constructor.
    // I am a Teacher default constructor.
    // I am a YouTuber parameterised constructor.
    // I am a Engineer parameterised constructor.
    // I am a Teacher parameterized constructor.
    // All about me:
    // I am a teacher
    // I have specilization in Aiml
    // I have a subscribers base of 1000
    // Thanks
    // I am a Teacher destructor.
    // I am an Engineer destructor.
    // I am a YouTuber destructor.
    // I am a Teacher destructor.
    // I am an Engineer destructor.
    // I am a YouTuber destructor.