//
// Created by Hao Ji on 2023/05/28.
//

#ifndef ATCODER_AC90_008_H
#define ATCODER_AC90_008_H


#include <iostream>
#include <vector>
#include "queue"
#include "stack"
#include "set"
#include "unordered_set"
#include "map"
#include "unordered_map"
#include "math.h"
#include "cmath"


typedef long l;
typedef long long ll;
using namespace std;
int mod = 1e9+7;
const int N = 1e5+7;
int n,dp[8][N];
string s;
char t[8]{' ','a','t','c','o','d','e','r'};

void ac90_008() {
    cin >> n >> s;
    dp[0][0] = 1;

    for(int i=1; i<=n; i++){
        for(int j=0; j<8; j++){
            dp[j][i] += dp[j][i-1];
            dp[j][i] %= mod;
            if(s[i-1] == t[j]){
                dp[j][i] += dp[j-1][i-1];
                dp[j][i] %= mod;
            }
        }
    }
    cout << dp[7][n] << endl;
    return;
}

#endif //ATCODER_AC90_008_H
