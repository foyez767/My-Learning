#include<bits/stdc++.h>
#define int long long
using namespace std;

bool cmp(tuple<int,string,int> a, tuple<int,string,int> b) {
    if(get<0>(a) != get<0> (b)) {
        if(get<0>(a) < get<0> (b)) return false;
        else return true;
    } else {
        if(get<1>(a) >= get<1>(b)) return false;
        return true;
    }
return false;
}

void solve(){
    // freopen("input.txt", "r", stdin);

    int n; cin >> n;

    vector<string> names;

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

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        to_be_cnt.push_back(x);
    }

    map<int, bool> disqualified_status;

    for (int i = 0; i < n; i++) {
        bool batti = true;

        for (int j = 1; j <= no_of_rounds[i]; j++) {
            cin >> score[i][j];

            if (score[i][j] < 0) {
                batti = false;
            }
        }
        disqualified_status[i] = batti;

        sort(score[i].begin(), score[i].end());
        partial_sum(score[i].begin(), score[i].end(), score[i].begin());

    }

    vector<tuple<int, string, int>> valid_list; //[score, names, id]

    for (int i = 0; i < n; i++) {
        if (disqualified_status[i]) {
            int r = no_of_rounds[i], l = 0;

            if (no_of_rounds[i] > to_be_cnt[i]) {
                l = no_of_rounds[i] - to_be_cnt[i];
            }

            int obtained_score = score[i][r] - score[i][l];

            valid_list.push_back({obtained_score, names[i], i});
        }
    }

    sort (valid_list.begin(), valid_list.end(), cmp);

    //////////////////////////////////////////////////////
    // freopen("output.txt", "w", stdout);

    if (valid_list.empty()) {   //if there is no valid participants
        cout << "Deception knows no bounds; it is an art mastered by all!\n";
        return;
    }

    map<int, pair<int, int>> rank;  //[rank, score]
    int ra = 1;

    auto [scr, nam, id] = valid_list[0];

    rank[id]  = {ra, scr};

    for (int k = 1; k < valid_list.size(); k++) {
        auto [scr, nam, id] = valid_list[k];
        auto [scr2, nam2, id2] = valid_list[k - 1];

        if (scr == scr2 and nam == nam2) {
            rank[id] = {ra, scr};
        } else {
            rank[id] = {++ra, scr};
        }

    }

    for (int i = 0; i < n; i++) {
        if (!disqualified_status[i]) {
            cout << "Disqualified " << names[i] << "\n";
        } else {
            auto [r, scr] = rank[i];

            cout << r << " " << names[i] << " " << scr << "\n";
        }
    }
 
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