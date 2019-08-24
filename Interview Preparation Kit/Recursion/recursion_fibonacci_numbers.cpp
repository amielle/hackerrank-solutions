/*
    Problem Source:
    https://www.hackerrank.com/challenges/ctci-fibonacci-numbers/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=recursion-backtracking*/
#include <iostream>

using namespace std;

// Implementation of a fibonacci function 
// by traversing the entire "tree"
int fibonacci(int n) {
    if (n == 0) return 0;
    else if (n == 1 | n == 2) return 1;
    else return fibonacci(n - 1) + fibonacci(n - 2);

}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}