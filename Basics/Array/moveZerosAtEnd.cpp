#include<iostream>
#include<vector>
using namespace std;
void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int j=-1;
        // finding index which contain first 0
        for(int i =0 ; i<n ;i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }

        if (j==-1) return ;
        // iterate from j+1 => compare with non zero and swap if swap then ++ j otherwise loop (i) move one step 

        for(int i = j+1 ; i<n ; i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
int main(){
    int n;
    cin >> n;
    vector<int>arr;
    for(int i=0 ; i<n ; i++){
        int x;
        cin >>x;
        arr.emplace_back(x);

    }
    moveZeroes(arr);
    for(auto it : arr){
        cout << it << " ";
    }

}