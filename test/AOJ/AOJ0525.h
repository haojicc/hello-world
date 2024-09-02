//
// Created by Hao Ji on 2024/07/31.
//

#ifndef ATCODER_AOJ0525_H
#define ATCODER_AOJ0525_H

#include "iostream"
#include "vector"

using namespace std;
int c,r;
int g_o[11][10001];
int g_i[11][10001];

int main(){
    while((cin >> r >> c) && (r+c) != 0){
        for(int i = 0 ; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> g_o[i][j];
                g_i[i][j] = g_o[i][j] ^ 1;
            }
        }
        int ans = 0;

        for(int index = 0; index < (1 << r); index++){
            int result = 0;
            vector<int> cnt_o(c,0);
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    if((index>>i) & 1) cnt_o[j] += g_i[i][j];
                    else cnt_o[j] += g_o[i][j];
                }
            }
            for(int j = 0; j < c; j++){
                result += max(cnt_o[j], r-cnt_o[j]);
            }
            ans = max(ans, result);
        }
        cout << ans << endl;
    }

    return 0;
}



#endif //ATCODER_AOJ0525_H
