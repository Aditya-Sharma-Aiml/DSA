#include<bits/stdc++.h>
using namespace std;

int knows(vector<vector<int>>& M, int a, int b){
    return M[a][b];
}

int isCeleb(vector<vector<int>>& M, int N){
    stack<int> s;
    //step-1: push all the people in the stack
    for(int i=0; i<N; i++){
        s.push(i);
    }

    //step-2: get two people from the stack and compare them, then push the potential celebrity back to the stack
    while(s.size() > 1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if(knows(M, a, b)){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }

    //step-3: check if the potential celebrity is a real celebrity or not
    int celebrity = s.top();
    s.pop();

    // step-4: verify the celebrity
    for(int i=0; i<N; i++){
        if(i != celebrity && (knows(M, celebrity, i) || !knows(M, i, celebrity))){
            return -1;
        }
    }

    return celebrity;
}

int main(){
    int N;
    cin >> N;
    vector<vector<int>> M(N, vector<int>(N));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> M[i][j];
        }
    }

    cout <<"celebrity is: " << isCeleb(M, N) << endl;
}