// #include<bits/stdc++.h>
// using namespace std;

// int findDistance(int x ,int y){
//     return sqrt((x*x) + (y*y));
// }

// int solve(int idx, int x, int y, string &inputPath, int maxi){

//     vector<char>ways = {'D', 'L', 'R', 'U'};
//     vector<int>moveX = {0, -1, 1, 0};
//     vector<int>moveY = {-1, 0, 0, 1};

//     if (idx >= inputPath.length()){

//         int distance = findDistance(x,y);
//         if (distance >= maxi) maxi = distance;
//         return maxi;

//     }

//     for(int i=0 ; i<inputPath.length(); i++){

//         auto it = find(ways.begin(), ways.end(), inputPath[i]);
        
//         if(it != ways.end()){

//             int move = it - ways.begin();
        
//             x += moveX[move];
//             y += moveY[move];
//             maxi = max(maxi, findDistance(x,y));
//             continue;
//         } 
//         else{

//             for(int j=0; j<4 ; j++){

//                 char temp = inputPath[i];
//                 inputPath[i] = ways[j];

//                 x += moveX[move];
//                 y += moveY[move];

//                 solve(idx+1, x, y, inputPath, maxi);

//                 x -= moveX[move];
//                 y -= moveY[move];

//                 inputPath[i] = temp;
                
//             }
//         }

//     }
//     return maxi;

// }

// int main(){

//     string inputPath;
//     cin >> inputPath;

//     int maxD = solve(0, 0, 0 , inputPath, 0);
//     cout << inputPath << endl;
//     cout << maxD;
// }