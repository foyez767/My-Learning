#include <bits/stdc++.h>
using namespace std;

struct player {
    int participation, needed;
    string name;
    vector<int> match;
    bool bad;
    int scores;
    int idx;
    int rank;
};

// Bubble Sort for sorting vector in non-increasing order
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<player> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].name;
        v[i].idx = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i].participation;
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i].needed;
    }

    for (int i = 0; i < n; i++) {
        int m = v[i].participation;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            if (x < 0) v[i].bad = 1;
            v[i].match.push_back(x);
        }
        bubbleSort(v[i].match); // Use Bubble Sort for sorting v[i].match
    }

    for (int i = 0; i < n; i++) {
        int cnt = min(v[i].participation, v[i].needed);
        v[i].scores = accumulate(v[i].match.begin(), v[i].match.begin() + cnt, 0);
    }

    sort(v.begin(), v.end(), [&](const player& a, const player& b) {
        return (a.scores == b.scores) ? (a.name < b.name) : (a.scores > b.scores);
    });

    int r = 1;
    player prev;
    bool f = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].bad) continue;
        if (f == 0) {
            v[i].rank = r;
            f = 1;
            prev = v[i];
            continue;
        }
        if (v[i].name == prev.name && v[i].scores == prev.scores) v[i].rank = r;
        else v[i].rank = ++r;
        prev = v[i];
    }

    vector<player> v1(n);
    for (int i = 0; i < n; i++) {
        v1[v[i].idx] = v[i];
    }

    int bad_cnt = 0;
    for (int i = 0; i < n; i++) {
        bad_cnt += (v1[i].bad);
    }
    if (bad_cnt == n) {
        cout << "Deception knows no bounds; it is an art mastered by all!" << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if (v1[i].bad) {
            cout << "Disqualified " << v1[i].name << '\n';
            continue;
        }
        cout << v1[i].rank << " " << v1[i].name << " " << v1[i].scores << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}
