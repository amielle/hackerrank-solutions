#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long int lli;

int main() {
    int T;
    lli N;

    scanf("%d", &T);

    for(int t=0; t<T; ++t){
        scanf("%lld", &N);

        lli div = 2, ans = N, temp;
        lli limit = sqrt(N) + 5;

        while(!(N&1)) N /= 2;

        if (N == 1) ans = 2;
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

        printf("%lld\n", ans);
    }

    return 0;
}
