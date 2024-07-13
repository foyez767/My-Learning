#include<bits/stdc++.h>
#define int long long
using namespace std;

bool cmp(pair<int,string> a, pair<int, string> b) {
    if(a.first != b.first) {
        if(a.first < b.first) return false;
        else return true;
    } else {
        if(a.second >= b.second) return false;
        return true;
    }
return false;
}

void solve(){
    int n; cin >> n;

    vector<string> names;
    // map<string, int> id;

    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        names.push_back(s);
    }

    vector<int> score [n];
    vector<int> no_of_rounds, to_be_cnt;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        no_of_rounds.push_back(x);
        vector<int> v (x + 1, 0);
        score[i] = v;
    }

    // for (auto s : score) {
    //     for (auto v : s) {
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        to_be_cnt.push_back(x);
    }

    map<int, bool> disqualified_status;

    for (int i = 0; i < n; i++) {
        bool batti = true;

        for (int j = 1; j <= no_of_rounds[i]; j++) {
            cin >> score[i][j];

            // cout << score[i][j] << endl;

            if (score[i][j] < 0) {
                batti = false;
            }
        }
        disqualified_status[i] = batti;

        sort(score[i].begin(), score[i].end());
        partial_sum(score[i].begin(), score[i].end(), score[i].begin());

        // for (auto v : score[i]) {
        //     cout << v << " ";
        // }
        // cout << "\n";
    }

    vector<pair<int, string>> valid_list;

    for (int i = 0; i < n; i++) {
        if (disqualified_status[i]) {
            int r = no_of_rounds[i], l = 0;

            if (no_of_rounds[i] > to_be_cnt[i]) {
                l = no_of_rounds[i] - to_be_cnt[i];
            }

            int obtained_score = score[i][r] - score[i][l];

            valid_list.push_back({obtained_score, names[i]});
        }
    }

    sort (valid_list.begin(), valid_list.end(), cmp);

    for (auto v : valid_list) cout << v.first << " " << v.second << "\n";
 
}
 
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    
    return 0;
}