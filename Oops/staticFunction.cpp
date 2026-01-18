#include<bits/stdc++.h>
using namespace std;

class Test {
public:
    static void show();
};

void Test::show() {
    cout << "Static function\n";
}

int main() {
    Test::show();   //correct use of ::
}

