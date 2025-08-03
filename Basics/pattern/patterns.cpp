#include<bits/stdc++.h>
using namespace std;

void pattern1(int n){
    cout<< "pattern1" << endl;
    for ( int i=0 ; i<n ;i++){
        for (int j=0 ; j<n ; j++){
            cout << "* ";
        }
        cout <<endl;
    }
}
void pattern2(int n){
    cout<< "pattern2" << endl;
    for ( int i=0 ; i<n ;i++){
        for (int j=0 ; j<=i ; j++){
            cout << "* ";
        }
        cout <<endl;
    }
}
void pattern3(int n){
    cout<< "pattern3" << endl;
    for ( int i=0 ; i<=n ;i++){
        for (int j=1 ; j<=i ; j++){
            cout << j << " ";
        }
        cout <<endl;
    }
}
void pattern4(int n){
    cout<< "pattern4" << endl;
    for ( int i=0 ; i<=n ;i++){
        for (int j=1 ; j<=i ; j++){
            cout << i << " ";
        }
        cout <<endl;
    }
}
void pattern5(int n){
    cout<< "pattern5" << endl;
    for ( int i=0 ; i<=n ;i++){
        for (int j=1 ; j<=n-i ; j++){
            cout << "* ";
        }
        cout <<endl;
    }
}
void pattern6(int n){
    cout<< "pattern6" << endl;
    for ( int i=0 ; i<n ;i++){
        for (int j=1 ; j<=n-i ; j++){
            cout << j<<" ";
        }
        cout <<endl;
    }
}
void pattern7(int n){
    cout<< "pattern7" << endl;
    for ( int i=0 ; i<n ;i++){
        for (int j=1 ; j<n-i ; j++){
            cout << " ";
        }
        for(int j=0 ; j<2*i+1 ; j++){
            cout <<"*";
        }
        for (int j=1 ; j<n-i ; j++){
            cout << " ";
        }
        cout <<endl;
    }
}
void pattern8(int n){
    cout<< "pattern8" << endl;
    for ( int i=0 ; i<n ;i++){
        for (int j=0 ; j<i ; j++){
            cout << " ";
        }
        for(int j=0 ; j<2*n-(2*i+1) ; j++){
            cout <<"*";
        }
        for (int j=0 ; j<i ; j++){
            cout << " ";
        }
        cout <<endl;
    }
}
void pattern9(int n){
    cout<< "pattern9" << endl;
    for ( int i=0 ; i<n-1 ;i++){
        for (int j=0 ; j<n-i-1 ; j++){
            cout << " ";
        }
        for(int j=0 ; j<2*i+1 ; j++){
            cout <<"*";
        }
        for (int j=0 ; j<n-i-1 ; j++){
            cout << " ";
        }
        cout <<endl;
    }
    for ( int i=0 ; i<n ;i++){
        for (int j=0 ; j<i ; j++){
            cout << " ";
        }
        for(int j=0 ; j<2*n-(2*i+1) ; j++){
            cout <<"*";
        }
        for (int j=0 ; j<i ; j++){
            cout << " ";
        }
        cout <<endl;
    }
}
void pattern10(int n){
    cout<< "pattern10" << endl;
     for (int i = 1; i <= (2 * n - 1); i++) {
        int stars = i;
        if (i > n)
            stars = (2 * n - i);
        
        for (int j = 0; j < stars; j++) {
            cout << "*";
        }
        cout << endl;
    }
    
}
void pattern11(int n){
    cout<< "pattern11" << endl;
    int start=1;

    for (int i=0 ; i<n ; i++){
        
        if (i%2==0) start = 1;
        else start =0;

        for (int j=0 ; j<=i; j++){
            cout << start;
            start = 1 - start; // flip  (1->0 and 0->1)
        } 
    cout << endl;
    }
}
void pattern12(int n){
    cout<< "pattern12" << endl;
    for (int i=1 ; i<=n ; i++ ){
        //num
        // int space  = 2*(n-1);
        for (int j=1 ; j<=i ; j++){
            cout << j;
        }
        //space
        for (int j=1 ; j<=2*(n-i) ; j++){ 
            cout << " ";
        }
        //num
        for (int j=i ; j>=1 ; j--){
            cout << j;
        }
        cout << endl;
        // space-=2;
    }
    
}
void pattern13(int n){
    cout<< "pattern13" << endl;
    int num = 1;
    for (int i=1 ; i<=n ; i++ ){
        
        for (int j=1 ; j<=i ; j++){
            cout <<num << " ";
            num++;
            
        }
        
        cout <<endl;
    }
    
}
void pattern14(int n){
    cout<< "pattern14" << endl;
    for (int i=0 ; i<n ; i++){
        
        for (char ch ='A'; ch <='A'+i ; ch++ ){
            cout << ch << " ";
        
        }
        
        cout <<endl;
    }
    
}
void pattern15(int n){
    cout<< "pattern15" << endl;
    for (int i=0 ; i<n ; i++){
        char ch = 'A';
        for(int j = n ; j>i ; j--){
            cout << ch++ << " ";
        }    
    cout << endl;
    }
}
void pattern16(int n){
    cout<< "pattern16" << endl;
    char ch = 'A';
    for (int i=0 ; i<n ; i++){
        for(int j = 0 ; j<=i ; j++){
            cout << ch << " ";
        } 
        ch++;   
    cout << endl;
    }
}
void pattern17(int n){
    cout<< "pattern17" << endl;
    for ( int i=0 ; i<n ;i++){
        //space
        
        for (int j=1 ; j<n-i ; j++){
            cout << " ";
        }

        //character
        char ch = 'A';
        int breakpoint = (2*i+1)/2;
        for(int j=1 ; j<=2*i+1 ; j++){
            cout << ch;
            if(j<=breakpoint)  ch++;
            else  ch--;
        }

        // space
        for (int j=1 ; j<n-i ; j++){
            cout << " ";
        }
        cout <<endl;
    }
}
void pattern18(int n){

    cout<< "pattern18" << endl;
    for (int i=0 ; i<n ; i++){
        char ch ='A'+n-1;
        for (char j = ch-i ; j<=ch ; j++){
            cout << j << " ";      
        } 
        cout <<endl;
        
    }
    
}
void pattern18_(int n){
    cout<< "pattern18_" << endl;
    for (int i=0 ; i<n ; i++){
        char ch ='A'+n-1;
        for (char j = ch ; j>=ch-i ; j--){
            cout << j << " ";      
        } 
        cout <<endl;
        
    }
    
}
void pattern19(int n){

    cout<< "pattern19" << endl;
int space = 0;

    // Upper half
    for (int i = 0; i < n; i++) {
        int stars = n - i;

        // Left stars
        for (int j = 0; j < stars; j++) cout << "*";

        // Spaces
        for (int j = 0; j < space; j++) cout << " ";

        // Right stars
        for (int j = 0; j < stars; j++) cout << "*";

        cout << endl;
        space += 2;
    }

    space -= 2;

    // Lower half
    for (int i = 0; i < n; i++) {
        int stars = i + 1;

        // Left stars
        for (int j = 0; j < stars; j++) cout << "*";

        // Spaces
        for (int j = 0; j < space; j++) cout << " ";

        // Right stars
        for (int j = 0; j < stars; j++) cout << "*";

        cout << endl;
        space -= 2;
    }
}
void pattern20(int n){
    cout<< "pattern20" << endl;
    int space = 2*(n-1);
    for (int i = 1; i <= 2 * n - 1; i++) {
        int stars = i;
        if (i > n)
            stars = 2 * n - i ;
        //star
        for (int j = 1; j <=stars; j++) {
            cout << "*";
        }
        //space
        for(int j =1 ; j<=space ; j++ ){
            cout << " ";
        }
        //star
        for (int j = 1; j <= stars; j++) {
            cout << "*";
        }

        cout << endl;
        if(i<n) space-=2;
        else space+=2;
    }
}
void pattern21(int n){
    cout<< "pattern21" << endl;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if (i==0 || i==n-1 || j==0 || j==n-1){
                cout<< "*";
            }
            else cout <<" ";
        }
        cout<<endl;
    }
}
void pattern22(int n){
    cout<< "pattern22" << endl;
    for(int i=0 ; i<2*n-1 ; i++){
        for(int j=0 ; j<2*n-1 ; j++){

            int top = i;
            int left = j;
            int right = 2*n-2-j;
            int down = 2*n-2-i;

            int x = (n-min(min(top,down), min(left,right)));
            cout << x<< " ";

        }
        cout <<endl;
    }
}
void pattern22_(int n){
    cout<< "pattern22_" << endl;
    //uper part
    for(int i = n ; i>1 ; i--){
        // space  : number
        for(int space=1 ; space<=n-i ; space++){
            cout <<n-space+1<< " "; // left triangle
        }
        for (int j=1 ; j<=2*i-1 ; j++){
            cout<<i << " "; // uper diamond
        }
        for(int space=1; space<=n-i ; space++){
            cout <<space+i<< " "; //right triangle
        }
        cout << endl;
    }

    //lower part 
    for(int i = 1 ; i<=n ; i++){
        // space  : number
        for(int space=1 ; space<=n-i ; space++){
            cout <<n-space+1<< " "; // left triangle
        }
        for (int j=1 ; j<=2*i-1 ; j++){
            cout<<i << " "; // uper diamond
        }
        for(int space=1 ; space<=n-i ; space++){
            cout <<space+i<< " "; //right triangle
        }
        cout << endl;
    }
    
}

