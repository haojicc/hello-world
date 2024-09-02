//
// Created by Hao Ji on 2024/08/02.
//

#ifndef ATCODER_AOJ0121_H
#define ATCODER_AOJ0121_H

#include "iostream"
#include "string"
#include "unordered_map"
#include "queue"
#include "algorithm"

using namespace std;
int dir[4] = {1,-1,4,-4};
unordered_map<string, int> dp;

void bfs(){
    queue<string> q;
    q.push("01234567");
    dp["01234567"] = 0;
    while(!q.empty()){
        string cur = q.front();
        q.pop();

        int p = 0;
        for(int i = 0; i < 8; i++){
            if(cur[i] == '0'){
                p = i;
                break;
            }
        }

        for(int i = 0; i < 4; i++){
            int n = p + dir[i];
            if(0 <= n && n < 8 && !(p == 3 && i == 0) && !(p == 4 && i == 1)){
                string next = cur;
                swap(next[p], next[n]);
                if(dp.find(next) == dp.end()){
                    dp[next] = dp[cur] + 1;
                    q.push(next);
                }
            }
        }
    }
}

int main(){
    bfs();
    string s ;
    while(getline(cin, s)){
        s.erase(remove(s.begin(),s.end(),' '),s.end());
        cout << dp[s] << endl;
    }

    return 0;
}

#endif //ATCODER_AOJ0121_H
