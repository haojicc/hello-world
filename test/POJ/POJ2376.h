//
// Created by Hao Ji on 2024/08/01.
//

#ifndef ATCODER_POJ2376_H
#define ATCODER_POJ2376_H


#include "stdio.h"
#include "set"

using namespace std;
int n,t;
int s,e;

int main(){
    scanf("%d %d",&n,&t);
    multiset<int> container;
    while(n--){
        scanf("%d %d",&s,&e);
        decltype(container)::iterator it = container.upper_bound(s);
        if(it != container.end()){ container.erase(it); }
        container.insert(e);
    }
    printf("%d",container.size());
    return 0;
}

#endif //ATCODER_POJ2376_H
