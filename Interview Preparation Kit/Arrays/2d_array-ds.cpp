/*
    Problem Source:
    https://www.hackerrank.com/challenges/2d-array/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays
*/
#include <bits/stdc++.h>
#include <limits>
using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int top_row, bottom_row, temp_sum, max_sum;
    max_sum = numeric_limits<int>::min();

    // Traverse by column first then to the next row.
    // Subtract the length and width for loop 
    // by 2 due to the hourglass shape.
    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
            top_row = arr[i][j] + arr[i][j+1] + arr[i][j+2];
            bottom_row = arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            temp_sum = top_row + bottom_row + arr[i+1][j+1];

            if (temp_sum > max_sum) max_sum = temp_sum;
            cout << temp_sum << endl;
        }
    }
    return max_sum;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
