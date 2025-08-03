#include<bits/stdc++.h>
using namespace std;

// write a method to find out a non-repeated element froom an array while rest of element occurin twice.
int findNonRepeated(int arr[] , int n)
{
    int Xor =0; // non repeated element
    

    for(int i=0 ; i<n ; i++)
    {
        Xor^=arr[i];
    }
    return Xor;
}

int main()
{
    int arr[]={10,20,30,30,20,40,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int non_repeated_element = findNonRepeated(arr,n);
    cout << "non repeated element : "<< non_repeated_element;


}
