// Scores 45.45 points

#include "scales.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

void init(int T) {
    /* ... */
}

void orderCoins() {
    /* ... */
    int W[] = {1, 2, 3, 4, 5, 6};
    int x = getLightest(W[0],W[1],W[2]);
    if(x==W[1]) swap(W[0],W[1]);
    if(x==W[2]) swap(W[0],W[2]);
    x = getLightest(W[0],W[3],W[4]);
    if(x==W[3]) swap(W[0],W[3]);
    if(x==W[4]) swap(W[0],W[4]);
    x = getLightest(W[0],W[1],W[5]);
    if(x==W[5]) swap(W[0],W[5]);

    x = getLightest(W[1],W[2],W[3]);
    if(x==W[2]) swap(W[1],W[2]);
    if(x==W[3]) swap(W[1],W[3]);
    x = getLightest(W[1],W[4],W[5]);
    if(x==W[4]) swap(W[1],W[4]);
    if(x==W[5]) swap(W[1],W[5]);

    x = getLightest(W[2],W[3],W[4]);
    if(x==W[3]) swap(W[2],W[3]);
    if(x==W[4]) swap(W[2],W[4]);
    x = getLightest(W[2],W[3],W[5]);
    if(x==W[5]) swap(W[2],W[5]);

    x = getLightest(W[3],W[4],W[5]);
    if(x==W[4]) swap(W[3],W[4]);
    if(x==W[5]) swap(W[3],W[5]);

    x = getMedian(W[3],W[4],W[5]);
    if(x==W[5]) swap(W[4],W[5]);

    answer(W);
}