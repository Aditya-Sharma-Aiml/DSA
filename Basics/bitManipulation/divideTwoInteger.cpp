#include<bits/stdc++.h>
using namespace std;
int divideTwoInteger(int dividend, int divisor) {

	if(divisor==0) return INT_MAX;

    if(dividend==INT_MIN && divisor == -1) return INT_MAX;

    else if(dividend==INT_MIN && divisor == 1) return INT_MIN;

    int negative = 0;
    if((dividend<0 )^ (divisor<0)) negative=1;

    long long dvd = llabs((long long )dividend);
    long long dvr = llabs((long long )divisor);

    long long  quotient = 0;

    while (dvd >= dvr) {
        long long temp = dvr, multiple = 1;
        // Double the divisor until it exceeds the dividend
        while (dvd >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        dvd -= temp;
        quotient += multiple;
    }

    if(negative) return -quotient;

    return (int)quotient;

} 
int main(){
    int dvd;
    int dvr;
    cin>> dvd>>dvr;
    int quotient = divideTwoInteger(dvd,dvr);
    cout<< quotient;

}
