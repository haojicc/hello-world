//
// Created by Hao Ji on 2023/05/25.
//

#ifndef ATCODER_AC90_020_H
#define ATCODER_AC90_020_H
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
#define PI 3.14159265358979

typedef long l;
typedef long long ll;
using namespace std;
ll a,b,c,t=1;

void ac90_020(){
    cin >> a >> b >> c;
    t = pow(c,b);
    if(a < t){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}

#endif //ATCODER_AC90_020_H
