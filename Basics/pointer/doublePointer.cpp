#include<bits/stdc++.h>
using namespace std;
int update(int **p2){

    // p2=p2+1;
    // kuchh change hoga ?? - NO

    //*p2 = *p2 + 1;
    // kuchh change hoga ?? - YES : p apne address ke 4 byte aage wale ko point krega (ex 0xabdc1a-0xabdc1e)


    **p2 = **p2 + 1;
    // kuchh change hoga ?? - YES : i=i+1; => i=6
}
int main(){

    int i = 5;
    int *p = &i;
    int* *p2 = &p;

    cout << endl << endl;

    cout<< "before - i: "  << i << endl;
    cout<< "before - p: "  << p << endl;
    cout<< "before - p2: "  << p2 << endl;

    update(p2);

    cout<< "after - i: "  << i << endl;
    cout<< "after - p: "  << p << endl;
    cout<< "after - p2: "  << p2 << endl;


    

}