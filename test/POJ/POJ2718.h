//
// Created by Hao Ji on 2024/07/29.
//

#ifndef ATCODER_POJ2718_H
#define ATCODER_POJ2718_H


#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

using namespace std;

int solve(vector<int>& d){
    int n = d.size();
    int len = n/2;
    int minDiff = INT_MAX;
    do{
        if(len != 1 && d[0] == 0) continue;
        if(n-len != 1 && d[len] == 0) continue;

        int first = 0;
        for(int i = 0; i < len; i++) first = first * 10 + d[i];

        int second = 0;
        for(int i = len; i < n; i++) second = second * 10 + d[i];

        if(abs(first - second) < minDiff) minDiff = abs(first - second);
    }while(next_permutation(d.begin(),d.end()));
    return minDiff;
}

int main(){
    int n;
    cin >> n;
    string temp;
    getline(cin, temp);
    for(int i = 0; i < n; i++){
        getline(cin, temp);
        temp.erase(remove(temp.begin(),temp.end(), ' '), temp.end());
        vector<int> d;
        for(int j = 0; j < temp.length(); j++) d.push_back(temp[j] - '0');
        cout << solve(d) << endl;
    }
    return 0;
}


#endif //ATCODER_POJ2718_H
