//
// Created by Hao Ji on 2024/07/22.
//

#ifndef ATCODER_CBMS2008_H
#define ATCODER_CBMS2008_H
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

void print(const std::vector<int>& v)
{
    std::for_each(v.begin(), v.end(), [](int x) {
        std::cout << x << " ";
    });
    std::cout << std::endl;
}

bool verify(vector<int>& v){
    for(int i = 0 ; i < v.size(); i++){
        if(v[i] == i+1) return false;
    }
    return true;
}
bool verify1(vector<int>& v){
    for(int i = 0 ; i < v.size(); i++){
        if(v[i] == i+1) return false;
    }

    for(int i = 0; i < v.size(); i++){
        if(v[2] == 1 && v[0] != 3) return true;
    }
    return false;
}

int main(){

    std::vector<int> v = {1,2,3,4,5};
    int cnt = 0;
    do {
        if(verify(v)){
            cnt++;
            print(v);
        }
    } while (std::next_permutation(v.begin(), v.end()));
    cout << cnt << endl;
    return 0;
}
#endif //ATCODER_CBMS2008_H
