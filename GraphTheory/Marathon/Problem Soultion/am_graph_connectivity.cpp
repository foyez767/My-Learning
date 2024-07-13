#include<bits/stdc++.h>
using namespace std;

const int N = 30;
vector<int> grp[N];
int n, vis[N];

void dfs (int u) {
    vis[u] = true;

    for (auto v : grp[u]) {
        if (!vis[v]) {
            dfs (v);
        }
    }
}

void reset (int n) {
    for (int i = 1; i <= n; i++) {
        grp[i].clear();
        vis[i] = false;
    }
}

int main(){
    int tc; cin >> tc;
    
    while (tc--) {
        char ch; cin >> ch;

        int n = ch - 'A' + 1;

        reset(n);
        cin.ignore();

        string s;

        while (getline(cin, s) and (s != "")) {
            int u = s[0] - 'A' + 1, v = s[1] - 'A' + 1;
            grp[u].push_back(v);
            grp[v].push_back(u);
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                ans++;
                dfs (i);
            }
        }

        cout << ans << "\n";

        if (tc) cout << "\n";


    }

return 0;
}