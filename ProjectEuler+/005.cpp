#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int pfactors[41][10];
void primeFactors(int n) {
    int temp = n, counter = 0;

    while (n % 2 == 0){  
        pfactors[temp][counter++] = 2;
        n = n/2;  
    }  

    for (int i = 3; i <= sqrt(n); i = i + 2){
        while (n % i == 0){
            pfactors[temp][counter++] = i;
            n = n/i;  
        }  
    }  

    if (n > 2) pfactors[temp][counter++] = n;
    
    pfactors[temp][counter] = 0;
}

void init(){
    for(int i=1;i<=40;++i){
        primeFactors(i);
    }
}

int main() {
    int T, N;
    init();
    
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        
        // Solution is iteratable since small range.
        // Pre-processed primes help to only include
        // primes not yet included in the final answer
        int ans = N;
        for(int i=N-1; i>1;--i){
            int temp = ans, counter = 0;
            while(pfactors[i][counter] != 0){
                if (temp % pfactors[i][counter] != 0){
                    ans *= pfactors[i][counter];
                }
                else temp /= pfactors[i][counter];
                ++counter;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
