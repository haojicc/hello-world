//
// Created by Hao Ji on 2024/08/29.
//

#ifndef ATCODER_POJ2385_H
#define ATCODER_POJ2385_H


#include "iostream"
#include "vector"

using namespace std;
int w,t,n;

int main(){
    cin >> t >> w;
    vector<vector<int>> dp(t+1,vector<int>(w+1,0));
    for(int i = 1; i <= t; i++){
        cin >> n;
        for(int j = 0; j <= min(w,i); j++){
            if((j % 2 == 0 && n == 1) || (j % 2 == 1 && n == 2)){
                dp[i][j] = max(dp[i-1][j]+1, j>0?dp[i-1][j-1]+1:0);
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]);
            }
        }
    }
    cout << dp[t][w] << endl;
    return 0;
}


#endif //ATCODER_POJ2385_H
