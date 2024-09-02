//
// Created by Hao Ji on 2024/08/27.
//

#ifndef ATCODER_POJ2229_H
#define ATCODER_POJ2229_H

#include "iostream"
#include "vector"

using namespace std;
const int mod = 10000009;
int n;

void solve1(){
    vector<int> v(n+1,0);

    v[0] = 1;
    v[1] = 1;
    for(int i = 2 ; i <= n; i++){
        if(i % 2 == 0){
            v[i] = (v[i-1] + v[i/2]) % mod;
        }else{
            v[i] = v[i-1];
        }
    }

    cout << v[n] << endl;
    return ;
}

void solve2(){
    vector<int> v;
    int tmp = 1;
    int temp = n;
    while(temp > 0){
        v.push_back(tmp);
        temp >>= 1;
        tmp <<= 1;
    }

    vector<int> dp(n+1,1);
    for(int i = 1; i < v.size(); i++){
        for(int j = v[i]; j <= n; j++){
            dp[j] = (dp[j] + dp[j-v[i]]) % mod;
        }
    }

    cout << dp[n] << endl;
    return;
}


int main(){
    while(true){
        cin >> n;
        solve1();
        solve2();
    }

}

#endif //ATCODER_POJ2229_H
