//
// Created by Hao Ji on 2023/07/13.
//

#ifndef ATCODER_BIT_MANIPULATION_H
#define ATCODER_BIT_MANIPULATION_H

void doSomething(int state){
    return ;
};

int count_bit_1_numbers(int state){
    return __builtin_popcount(state);
}

void gospers_Hack(int k, int m){
    int state = (1 << k) - 1;
    while (state < (1 << m))
    {
        doSomething(state);

        int c = state & - state;
        int r = state + c;
        state = (((r ^ state) >> 2) / c) | r;
    }
}
/*
 * 00000111
 * 00001011
 * 00001101
 * 00001110
 * ...
 * */


void Iterate_Subsets(int state){
    for (int subset=state; subset>0; subset=(subset-1)&state)
    {
        doSomething(subset);
    }
}

/*
 * bitset<100>bs; // define a bitset type variable

std::string str = std::bitset<32>(n).to_string(); // convert an integer n to bitset type, and then to string type

bs.set(); // make every bit as 1

bs.count(); // count the number of 1-bits in bs
 *
 *
 * */

#endif //ATCODER_BIT_MANIPULATION_H
