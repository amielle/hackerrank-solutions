#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// can be smaller but made to safeguard
#define MAXN 1000*1000

int palindromes[MAXN];
int palindrome_count;

bool isPalindrome(int x){
    int s[7];
    int counter = 0;

    while (x > 0){
        s[counter++] = x%10;
        x /= 10;
    }

    int palindrome_len = 6;
    for(int i=0; i<palindrome_len/2; ++i){
        if (s[i] != s[palindrome_len - 1 - i]) return false;
    }
    
    return true;
}

void init(){
    int counter = 0;

    // three digit numbers only
    for (int i=100; i<1000; ++i){
        for (int j=100; j<1000; ++j){
            int product = i*j;

            if (isPalindrome(product)) palindromes[counter++] = product;
        }
    }

    palindrome_count = counter;
}

int main() {
    int T, N;
    init();

    scanf("%d", &T);

    for(int t=0; t<T; ++t){
        scanf("%d", &N);

        int ans = 0;

        // can be further optimized by sorting the pre-processed array
        // and just iterating until palindromes[i] > N
        for(int i=0;i<palindrome_count;++i){
            if ((palindromes[i] > ans) && (palindromes[i] < N))
                ans = palindromes[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
