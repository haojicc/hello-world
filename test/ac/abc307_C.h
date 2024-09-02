//
// Created by Hao Ji on 2023/06/25.
//

#ifndef ATCODER_ABC307_C_H
#define ATCODER_ABC307_C_H



#include <iostream>
#include <vector>
#include "queue"
#include "stack"
#include "set"
#include "unordered_set"
#include "map"
#include "unordered_map"
#include "math.h"
#include "cmath"
#include "algorithm"

typedef long long ll;
using namespace std;

int abc307_c() {
    int h,w;
    vector<set<pair<int, int>>> vec(3);
    for(int i = 0; i < 3; i++){
        cin >> h >> w;
        for(int y = 0; y < h; y++){
            for(int x = 0; x < w; x++){
                char ch; cin >> ch;
                if(ch == '#'){
                    vec[i].emplace(x,y);
                }
            }
        }
    }

    for(int i = -10; i <= 10; i++){
        for(int j = -10; j <= 10; j++){
            for(int l = -10; l <= 10; l++){
                for(int k = -10; k <= 10; k++){
                    set<pair<int, int>> newswt;
                    for(auto& it: vec[0]){
                        newswt.emplace(it.first + i, it.second + j);
                    }
                    for(auto& it: vec[1]){
                        newswt.emplace(it.first + l, it.second + k);
                    }

                    if(newswt == vec[2]){
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "No" << endl;

    return 0;
}

#endif //ATCODER_ABC307_C_H
