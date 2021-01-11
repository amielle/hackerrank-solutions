#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 3000 + 2

int abc[MAXN];
void init(){
    for(int i=0;i<MAXN;++i){
        abc[i] = -1;
    }

    for(int a=1;a<MAXN;++a){
        for(int b=a+1;b<MAXN;++b){
            double c = sqrt(a*a + b*b); // higher precision
            
            if ((a+b+c) >= MAXN) break;
            if (c == (int)c){
                if(a*b*c > abc[(int)(a+b+c)]){
                    abc[(int)(a+b+c)] = a*b*c;
                    // printf("%d %d %f\n", a,b,c);
                }
            }
        }
    }
}
int main() {
    int T, N;
    init();
    scanf("%d", &T);
    
    while(T--){
        scanf("%d", &N);
        printf("%d\n", abc[N]);
    }
    return 0;
}
