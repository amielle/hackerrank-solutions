#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;
#define MAXN 5000000 + 1

lli steps[MAXN], maxsteps;
int maxindex[MAXN];

void init(){
    for(int t=0;t<MAXN;++t){
        steps[t] = 0;
    }

    steps[1] = 1;
    maxsteps = 1;
    maxindex[1] = 1;

    // While iterating, might as well store
    // the largest steps along the way.
    for(int i=2;i<MAXN;++i){
        lli val = i;
        lli temp = 0;
        while(val != 1){
            if((val < MAXN) && (steps[val] != 0)) break;

            if (val&1) val = 3*val+1;
            else val /= 2;
            ++temp;
        }
        steps[i] += (lli)(steps[val]) + temp;

        if(steps[i] >= maxsteps){
            maxsteps = steps[i];
            maxindex[i] = i;
        }
        else{
            maxindex[i] = maxindex[i-1];
        }
    }
}
int main() {
    int T, N;
    scanf("%d", &T);
    init();

    while(T--){
        scanf("%d", &N);

        printf("%d\n", maxindex[N]);
    }
    return 0;
}
