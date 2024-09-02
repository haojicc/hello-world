//
// Created by Hao Ji on 2023/05/24.
//

#ifndef ATCODER_PZ_S018_H
#define ATCODER_PZ_S018_H


#include <iostream>
#include <vector>
#include "queue"
#include "stack"
#include "set"
#include "unordered_set"
#include "map"
#include "unordered_map"
#include "math.h"

typedef long l;
typedef long long ll;
using namespace std;
int n,m,t;
char cs;

vector<vector<int>> matrixMulti(vector<vector<int>>& a, vector<vector<int>>& b){
    int an = a.size();
    int am = a[0].size();
    int bn = b.size();
    int bm = b[0].size();
    vector<vector<int>> ans(an, vector<int>(bm,0));

    if(am != bn){
        return ans;
    }

    for(int i=0; i<an; i++){
        for(int j=0; j<bm; j++){
            int sum = 0;
            for(int k=0; k<am; k++){
                sum += a[i][k] * b[k][j];
            }
            ans[i][j] = sum%2;
        }
    }

    return ans;
}

vector<vector<int>> matrixPower(vector<vector<int>>& a, int t){
    int an = a.size();
    int am = a[0].size();
    vector<vector<int>> ans(an,vector<int> (am));
    vector<vector<int>> base(an,vector<int> (am));

    for(int i=0; i<an; i++){
        for(int j=0; j<am; j++){
            if(i == j) ans[i][j] = 1;
            base[i][j] = a[i][j];
        }
    }

    while(t != 0){
        if(t & 1){
            ans = matrixMulti(ans,base);
        }
        base = matrixMulti(base, base);
        t >>= 1;
    }

    return ans;
}

void solution_s018(){
    cin >> n >> m >> t;
    vector<vector<int>> w(n,vector<int>(m,0));
    vector<vector<int>> ans(n,vector<int>(m,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> cs;
            if(cs == 'S'){
                w[i][j] = 1;
            }else{
                w[i][j] = 0;
            }
        }
    }

    vector<vector<int>> P(n,vector<int>(n,0));
    vector<vector<int>> Q(m,vector<int>(m,0));

    for(int i=0; i<n; i++){
        P[i][(i-1+n)%n] = 1;
        P[i][i] = 1;
        P[i][(i+1+n)%n] = 1;
    }

    for(int i=0; i<m; i++){
        Q[(i-1+m)%m][i] = 1;
        Q[i][i] = 1;
        Q[(i+1+m)%m][i] = 1;
    }

    P = matrixPower(P, t); // P^t with Binary Exponentiation
    Q = matrixPower(Q, t); // Q^t with Binary Exponentiation
    ans = matrixMulti(P, w);
    ans = matrixMulti(ans, Q); // P^t * w * Q^t

    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(ans[i][j] & 1){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return;
}


#endif //ATCODER_PZ_S018_H
