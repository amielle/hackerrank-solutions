#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 1000002

typedef long long int lli;

int primes[MAXN];

bool isPrime(int N){
    lli div = 2;
    lli limit = sqrt(N) + 5;

    if(!(N&1)) return false;
    else{
        div = 3;
        while((div <= limit) && (N != 1)){
            if(N % div != 0) div += 2;
            else{
                N /= div;
                if (N != 1) return false;
            }
        }
    }
    
    return true;
}

void init(){
    int counter = 0;
    primes[counter++] = 2;
    for(int i=3;i<MAXN;++i){
        if(isPrime(i)) primes[counter++] = i;
    }
    primes[counter] = MAXN;
}

int main() {
    int T, N;
    init();

    scanf("%d", &T);
    
    while(T--){
        scanf("%d", &N); 
        int counter = 0;
        lli ans = 0;
        while(primes[counter] <= N){
            ans += primes[counter++];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
