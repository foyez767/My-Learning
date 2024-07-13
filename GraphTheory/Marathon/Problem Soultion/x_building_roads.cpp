#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 7;
vector<int> grp[N];
bool vis[N];

void dfs (int u) {
    vis[u] = true;

    for (auto v : grp[u]) {
        if (!vis[v]) {
            dfs (v);
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }

    vector<int> city;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            city.push_back(i);
            dfs (i);
        }
    }

    if (city.size() < 2) {
        cout << 0 << "\n";
    } else {
        cout << (city.size() - 1) << "\n";

        for (int i = 1; i < city.size(); i++) {
            cout << city[i - 1] << " " << city[i] << "\n";
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