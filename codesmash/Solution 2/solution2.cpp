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

bool cmp2(tuple<int, string, int> a, tuple<int, string, int> b) {
    if (get<2>(a) >= get<2> (b)) {
        return false;
    }
    return true;
}

void solve(){
    freopen("output.txt", "r", stdin);
    
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
        disqualified_status[i + 1] = batti;

        sort(score[i].begin(), score[i].end());
        partial_sum(score[i].begin(), score[i].end(), score[i].begin());

    }

    vector<tuple<int, string, int>> valid_list; //[score, names, id]

    for (int i = 0; i < n; i++) {
        if (disqualified_status[i + 1]) {
            int r = no_of_rounds[i], l = 0;

            if (no_of_rounds[i] > to_be_cnt[i]) {
                l = no_of_rounds[i] - to_be_cnt[i];
            }

            int obtained_score = score[i][r] - score[i][l];

            valid_list.push_back({obtained_score, names[i], i + 1});
        }
    }

    sort (valid_list.begin(), valid_list.end(), cmp);

    map<pair<string,int>, int> rank;

    int k = 1;

    for (int i = 0; i < valid_list.size(); i++) {
        auto [scr, nam, id] = valid_list[i];

        if (rank[{nam, scr}]) {
            continue;
        }

        rank [{nam, scr}] = k++;
    }


    sort (valid_list.begin(), valid_list.end(), cmp2);

    freopen("output.txt", "w", stdout);

    if (valid_list.empty()) {   //if there is no valid participants
        cout << "Deception knows no bounds; it is an art mastered by all!\n";
        return;
    }

    int idx = 1;

    for (int i = 0; i < valid_list.size(); i++) {
        auto [scr, nam, id] = valid_list[i];

        if (id != idx) {
            cout << "Disqualified\n";
            i--, idx++;
            continue;
        } else {
            string namee = get<1> (valid_list[i]);
            int scrr = get<0> (valid_list[i]);

            int rak = rank [{namee, scrr}];

            cout << rak << " " << namee << " " << scrr << "\n";
            idx++;
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