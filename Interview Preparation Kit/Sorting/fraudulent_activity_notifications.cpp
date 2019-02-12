/*
    Notes/Findings:
    - It is possible to insert an item to an already sorted vector
    - Doing so can actually retain it being sorted
    - For speed, just put it all in one function apparently
    - Makes sense due to the information access, processing, and return overhead
      if a function is used for vectors (UPDATE: Tested it again and indeed, 
      the function made it timeout for the even days case)
    - Although coding with functions is still better to do for maintainability
    - There is still a better way to handle the typecasting for the median
  
    Fixes/tweaks from timeout/faulty version:
    - Removed the initialization of the vector everytime
    - Make it such that it just slides the subvector relative to the main vector
    - The method of sliding in this case was that the earliest was removed while
      the next value in the vector will take its place
    - Removed getMedian function
*/
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

vector<string> split_string(string);

int activityNotifications(vector<int> expenditure, int d) {
    // d - the number of trailing days' data used to calculate median spending 
    // sort the trailing days' data. afterwards, get the median (do logic then)
    double median = 0;
    int notif_count = 0;
    double med1 = 0;
    double med2 = 0;

    vector<int> sub(expenditure.begin(), expenditure.begin() + d);
    sort(sub.begin(),sub.end());

    // start at d due to the offset for which when to start
    for (int i = d; i < expenditure.size(); ++i) {
        
        if (i != d){
            // readjust the subvector
            auto pos = lower_bound(sub.begin(), sub.end(), expenditure[i - d - 1]);
            sub.erase(pos); 
            sub.insert(upper_bound(sub.begin(), sub.end(), expenditure[i - 1]), expenditure[i - 1]);

            med1 = (double)(sub[d/2]);
            med2 = (double)(sub[d/2 - 1]);
            if (d % 2 == 0) {
                median = (med1 + med2)/2;
            }
            else {
                median = sub[int(d/2)];
            }
        }
        else {
            med1 = (double)(sub[d/2]);
            med2 = (double)(sub[d/2 - 1]);
            if (d % 2 == 0) {
                median = (med1 + med2)/2;
            }
            else {
                median = sub[int(d/2)];
            }
        }
        if (expenditure[i] >= 2*median){
            ++notif_count;
        }
        cout << median << endl;
    }
    

    return notif_count;
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
