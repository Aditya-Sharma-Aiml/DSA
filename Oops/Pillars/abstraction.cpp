
// 🔐 Encapsulation = HOW data is protected
// 1️⃣ Encapsulation kya hota hai?

// 👉 Data + methods ko ek class me band karna
// 👉 Direct access hide karke controlled access dena


// 🎭 Abstraction = WHAT user sees
// 2️⃣ Abstraction kya hota hai?

// 👉 Sirf important cheezein dikhana
// 👉 Implementation details chhupa dena

#include <bits/stdc++.h>
using namespace std;

/*
====================================
REAL WORLD EXAMPLE: ATM
====================================

ABSTRACTION:
- User ko sirf ye pata:
  deposit(), withdraw(), checkBalance()

ENCAPSULATION:
- balance private hai
- direct access allowed nahi
- rules methods ke andar lage hue hain
*/

class ATM {

private:    // 🔐 Encapsulation (data hiding)
    int balance;

public:
    // Constructor
    ATM() {
        balance = 10000;   // initial balance
    }

    // WHAT user can do (Abstraction)
    void deposit(int amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit Successful\n";
        } else {
            cout << "Invalid Deposit Amount\n";
        }
    }

    void withdraw(int amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdraw Successful\n";
        } else {
            cout << "Invalid Withdraw Amount\n";
        }
    }

    void checkBalance() {
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {

    ATM atm;   // User gets ATM access

    atm.deposit(5000);     // user only uses services
    atm.withdraw(2000);
    atm.checkBalance();

    // ❌ Not allowed (Encapsulation)
    // atm.balance = 100000;  // ERROR

    return 0;
}
