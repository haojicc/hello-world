//
// Created by Hao Ji on 2024/08/21.
//

#ifndef ATCODER_POJ3262_H
#define ATCODER_POJ3262_H

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

bool camp(vector < int > & a, vector< int > & b){
    return a[0] * b[1] < a[1] * b[0];
}

int main(){
    int n;
    cin >> n;
    vector< vector<int> > v(n,vector<int>(2,0));
    for(int i = 0; i < n; i++){
        cin >> v[i][0] >> v[i][1];
    }
    sort(v.begin(),v.end(), camp);

    long long ant = 0;
    int time = v[0][0];
    for(int i = 1; i < n; i++){
        ant += 2 * time * v[i][1];
        time += v[i][0];
    }

    cout << ant << endl;
    return 0;
}

#endif //ATCODER_POJ3262_H
