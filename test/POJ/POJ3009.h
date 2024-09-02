//
// Created by Hao Ji on 2024/07/19.
//

#ifndef ATCODER_POJ3009_H
#define ATCODER_POJ3009_H

#include<cstdio>
#include<cstdlib>
#define size 30

int h,w;
int result;
int g[size][size];
int sx,sy,gx,gy;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

void dfs(int,int,int);
bool in_map(int,int);

int main(){
    while(scanf("%d%d",&w,&h) && (w+h)){
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
                scanf("%d",&g[i][j]);

        result = 11;
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++){
                if(g[i][j] == 2){
                    sx = i; sy = j;
                    g[i][j] = 0;
                }
                if(g[i][j] == 3){
                    gx = i; gy = j;
                }
            }
        dfs(sx,sy,0);
        if(result == 11)
            puts("-1");
        else
            printf("%d\n",result);
    }
    system("pause");
    return 0;
}

void dfs(int x,int y, int step){
    if(x == gx && y == gy){
        if(result > step) result = step;
        return ;
    }

    if(step == 10 || step >= result) return ;

    for(int i=0;i<4;i++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        while(in_map(xx,yy) && g[xx][yy] != 1){
            if(xx == gx && yy == gy){
                step++;
                if(result > step) result = step;
                return ;
            }
            xx += dx[i];
            yy += dy[i];
        }

        if(xx == x + dx[i] && yy == y + dy[i] || !in_map(xx,yy)) continue;

        g[xx][yy] = 0;
        dfs(xx-dx[i],yy-dy[i],step+1);
        g[xx][yy] = 1;
    }
}

bool in_map(int x, int y){
    return 0 <= x && x < h && 0 <= y && y < w;
}


#endif //ATCODER_POJ3009_H
