//
// Created by Hao Ji on 2023/06/01.
//

#ifndef ATCODER_AC90_009_H
#define ATCODER_AC90_009_H


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
#define PI 3.14159265358979
struct Point{
    double px,py;
};
int N;
Point G[2009];

Point operator-(const Point& a1, const Point& a2){
    return Point{a1.px - a2.px, a1.py - a2.py};
}

double getangle(Point G){
    if(G.py >= 0.0){
        double I = G.px / sqrt(G.px * G.px + G.py * G.py);
        double angle = acos(I) * 180.0 / PI;
        return angle;
    }else{
        double I = G.px / sqrt(G.px * G.px + G.py * G.py);
        double angle = acos(I) * 180.0 / PI;
        return 360.0 - angle;
    }
}

double getangle2(double I1, double I2){
    double res = abs(I1 - I2);
    if(res >= 180.0) return 360.0 - res;
    return res;
}

double solve(int pos){
    vector<double> vec;
    for(int i = 1; i <= N; i++){
        if(i == pos) continue;
        Point SA = G[i] - G[pos];
        double angle = getangle(SA);
        vec.push_back(angle);
    }
    sort(vec.begin(), vec.end());

    double ret = 0.0;
    for(int i = 0; i < vec.size(); i++){
        double target = vec[i] + 180.0;
        if(target >= 360.0) target -= 360.0;
        int pos1 = lower_bound(vec.begin(), vec.end(), target) - vec.begin();

        int CandIdx1 = pos1 % vec.size();
        int CandIdx2 = (pos1 + vec.size() - 1) % vec.size();

        double Candidate1 = getangle2(vec[i], vec[CandIdx1]);
        double Candidate2 = getangle2(vec[i], vec[CandIdx2]);
        ret = max({ret, Candidate1, Candidate2});
    }

    return ret;
}

double solve_Slow(){
    double Answer = 0.0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= N; k++){
                if(i == j || i == k || j == k) continue;
                double I1 = getangle(G[i] - G[j]);
                double I2 = getangle(G[k] - G[j]);
                Answer = max(Answer, getangle2(I1, I2));
            }
        }
    }
    return Answer;
}
/*
 * 这个方法的核心思想是，找当每个点作为中间那个点的时候，所能组成的最大的角是多少。
 * 在这个写法中有个很去巧妙的地方，a角度最大的边是距离180+a最近的 lower_bound
 * */
double solver_Fast(){
    double Answer = 0.0;
    for(int i = 1; i <= N; i++){
        double ret = solve(i);
        Answer = max(Answer, ret);
    }

    return Answer;
}

void ac90_009() {
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> G[i].px >> G[i].py;
    }

    double FinalAns = solver_Fast();
    printf("%.12lf\n", FinalAns);
    return;
}

#endif //ATCODER_AC90_009_H
