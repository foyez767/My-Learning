#include<bits/stdc++.h>
using namespace std;

const int N = 5005;
vector<int> grp[N];
bool vis[N];
int cnt = 0;

void dfs (int u) {
    vis[u] = true;

    for (auto v : grp[u]) {
        if (!vis[v]) {
            cnt++;
            dfs (v);
        }
    }
}

void reset (int n) {
    for (int i = 1; i <= n; i++) {
        vis[i] = false;
        grp[i].clear();
    }
}

int main(){
    int c, r;

    while (cin >> c >> r and !(c == r and c == 0)) {
        map<string, int> id;
        int k = 1;

        for (int i = 1; i <= c; i++) {
            string name; cin >> name;
            id[name] = k++;
        }

        for (int i = 1; i <= r; i++) {
            string u, v; cin >> u >> v;
            grp[id[u]].push_back(id[v]);
            grp[id[v]].push_back(id[u]);
        }

        int ans = 0;

        for (int i = 1; i <= c; i++) {
            if (!vis[i]) {
                cnt = 1;
                dfs (i);
                ans = max (ans, cnt);
            }
        }

        cout << ans << "\n";

        reset (c);
    }

return 0;
}