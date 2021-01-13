#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 1001
typedef unsigned long long int ulli;

ulli sums[5], segment;
ulli tenpow[11];

void init(){
    tenpow[0] = 1;
    for(int i=1;i<11;++i){
        tenpow[i] = tenpow[i-1]*10;
    }
    for(int i=0;i<5;++i) sums[i] = 0;
}

int main() {
    int N;
    char inp[51];
    init();
    
    scanf("%d", &N);

    for(int n=0;n<N;++n){
        scanf("%s", inp);
        for(int i=0;i<5;++i){
            
            segment = 0;
            for(int j = 0; j<10; ++j){
                segment += (ulli)(inp[i*10 + j] - '0')*(tenpow[9-j]);
            }
            sums[4-i] += segment;
        }
    }
    
    for(int i=1;i<5;++i){
        sums[i] += (ulli)(sums[i-1]/tenpow[10]);
    }

    int counter = 0;
    segment = sums[4];
    while(segment != 0){
        segment /= 10;
        ++counter;
    }

    printf("%llu\n", sums[4]/(int)(pow(10,counter-10)));
    return 0;
}
