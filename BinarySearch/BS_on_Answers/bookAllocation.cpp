#include<bits/stdc++.h>
using namespace std;

int countStudents(vector<int>&book , int pages){
    int student  = 1;
    long long pagesStudent = 0;// current student has no. of pages
    for(int i=0 ; i< book.size() ; i++){
        
        if(pagesStudent + book[i] <= pages){
            //add pages to current student
            pagesStudent += book[i];
        }
        else{
            //add pages to next student
            student += 1;
            pagesStudent = book[i];
        }
    }
    return student;
}
//Time Complexity: O(N * (sum(book[])-max(book[])+1))
int findPages_bruteForce(vector<int>&book , int m){

    if (m>book.size()) return -1;

    long long low = *max_element(book.begin(), book.end());
    long long high = accumulate(book.begin(), book.end(),0);

    for(long long pages = low ; pages <= high ; pages++){

        if (countStudents(book , pages)==m){
            return pages;
        }
    }
    return low;


}

// Optimal: BS
// Time Complexity: O(N * log(sum(book[])-max(book[])+1))

int findPages(vector<int>& book,int m) {

    //book allocation impossible:
    if (m > book.size()) return -1;

    int low = *max_element(book.begin(), book.end());
    int high = accumulate(book.begin(), book.end(), 0);

    while (low <= high) {

        int mid = (low + high) / 2;

        int students = countStudents(book, mid);

        if (students > m) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

int main(){
    int n, m; // m: no. of student
    cin >> n >> m;
    vector<int>book(n);
    for(int i=0 ; i<n ;i++){
        cin >> book[i];
    }
    cout << "maximaum pages as minimum possible : " <<findPages(book, m);

}