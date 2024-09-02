//
// Created by Hao Ji on 2024/08/19.
//

#ifndef ATCODER_POJ2393_H
#define ATCODER_POJ2393_H

#include "iostream"

using namespace std;
int n,s;
int price_cur,cnt;
int price_min = 5009;
long long total = 0;

int main(){
    cin >> n >> s;
    for(int i = 0 ; i < n; i++){
        cin >> price_cur >> cnt;
        if(price_min + s < price_cur){
            total += (price_min + s) * cnt;
            price_min = price_min + s;
        }else{
            total += price_cur * cnt;
            price_min = price_cur;
        }
    }
    cout << total << endl;

    return 0;
}

#endif //ATCODER_POJ2393_H
