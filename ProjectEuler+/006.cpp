#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

int main() {
    int T, N;
    
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);

        // Derived from arithmetic progression
        // and general formula for sum of squares.
        // Can't distribute since it becomes a float midway
        lli ap = N*(N+1)/2;
        lli ans = ap*ap - ap*(2*N+1)/3;
        if (ans < 0) ans *= -1;

        printf("%lld\n", ans);
    }
    return 0;
}
