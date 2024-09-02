//
// Created by Hao Ji on 2023/05/25.
//

#ifndef ATCODER_AC90_018_H
#define ATCODER_AC90_018_H
#include <iostream>
#include <vector>
#include "queue"
#include "stack"
#include "set"
#include "unordered_set"
#include "map"
#include "unordered_map"
#include "math.h"
#define PI 3.14159265358979

typedef long l;
typedef long long ll;
using namespace std;
long double yt,zt,Ta,ans,T,L,X,Y,Q,E;

void ac90_018(){
    cin >> T;
    cin >> L >> X >> Y;
    cin >> Q;
    while(Q-- > 0){
        cin >> E;
        double theta = E / T * 2.0 * PI;
        yt = -sin(theta) * (L / 2.0);
        zt = (L / 2.0) - cos(theta) * (L / 2.0);
        Ta = sqrt((yt-Y) * (yt-Y) + X * X);
        ans = atan2(zt, Ta) * 180.0 / PI;
        printf("%.12Lf\n", ans);
    }
    return;
}
#endif //ATCODER_AC90_018_H
