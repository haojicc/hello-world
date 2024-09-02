//
// Created by Hao Ji on 2023/06/06.
//

#ifndef ATCODER_AC90_013_H
#define ATCODER_AC90_013_H

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
const int VN = 1e5+9;

ll n, m;
ll A[VN], B[VN], C[VN];

ll dist[VN];
ll dist1[VN];
ll distn[VN];
vector<pair<int, ll>> G[VN];

void dijkstra(int st){
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
    for(int i = 1; i <= n; i++){
        dist[i] = (1LL << 60);
    }

    dist[st] = 0;
    Q.push(make_pair(0, st));

    while(!Q.empty()){
        int pos = Q.top().second; Q.pop();
        for(int i = 0; i < G[pos].size(); i++){
            int to = G[pos][i].first;
            ll cost = G[pos][i].second;
            if(dist[to] > dist[pos] + cost){
                dist[to] = dist[pos] + cost;
                Q.push(make_pair(dist[to], to));
            }
        }
    }
}

int ac90_013() {
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> A[i] >> B[i] >> C[i];
        G[A[i]].push_back(make_pair(B[i], C[i]));
        G[B[i]].push_back(make_pair(A[i], C[i]));
    }

    dijkstra(1);
    for(int i = 1; i <= n; i++) dist1[i] = dist[i];

    dijkstra(n);
    for(int i = 1; i <= n; i++) distn[i] = dist[i];

    for(int i = 1; i <= n; i++){
        ll ans = dist1[i] + distn[i];
        cout << ans << endl;
    }

    return 0 ;
}


#endif //ATCODER_AC90_013_H
