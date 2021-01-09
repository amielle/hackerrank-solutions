#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAXN 10000 + 2
using namespace std;
typedef long long int lli;

lli primes[MAXN];

bool isPrime(int N){
    lli div = 2, ans = N, original = N, temp;
    lli limit = sqrt(N) + 5;

    while(!(N&1)) N /= 2;

    if (N == 1) return false;
    else{
        div = 3;
        while((div <= limit) && (N != 1)){
            if(N % div != 0) div += 2;
            else{
                temp = N;
                N /= div;
            }
        }

        ans = (N == 1) ? temp : N;
    }
    if (ans == original) return true;
    
    return false;
}

void init(){
    int counter = 1, num=3;
    primes[0] = 2;
    while(counter < MAXN-1){
        if(isPrime(num) == true){
            primes[counter++] = num;
        } 
        
        ++num;
    }
}

int main() {
    int T, N;
    init();

    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        printf("%lld\n", primes[N-1]);
    }
     
    return 0;
}
