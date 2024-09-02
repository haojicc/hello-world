//
// Created by Hao Ji on 2024/07/22.
//

#ifndef ATCODER_AOJ0118_H
#define ATCODER_AOJ0118_H
#include "iostream"
#include "vector"
#define size 109

using namespace std;

int h,w;
int cnt;
string str[size];
vector<int> a;

int index_trans(int y ,int x){
    return y * w + x;
}

int find_set(int x){
    if(a[x] == x) return x;
    a[x] = find_set(a[x]);
    return a[x];
}

void union_set(int x, int y){
    int px = find_set(x);
    int py = find_set(y);
    if(px == py) return ;
    else a[px] = py;
}

int main(){
    while(cin >> h >> w && (h+w) != 0){
        cnt = 0;
        a.resize(h*w+2);
        for(int i = 0; i < h; i++){
            cin >> str[i];
        }
        for(int i = 0; i < h*w+2; i++){
            a[i] = i;
        }

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(i > 0 && str[i][j] == str[i-1][j]){
                    union_set(index_trans(i,j), index_trans(i-1,j));
                }
                if(j > 0 && str[i][j] == str[i][j-1]){
                    union_set(index_trans(i,j), index_trans(i,j-1));
                }
            }
        }

        for(int i = 0; i <= index_trans(h-1,w-1); i++){
            if(a[i] == i) cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}
#endif //ATCODER_AOJ0118_H
