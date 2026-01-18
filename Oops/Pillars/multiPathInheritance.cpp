#include<bits/stdc++.h>
using namespace std;

class Person {

    protected:
        string name;
        int age;

    public:
        Person() {
            // Default constructor
            cout << "Person" << endl;
        }

        void display() {
            cout << "name : " << name << " age : " << age << endl;
        }
};

/*
  Engineer class Person ko VIRTUAL inherit kar rahi hai.

  Reason:
  Teacher class Engineer aur YouTuber dono se inherit karti hai,
  aur Engineer + YouTuber dono hi Person se inherit karte hain.

  Agar virtual use na karein to:
  -> Teacher ke paas Person ke 2 copies ban jaayengi
  -> Diamond Problem create ho jaata hai

  virtual ensure karta hai ki:
  -> Teacher class me Person ka sirf EK hi object ho
*/
class Engineer : public virtual Person {

    public:
        string specilization;

        Engineer(string specilization) {
            cout << "Engineer" << endl;
            this->specilization = specilization;
        }

        void work() {
            cout << "I have specilization in " << specilization << endl;
        }
};

/*
  YouTuber bhi Person ko VIRTUAL inherit kar rahi hai
  taaki Teacher class me Person ka duplicate object na bane
*/
class YouTuber : public virtual Person {

    public:
        int subscribers;

        YouTuber(int subscribers) {
            cout << "Youtuber" << endl;
            this->subscribers = subscribers;
        }

        void subscriber() {
            cout << "I have a subscribers base of " << subscribers << endl;
        }
};

/*
  Teacher class:
  - Engineer aur YouTuber dono se inherit kar rahi hai (Multiple inheritance)
  - Person ka data directly use kar pa rahi hai
    kyunki virtual inheritance se Person ka sirf ek object bana hai
*/
class Teacher : protected YouTuber, public Engineer {
    // constructor : Person -> YouTuber -> Engineer -> Teacher : (because vitual base class sabse phle fir class inheritance order mentioned ke hisab se jese yhn inherit hua hai )

    public:
        Teacher(string name, int age, string specilization, int subscribers)
            : Engineer(specilization), YouTuber(subscribers) {
                
            cout << "Teacher" << endl;
            // Person ka single (shared) object yahin initialize ho raha hai
            this->name = name;
            this->age = age;
        }

        void show() {
            cout << "All about me:" << endl;
            cout << "I am a teacher" << endl;

            display();     // Person ka function
            work();        // Engineer ka function
            subscriber();  // YouTuber ka function

            cout << "Thanks" << endl;
        }
};

int main() {

    Teacher T1("Aditya", 21, "AIML", 2000);
    T1.show();

}
// OUTPUT:
    // Person
    // Youtuber
    // Engineer
    // Teacher
    // All about me:
    // I am a teacher
    // name : Aditya age : 21
    // I have specilization in AIML
    // I have a subscribers base of 2000
    // Thanks