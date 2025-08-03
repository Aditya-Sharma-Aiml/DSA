#include<bits/stdc++.h>
using namespace std;
// two non repeated element while others are twice
int findRightMostPosition(int data)
{
    int pos =0 ;
    while(data!=0)
    {
        if(data & 1) break;
        pos++;
        data = data >> 1;
    }
    return 1<< pos;
}
int generateMask(int arr[] ,int n)
{   
    int Xor = 0;
    for(int i=0 ; i<n ; i++){
        Xor ^= arr[i];
    }
    int pos = findRightMostPosition(Xor);
}
int findNonRepeatedElement(int arr[] , int n)
{
    // data divide into two group
    int g1 = 0 ,g2 = 0;
    int mask = generateMask(arr,n);
    
    for ( int i=0 ; i<n ; i++)
    {
        if (arr[i] & mask)
        {
            g1 ^= arr[i]; 
        }
        else{
            g2 ^= arr[i];
        }
    }
    cout << "non repeated element are " << g1 << " and " << g2;
}

int main(){
    int arr[] = {10,20,30,20,10,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    findNonRepeatedElement(arr,n);
}