#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXG 20
typedef long long int lli;

int grid[MAXG][MAXG];

int main() {
    for(int i=0;i<MAXG;++i){
        for(int j=0;j<MAXG;++j){
            cin >> grid[i][j];
        }
    }
    lli product = 1;
    
    // get first product
    for(int i=0;i<4;++i){
        product *= grid[i][0];        
    }

    // check vertical
    for(int i=0;i<MAXG-3;++i){
        for(int j=0;j<MAXG;++j){
            
            lli temp = 1;
            for(int c=i;c<i+4;++c){
                temp *= grid[c][j];
            }
            if (temp > product) product = temp;
        }
    }
    
    // check horizontal
    for(int i=0;i<MAXG;++i){
        for(int j=0;j<MAXG-3;++j){
            
            lli temp = 1;
            for(int c=j;c<j+4;++c){
                temp *= grid[i][c];
            }
            if (temp > product) product = temp;
        }
    }

    // check \ diagonal
    for(int i=0;i<MAXG-3;++i){
        for(int j=0;j<MAXG-3;++j){
            
            lli temp = 1;
            for(int c=0;c<4;++c){
                temp *= grid[i+c][j+c];
            }
            // printf("%lld (%d %d)\n", temp, i,j);
            if (temp > product) product = temp;
        }
    }
    
    // check / diagonal
    for(int i=0;i<MAXG-3;++i){
        for(int j=0;j<MAXG-3;++j){
            
            lli temp = 1;
            for(int c=0;c<4;++c){
                temp *= grid[i+(3-c)][j+c];
            }
            if (temp > product) product = temp;
        }
    }
    printf("%lld\n", product);
    return 0;
}
