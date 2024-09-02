//
// Created by Hao Ji on 2023/06/03.
//

#ifndef ATCODER_AC90_012_H
#define ATCODER_AC90_012_H
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

typedef long l;
typedef long long ll;
using namespace std;
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};



class unionfind{
public:
    vector<int> point;
    vector<int> len;
    void init(int h, int w){
        point.resize(h*w, -1);
        len.resize(h*w, 1);
    }

    int find(int p){
        if(point[p] == p) return p;
        int temp = find(point[p]);
        point[p] = temp;
        len[p] = 2;
        return point[p];
    }

    void merge(int a, int b){
        if(check(a,b)) return ;
        int ap = find(a);
        int bp = find(b);
        if(len[ap] > len[bp]){
            point[bp] = ap;
            len[bp] = len[ap];
        }else{
            point[ap] = bp;
            len[ap] = len[ap] == len[bp] ? len[bp]+1 : len[bp];
        }
    }

    bool check(int a, int b){
        int ap = find(a);
        int bp = find(b);
        if(ap == bp) return true;
        else return false;
    }
};

int h,w,q;
int map[2009][2009];

void query1(int r, int c){
    map[r][c] = 1;
}

void ac90_012() {


    return;
}

#endif //ATCODER_AC90_012_H
