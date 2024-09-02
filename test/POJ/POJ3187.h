//
// Created by Hao Ji on 2024/07/30.
//

#ifndef ATCODER_POJ3187_H
#define ATCODER_POJ3187_H


#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;
int n, sum;
vector<int> num;
int table[11][11];

int check(vector<int> & num){
    int total = 0;
    for(int i = 0; i < n; i++){
        total += table[n][i+1] * num[i];
    }
    return total;
}

int main(){
    for(int i = 1; i <= 10; i++){
        table[i][1] = 1;
        table[i][i] = 1;
        for(int j = 2; j <= i; j++) table[i][j] = table[i-1][j] + table[i-1][j-1];
    }

    cin >> n >> sum;
    for(int i = 1; i <= n; i++) num.push_back(i);

    do{
        if(check(num) == sum){
            for(int i = 0; i < n; i++){
                if(i != 0) cout << ' ';
                cout << num[i];
            }
            cout << endl;
            break;
        }
    }while(next_permutation(num.begin(),num.end()));
    return 0;
}

#endif //ATCODER_POJ3187_H
