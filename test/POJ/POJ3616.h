//
// Created by Hao Ji on 2024/08/29.
//

#ifndef ATCODER_POJ3616_H
#define ATCODER_POJ3616_H


#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;
struct interval{
    int s;
    int en;
    int ef;
};

bool compareInterval(interval& a, interval& b){
    return a.en < b.en;
}
int n,m,r;

int main(){
    cin >> n >> m >> r;
    vector<interval> intervals(m);
    for(int i = 0; i < m; i++){
        cin >> intervals[i].s >> intervals[i].en >> intervals[i].ef;
        intervals[i].en += r;
    }
    sort(intervals.begin(),intervals.end(),compareInterval);
    vector<int> dp(n+r+1,0);
    int cnt = 0;
    for(int i = 1; i <= n+r; i++){
        dp[i] = dp[i-1];
        while(cnt < m && intervals[cnt].en == i){
            dp[i] = max(dp[i], dp[intervals[cnt].s] + intervals[cnt].ef);
            cnt++;
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}


#endif //ATCODER_POJ3616_H
