/*
    Problem Source:
    https://www.hackerrank.com/challenges/ctci-recursive-staircase/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=recursion-backtracking
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int res;
    for (int s_itr = 0; s_itr < s; s_itr++) {
        int n;
        
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Termination issues, so better to use caching/memoization/bottom-up approach
        vector<int> buffer = {0,1,2,4};

        // Actual solution portion
        if (n < 4) res = buffer[n];
        else{
            for(int i=4;i < n + 1;++i){
                // You can see the pattern forming around 4 (follows through for the rest)
                buffer.push_back((buffer[i-3] + buffer[i-2] + buffer[i-1]));
            } 
            res = buffer[n] % 10000000007;
        }

        fout << res << "\n";
    }

    fout.close();

    return 0;
}
