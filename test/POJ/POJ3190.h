//
// Created by Hao Ji on 2024/08/05.
//

#ifndef ATCODER_POJ3190_H
#define ATCODER_POJ3190_H

#include "iostream"
#include "algorithm"
#include "vector"
#include "queue"

using namespace std;
const int maxn = 50005;
struct cow{
    int s;
    int e;
    int index;
    cow(int s, int e, int idx):s(s),e(e),index(idx){}
    bool operator <(const cow A) const {
        return s < A.s;
    }
};
struct stall{
    int id;
    int lastendtime = -1;
    stall(int l, int i ):id(i),lastendtime(l){}
};
class compare{
public:
    bool  operator()(const stall A, const stall B) {
        return A.lastendtime > B.lastendtime;
    }
};

int main(){
    int N;
    cin >> N;
    vector<cow> cows;
    priority_queue<stall,vector<stall>, compare>stalls;
    int result[maxn];
    for(int i = 0; i < N; i++){
        int ss,ee;
        cin >> ss >> ee;
        cows.push_back(cow(ss,ee,i));
    }
    sort(cows.begin(),cows.end());
    int stallnum = 1;
    stall top = stall(cows[0].e,stallnum++);
    result[cows[0].index] = top.id;
    stalls.push(top);
    for(int i = 1; i < N; i++){
        top = stalls.top();
        if(top.lastendtime < cows[i].s){
            stalls.pop();
            top.lastendtime = cows[i].e;
            result[cows[i].index] = top.id;
            stalls.push(top);
        }else{
            stall temp = stall(cows[i].e,stallnum++);
            result[cows[i].index] = temp.id;
            stalls.push(temp);
        }
    }

    cout << stalls.size() << endl;
    for(int i = 0; i < N; i++){
        cout << result[i] << endl;
    }

    return 0;
}


#endif //ATCODER_POJ3190_H
