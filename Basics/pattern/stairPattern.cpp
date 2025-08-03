#include<bits/stdc++.h>
using namespace std;
/*
*
**
***
   *
   **
   ***
      *
      ** 
      ***
*/
void stairPattern(int n)
{
    for(int block=0 ; block<n ; block++)
    {
        for(int i=0 ; i<n ; i++)
        {
            for(int space = 0 ; space < block*n ; space++)
            {
                cout <<" ";

            }
            for(int j=0 ; j<=i ; j++)
            {
                cout << "*";
            }
        cout << endl;    
        }
        
    }
}
int main(){
    int n;
    cout<< "enter n: ";
    cin >> n;
    stairPattern(n);

}