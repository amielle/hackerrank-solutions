#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define MAXN 4e16

/*
    Since Fibonacci values grow really fast, we can make use
    of this property to pre-process the even values in
    the sequence.

    Spent hours on the math working with Binet, recurrence
    relation, and other properties but this was the faster
    method for implementation/comprehension (previous plan
    was to retrieve the summation by proof).
*/

lli fib_even[100];
void init(){
    lli x1, x2, temp;
    x1 = 1;
    x2 = 2;
    int counter = 0;
    
    fib_even[counter] = x2;

    while(1){
        temp = x2;
        x2 += x1;
        x1 = temp;
        
        if (x2 > MAXN) break;
        
        if (x2 % 2 == 0){
            fib_even[++counter] = x2;
        }
    }
    
    fib_even[++counter] = -1;
}

int main() {
    int T;
    lli N;
    init();
    
    scanf("%d", &T);

    for(int t=0; t<T; ++t){
        scanf("%lld", &N);
        
        lli ans = 0;
        int counter = 0;
        
        while(1){
            if ((fib_even[counter] > N) || (fib_even[counter] == -1)) break;
            else ans += fib_even[counter++];
        }
        printf("%lld\n", ans);
    }
    return 0;
}

