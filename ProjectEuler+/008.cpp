#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 1000 + 5
typedef long long int lli;

char num[MAXN];

// Make a sliding checker (divide previous and just multiply to get the next.)
// Add alternate cases for 0 products. Included 0 check for divisor due to
//     raised security issue.

lli get_windowed_product(int offset, int K){
    lli product = 1;
    for(int i=offset;i<offset+K;++i){
        int multiplier = num[i] - '0';
        if (multiplier == 0) return 0;
        product *= multiplier;
    }
    return product;
}

int main() {
    int T, N, K;
    
    scanf("%d", &T);
    
    while(T--){
        scanf("%d %d", &N, &K);
        scanf("%s", num);

        // get initial window
        lli ans = get_windowed_product(0, K);
        lli prev = ans;

        for(int i=1;i<N-K+1;++i){
            if (num[i+K-1] == '0') i += (K-1);
            else{
                if((prev == 0) || ((num[i-1] - '0') == 0)){
                    prev = get_windowed_product(i, K);
                }
                else{
                    prev = prev*((num[i+K-1]- '0'))/((num[i-1] - '0'));
                }
                if (prev > ans) ans = prev;
            }
            
        }
        printf("%lld\n", ans);
    }
    return 0;
}
