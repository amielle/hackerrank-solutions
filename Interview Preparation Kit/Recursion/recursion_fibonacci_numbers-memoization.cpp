/*
    Problem Source:
    https://www.hackerrank.com/challenges/ctci-fibonacci-numbers/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=recursion-backtracking*/
#include <iostream>
#include <vector>

using namespace std;

// Implementation of a fibonacci function 
// through memoization

int fibonacci(int n, vector<int> temp) {
    if (!temp[n]) temp[n] = fibonacci(n-1, temp) + fibonacci(n-2, temp);
    return temp[n];
}

int main() {
    int n;
    cin >> n;
    vector<int> buffer(n + 1, 0); 
    buffer[1] = 1;
    buffer[2] = 1;

    if (n < 3) cout << buffer[n];
    else cout << fibonacci(n, buffer);
    return 0;
}

