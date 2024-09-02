//
// Created by Hao Ji on 2024/08/22.
//

#ifndef ATCODER_POJ3176_H
#define ATCODER_POJ3176_H

#include "iostream"
#include "vector"
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> tri(n);
    vector<int> dp(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            int tmp;
            cin >> tmp;
            tri[i].push_back(tmp);
        }
    }

    for(int i = 0; i < n; i++){
        if(i == 0) continue;
        for(int j = 0; j <= i; j++){
            if(j == 0) tri[i][j] += tri[i-1][j];
            else if(j == i) tri[i][j] += tri[i-1][j-1];
            else tri[i][j] += max(tri[i-1][j],tri[i-1][j-1]);
        }
    }

    int m = 0;
    for(int i = 1; i <= n; i++) m = max(m,tri[n-1][i]);
    cout << m << endl;

    return 0;
}


#endif //ATCODER_POJ3176_H
