//
// Created by Hao Ji on 2024/08/21.
//

#ifndef ATCODER_POJ1862_H
#define ATCODER_POJ1862_H

#include<iostream>
#include<queue>
#include<iomanip>
#include<cmath>

using namespace std;

priority_queue<double> heap;
int n;

int main()
{
    cin >> n;
    while (n--)
    {
        int tmp;
        cin >> tmp;
        heap.push(tmp);
    }
    while (heap.size() != 1)
    {
        double a = heap.top(); heap.pop();
        double b = heap.top(); heap.pop();
        heap.push(2*sqrt(a * b));
    }
    cout << setprecision(3) << fixed << heap.top() << endl;
    return 0;
}

#endif //ATCODER_POJ1862_H
