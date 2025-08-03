#include<bits/stdc++.h>
using namespace std;

//(i) 1-> set bit 
//(ii) 0 -> clear bit 
//(iii) mask 

int oddEven(int n)
{
    if(n&1) cout << "odd" << endl;
    else cout << "even" << endl;
}

//check bit is set or clear at any position 

int checkBit(int data , int pos)
{
    //int mask = 1<< pos;
    if (data & 1<<pos) cout<<"set bit" << endl; 
    else cout << "clear bit" << endl;
}

// count the number of set bit in given data
int countSetBit(int data)
{
    int count = 0;
    while(data != 0)
    {
        if(data & 1) count++;
        data = data >> 1;  // ✅ Move outside if
    }
    return count;
}


// find positons of set bit

int findPositionOfSetBit(int data)
{
    int pos = 0;
    cout << "setbit positions : ";
    while(data!=0)
    {
        if (data & 1) cout << pos << ",";
        pos++;
        data = data >> 1;
    }
    cout <<endl;
    
}
// change status of bit (flip the bit)
int changeBitStatus(int data , int pos)
{

    cout << "data " << data << " : before changed bit status at pos " << pos << endl;

    int mask = 1 << pos;
    data = data ^ mask;

    cout << "data " << data << " : after changed bit status at pos " << pos << endl;
}

// check given data is power of two or not
int isPowerOfTwo(int data)
{
    int count = countSetBit(data);
    if(count == 1 ) cout << data << " is in power of 2" << endl;
    else cout << data << " is not in power of 2" << endl;
}
int main()
{   oddEven(10);
    checkBit(10,2);
    findPositionOfSetBit(11);
    changeBitStatus(11,2);
    isPowerOfTwo(0);
    int count_set_bit = countSetBit(11);
    cout << "count_set_bit : " << count_set_bit;

}

