#include <bits/stdc++.h>
#include <cmath>
using namespace std;

vector<string> split_string(string);

// Complete the activityNotifications function below.
int getMedian(vector<int> trailing_data, int days){
    int median;

    sort(trailing_data.begin(), trailing_data.end());

    if (days % 2 == 0) {
        median = round((trailing_data[days/2] + trailing_data[days/2 - 1])/2 + 0.5);
    }
    else {
        median = trailing_data[int(days/2)];
    }
    return median;
}

int activityNotifications(vector<int> expenditure, int d) {
    // d - the number of trailing days' data used to calculate median spending 
    // sort the trailing days' data. afterwards, get the median (do logic then)
    int median = 0;
    int notifs = 0;

    vector<int>::const_iterator first;
    vector<int>::const_iterator last;
    vector<int> sub (d + 1);
    

    for (int i = 0; i < expenditure.size() - d; ++i) {
        copy(expenditure.begin() + i, expenditure.begin() + i + d + 1, sub.begin());
        median = getMedian(sub, d);

        if (expenditure[i + d] >= 2*median) {
            ++notifs;
        }
        cout << expenditure[i + d];
        //sub = vector<int>();
    }
    

    return notifs;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
