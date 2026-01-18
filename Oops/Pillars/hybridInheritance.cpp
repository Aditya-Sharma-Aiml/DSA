#include<bits/stdc++.h>
using namespace std;

// Independent base class
class Student {
    protected:
        int roll;

    public:
        Student(int roll) {
            this->roll = roll;
        }
};

// Independent class
class Male {
    protected:
        string beard;
        
    public:
        Male(string beard) {
            this->beard = beard;
        }
};

// Independent class
class Female {
    protected:
        string hair;

    public:
        Female(string hair) {
            this->hair = hair;
        }
};

// Boy inherits Student + Male
class Boy : public Student, public Male {

    public:
        Boy(int roll, string beard)
            : Student(roll), Male(beard) {}

        void display() {
            cout << "Boy Details\n";
            cout << "Roll : " << roll << endl;
            cout << "Beard : " << beard << endl;
        }
};

// Girl inherits Student + Female
class Girl : public Student, public Female {
    public:
        Girl(int roll, string hair)
            : Student(roll), Female(hair) {}

        void display() {
            cout << "Girl Details\n";
            cout << "Roll : " << roll << endl;
            cout << "Hair : " << hair << endl;
        }
};

int main() {

    Boy b(101, "Yes");
    Girl g(102, "Long");

    b.display();
    cout << endl;
    g.display();

    return 0;
}
// OUTPUT:
//     Boy Details
//     Roll : 101
//     Beard : Yes

//     Girl Details
//     Roll : 102
//     Hair : Long