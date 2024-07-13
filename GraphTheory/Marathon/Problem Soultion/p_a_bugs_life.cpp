#include<bits/stdc++.h>
using namespace std;

const int N = 2005;
vector<int> grp[N];
bool vis[N], col[N], assumptions = true;

void dfs (int u) {
    vis[u] = true;

    for (auto v : grp[u]) {
        if (!vis[v]) {
            col[v] = !col[u];
            dfs (v);
        } else if (col[u] == col[v]) {
            assumptions = false;
        }
    }
}

void solve(){
    assumptions = true;

    int n, m; cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs (i);
        }
    }

    (assumptions) ? cout << "No suspicious bugs found!\n" : cout << "Suspicious bugs found!\n";

    for (int i = 1; i <= n; i++) {
        grp[i].clear();
        vis[i] = col[i] = false;
    }

}
 
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Scenario #" << i << ":\n";
        solve();
    }
    
    return 0;
}