void rightArrowStarPattern(int n) {
    cout<< "rightArrowStarPattern" << endl;
    // Upper part
    for (int i = 0; i < n; i++) {
        // Spaces
        for (int space = 0; space < i; space++) {
            cout << "  ";
        }
        // Stars
        for (int j = 0; j < n - i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    // Lower part
    for (int i = 1; i < n; i++) {
        // Spaces
        for (int space = 0; space < n - i - 1; space++) {
            cout << "  ";
        }
        // Stars
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void leftArrowStarPattern(int n) {
    cout << "leftArrowStarPattern" << endl;
    // Upper part
    for (int i = 0; i < n; i++) {
        // Spaces
        for (int space = 0; space < n - i -1; space++) {
            cout << " ";
        }
        // Stars
        for (int j = 0; j < n-i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    // Lower part
    for (int i=1 ; i<n ; i++) {
        // Spaces
        for (int space = 0; space < i; space++) {
            cout << " ";
        }
        // Stars
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}
void numDiamond(int n){
    cout << "numDiamond" << endl;
    int count =1;
    for(int i=1 ; i<=n/2+1 ;i++){
        for(int j=0 ;j<(n+1)/2-i ;j++){
            cout <<" ";
        }
        for(int j=1 ;j<=i ;j++){
            cout <<count++ << " ";
        }
        cout << endl;

    }
    for(int i=1 ; i<=n/2 ;i++){
        for(int j=1 ;j<=i ;j++){
            cout <<" ";
        }
        for(int j=1 ;j<=(n+1)/2-i ;j++){
            cout <<count++ << " ";
        }
        cout << endl;

    }

}
void pattern23(int n){
    cout << "pattern23" << endl;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n-i ; j++){
            if (i%2==0) cout <<"* ";
            else cout << "@ ";
        } 
        cout<< endl;
    }

}
void pattern24(int n){
    cout << "pattern24" << endl;
    for(int i=0 ; i<n ; i++){
        //space
        for(int sp=0 ; sp<n-i-1 ; sp++){
            cout <<" ";
        }
        // num
        int x=i;
        
        for(int j=0 ;j<=2*i ;j++){
            if(j<=i) x++;
            else x--;
            cout << x;
        }
        cout <<endl;
    }
}
void pattern25(int n){
    cout << "Pattern25 : " << endl;
    for(int i=0 ; i<n ;i++){
        for(int j=0 ;j<n ;j++){
            if(i==0 || i==n-1 ){
                cout << "* ";
            }
            else if(j==(n-i-1)){
                cout << "* ";
            }
            else cout << "  ";
        }
        cout << endl;
    }
}
void pattern26(int n){
    cout << "pattern26 : " << endl;
    for(int i=0 ; i<n ;i++){
        
        for(int j=0 ;j<2*n-1 ;j++){

            if(i==n-1) cout << "* ";
            else if(j==n-i-1 || j==n+i-1) cout << "* ";
            else cout << "  ";
        }
        cout << endl;
    }
}
int main(){

   

    int n;
    cout << "enter range: ";
    cin >> n;
    pattern1(n);
    cout << endl;
    pattern2(n);
    cout << endl;
    pattern3(n);
    cout << endl;
    pattern4(n);
    cout << endl;
    pattern5(n);
    cout << endl;
    pattern6(n);
    cout << endl;
    pattern7(n);
    cout << endl;
    pattern8(n);
    cout << endl;
    pattern9(n);
    cout <<endl;
    pattern10(n);
    cout << endl;
    pattern11(n);
    cout << endl;
    pattern12(n);
    cout << endl;
    pattern13(n);
    cout << endl;
    pattern14(n);
    cout << endl;
    pattern15(n);
    cout << endl;
    pattern16(n);
    cout << endl;
    pattern17(n);
    cout << endl;
    pattern18(n);
    cout << endl;
    pattern18_(n);
    cout << endl;
    pattern19(n);
    cout <<endl;
    pattern20(n);
    cout <<endl;
    pattern21(n);
    cout <<endl;
    pattern22(n);
    cout <<endl;
    pattern22_(n);
    cout << endl;
    rightArrowStarPattern(n);
    cout << endl;
    leftArrowStarPattern(n);
    cout<<endl;
    numDiamond(n);
    cout << endl;
    pattern23(n);
    cout << endl;
    pattern24(n);
    cout << endl;
    pattern25(n);
    cout << endl;
    pattern26(n);


}
