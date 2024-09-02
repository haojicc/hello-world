//
// Created by Hao Ji on 2024/07/24.
//

#ifndef ATCODER_AOJ0558_H
#define ATCODER_AOJ0558_H

#include "iostream"
#include "vector"
#include "queue"

using namespace std;
int h,w,n;
int sx,sy;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};

int encode(int x, int y){
    return x * 10000 + y;
}

pair<int, int> decode(int poi){
    int x = poi / 10000;
    int y = poi % 10000;
    return make_pair(x,y);
}

bool in_map(int x, int y){
    return 0 <= x && x < h && 0 <= y && y < w;
}

int main(){
    cin >> h >> w >> n;
    string str[h];
    int cnt = 0;
    for(int i = 0; i < h; i++){
        cin >> str[i];
        for(int j = 0; j < w; j++){
            if(str[i][j] == 'S'){
                sx = i;
                sy = j;
            }
        }
    }
    for(int cur = 1; cur <= n; cur++){
        queue< pair < int,int> > q;
        q.push(make_pair(encode(sx,sy),cnt));
        vector< vector < bool> > visited(h,vector<bool>(w,false));
        visited[sx][sy] = true;
        while(!q.empty()){
            pair<int, int> temp = q.front();q.pop();
            int curx = decode(temp.first).first;
            int cury = decode(temp.first).second;
            for(int i = 0; i < 4; i++){
                int nextx = curx + dx[i];
                int nexty = cury + dy[i];
                if(!in_map(nextx,nexty) || visited[nextx][nexty]) continue;
                if(str[nextx][nexty] == '0'+cur){
                    cnt = temp.second+1;
                    sx = nextx;
                    sy = nexty;
                    break;
                } else if(str[nextx][nexty] != 'X'){
                    q.push(make_pair(encode(nextx,nexty), temp.second+1));
                    visited[nextx][nexty] = true;
                }
            }
            if(cnt == temp.second+1) break;
        }
    }
    cout << cnt << endl;

    return 0;
}

#endif //ATCODER_AOJ0558_H
