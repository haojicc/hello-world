//
// Created by Hao Ji on 2024/07/31.
//

#ifndef ATCODER_POJ3050_H
#define ATCODER_POJ3050_H

#include "iostream"
#include "set"
#include "string"

using namespace std;
char g[5][5];
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
set<string> s;

void dfs(int turn, int x, int y, string str){
    if(turn == 5) s.insert(str);
    else{
        int nx,ny;
        for(int i = 0; i < 4; i++){
            nx = x + dx[i];
            ny = y + dy[i];
            if(0 <= nx && nx < 5 && 0 <= ny && ny < 5) dfs(turn+1, nx, ny, str + g[nx][ny]);
        }
    }
    return;
}


int main(){
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            cin >> g[i][j];

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++){
            string temp = "";
            temp += g[i][j];
            dfs(0,i,j, temp);
        }


    cout << s.size() << endl;

    return 0;
}

#endif //ATCODER_POJ3050_H
