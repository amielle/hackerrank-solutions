#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// since MAXN is 10e9 + 1, it's too large and can't be saved

typedef long long int lli;

lli arithmetic_progression(lli upper_bound, lli divisor){
    if (upper_bound % divisor == 0) --upper_bound;

    lli n = upper_bound/divisor;

    lli ap_sum = n*divisor*(n+1)/2;

    return ap_sum;
}

int main() {
    int T;
    lli N;

    scanf("%d", &T);

    for(int t=0; t<T; ++t){
        scanf("%lld", &N);

        // use arithmetic progression instead

        lli ans = arithmetic_progression(N,3);
        ans += arithmetic_progression(N,5);
        ans -= arithmetic_progression(N,15);

        printf("%lld\n", ans);
    }

    return 0;
}
