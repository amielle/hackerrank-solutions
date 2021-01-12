#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 193
typedef long long int lli;
lli div_val[MAXN];

int get_factors(lli N){
    int factors = 1;
    int limit = sqrt(N) + 5;
    
    for(int i=2;i<limit;++i){
        int power = 0;
        while(N % i == 0 && N != 1){
            N /= i;
            ++power;
        }
        factors *= (power + 1);
    }
    if (N > 1) factors *= 2;
    
    return factors;
}

void init(){
    for(int i=0;i<MAXN;++i){
        div_val[i] = 0;
    }
    int factors = 0, n = 0;
    lli sum_val;
    for(int i=1;i<MAXN ;++i){
        while(factors<=i){
            ++n;
            sum_val = n*(n+1)/2;
            factors = get_factors(sum_val);
        }
        if (div_val[factors] == 0){
            div_val[factors] = sum_val;
        }
    }
    
}

int main() {
    int T, N;
    lli ans;
    init();

    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        if(N<192){
            ++N;
            while(div_val[N] == 0 && N < MAXN) ++N;
            ans = div_val[N];
        }
        else if(N<=239) ans = 2031120;
        else if(N<=319) ans = 2162160;
        else if(N<=479) ans = 17907120;
        else if(N<=575) ans = 76576500;
        else if(N<=647) ans = 103672800;
        else if(N<=767) ans = 236215980;
        else ans = 842161320;

        printf("%lld\n", ans);
        
    }   
    return 0;
}
