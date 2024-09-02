//
// Created by Hao Ji on 2024/07/18.
//

#ifndef ATCODER_POJ1979_H
#define ATCODER_POJ1979_H


#include "iostream"
#include "string"

using namespace std;
int h, w;
int cnt;
int visited[22][22];
string str[22];

void dfs(int x, int y){
    if(x < 0 || x >= h || y < 0 || y >= w || visited[x][y] == 1) return;
    visited[x][y] = 1;
    if(str[x][y]=='.'){
        cnt++;
        dfs(x+1,y);
        dfs(x-1,y);
        dfs(x,y+1);
        dfs(x,y-1);
    }
    return;
}

int main(){
    while(cin >> w >> h && w != 0){
        int sh, sw;
        cnt = 0;
        for(int i = 0; i < h; i++){
            cin >> str[i];
            for(int j = 0; j < w; j++){
                visited[i][j] = 0;
                if(str[i][j] == '@'){sh = i; sw = j;str[i][j]='.';}
            }
        }
        dfs(sh,sw);
        cout << cnt << endl;
    }
    return 0;
}


//------------------

#include "iostream"
#include "string"
#include "queue"

using namespace std;
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

int main(){
    int h, w;
    while(cin >> w >> h && w != 0){
        string str[h];
        int visited[h][w];
        queue< pair < int, int> > q;
        for(int i = 0; i < h; i++){
            cin >> str[i];
            for(int j = 0; j < w; j++){
                visited[i][j] = 0;
                if(str[i][j] == '@'){
                    visited[i][j] = 1;
                    q.push(make_pair(i,j));
                }
            }
        }
        int cnt = 0;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();cnt++;
            for(int k = 0; k < 4; k++){
                int xx = x+dx[k];
                int yy = y+dy[k];
                if(xx >= 0 && xx < h && yy >= 0 && yy < w && str[xx][yy] == '.' && visited[xx][yy] == 0){
                    q.push(make_pair(xx,yy));
                    visited[xx][yy] = 1;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

#endif //ATCODER_POJ1979_H
