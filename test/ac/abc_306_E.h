//
// Created by Hao Ji on 2023/06/18.
//

#ifndef ATCODER_ABC_306_E_H
#define ATCODER_ABC_306_E_H



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

typedef long long ll;
using namespace std;

multiset<int> x,y;
int n,k,q;
ll sum=0;

void balance(){
    while(x.size() < k){
        auto iy = y.end();
        iy--;
        x.insert((*iy));
        sum += (*iy);
        y.erase(iy);
    }
    if(x.empty() || y.empty()) return;
    while(true){
        auto ix = x.begin(), iy = y.end();
        iy--;
        int ex = (*ix), ey = (*iy);
        if(ex >= ey) break;
        sum += (ey - ex);
        x.erase(ix), y.erase(iy);
        x.insert(ey), y.insert(ex);
    }
}

void erase(int v){
    auto ix = x.find(v);
    if(ix != x.end()){
        sum -= v;
        x.erase(ix);
    } else{
        y.erase(y.find(v));
    }
    balance();
}

int main() {
    cin >> n >> k >> q;
    vector<int> a(n+1, 0);
    for(int i=0;i<k;i++) x.insert(0);
    for(int i=k;i<n;i++) y.insert(0);
    sum = 0;
    while(q--){
        int p, w;
        cin >> p >> w;
        p--;
        y.insert(w);
        balance();
        erase(a[p]);
        a[p] = w;
        cout << sum << endl;
    }

    return 0;
}




#endif //ATCODER_ABC_306_E_H
