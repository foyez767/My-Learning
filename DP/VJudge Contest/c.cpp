#include<bits/stdc++.h>
#define int long long
using namespace std;

bool leap_year(int year) {
    // Check if the year is divisible by 4
    if (year % 4 == 0) {
        // If it's divisible by 100, it should also be divisible by 400 to be a leap year
        if (year % 100 == 0) {
            return year % 400 == 0;
        }
        return true;
    }
    return false;
}

void solve(){

    string gap   = "|---------------------------|";

    vector<vector<int>> vec (6, vector<int> (8, -1));

    vector<int> months = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> days = {"", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    vector<string> month_name = {"", "January", "February","March", "April", "May", "June", "July", "August",
        "September", "October", "November", "December"};

    vector<int> value = {0, 1, 2, 3, 4, 5, 6, 7};

    int day, month, year; char ch; cin >> day >> ch >> month >> ch >> year;

    bool leap = false;

    string start; cin >> start; 
    int initial = 0;

    for (int i = 1; i <= 7; i++) {
        if (start == days[i]) {
            initial = i;
            break;
        }
    }


    while (day != 1) {
        day--;

        initial--;

        if (initial == 0) {
            initial = 7;
        }

    }

    // cout << days[initial] << endl;

    start = days[initial];


    int no_of_day = 0;

    if (month == 2 and leap_year(year)) {
        leap = true;
        no_of_day = 29;
    } else {
        no_of_day = months[month];
    }

    no_of_day++;

        int first_row = -1;

        for (int i = 1; i <= 7; i++) {
            if (days[i] == start ) {
                first_row = i;
                break;
            }
        }

        int day_cnt = 1;

        for (int i = first_row; i <= 7; i++) {
            vec[1][i] = day_cnt;
            day_cnt++;
        }

        for (int i = 2; i <= 5; i++) {
            bool batti = true;

            for (int j = 1; j <= 7; j++) {
                if (day_cnt + 1 > no_of_day) {
                    batti = false;
                    break;
                }
                vec[i][j] = day_cnt++;
                
            }

            if (!batti) {
                break;
            }
        }

        if (day_cnt < no_of_day) {
            for (int i = 1; i <= 7; i++) {
                if (day_cnt + 1 > no_of_day) {
                    break;
                } else {
                    vec[1][i] = day_cnt;
                    day_cnt++;
                }
            }
        }

        // for (int i = 1; i <= 5; i++) {
        //     cout << i << " : ";
        //     for (int j = 1; j <= 7; j++) {
        //         cout << vec[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        cout << "Calendar for Month of "; cout << month_name[month] << ", " << year << "\n";


        // cout << gap << "\n";
        
        cout << "|";
        for (int i = 1; i <= 7; i++) cout << days[i] << "|"; cout << "\n";
        // cout << gap << "\n";


        for (int i = 1; i <= 5; i++) {
            // cout << "|";

            for (int j = 1; j <= 7; j++) {
                if (vec[i][j] == -1) {
                    // cout << " - |";
                    cout << "-";
                } else {
                    cout << " ";

                    // if (vec[i][j] < 10) {
                    //     cout << " " << vec[i][j] << "|";
                    // } else {
                    //     cout << vec[i][j] << "|";
                    // }
                    cout << vec[i][j];
                }
            }

            cout << "\n";
        }

        cout << gap << "\n";


    }


 
 
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve();

        cout << "\n";
    }
    
    return 0;
}