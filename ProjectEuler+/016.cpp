#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 10001
char digits[MAXN];

int getsum(int n){
    int len = (int)((int)(n/log2(10))) + 1;
    
    sprintf(digits, "%.0Lf", exp2((long double) n));
    int sum = 0;
    for(int i=0; i<len; ++i) sum += (int)(digits[i] - '0');
    return sum;
}

int main() {
    int T, N;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        printf("%d\n", getsum(N));
    }
    return 0;
}
