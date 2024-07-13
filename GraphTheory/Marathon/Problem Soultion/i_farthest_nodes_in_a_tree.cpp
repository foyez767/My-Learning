#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3e4 + 5;
vector<pair<int,int>> grp[N];
bool vis [N];
int dis[N], node, max_dis;

void dfs (int u) {
    vis[u] = true;

    if (dis[u] > max_dis) {
        max_dis = dis[u];
        node = u;
    }

    for (auto [v, w] : grp[u]) {
        if (!vis[v]) {
            dis[v] = dis[u] + w;
            dfs (v);
        }
    }
}

void dfs2 (int u) {
    vis[u] = true;

    max_dis = max (max_dis, dis[u]);

    for (auto [v, w]: grp[u]) {
        if (!vis[v]) {
            dis[v] = dis[u] + w;
            dfs (v);
        }
    }
}

void Clear (int n) {
    for (int i = 0; i <= n; i++) {
        vis[i] = false;
        dis[i] = 0;
    }
}

void solve(){
    node = -1, max_dis = -1;

    int n; cin >> n; 

    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;

        grp[u].push_back({v, w});
        grp[v].push_back({u, w});
    }

    Clear(n);
    dfs (0);

    Clear(n);
    dfs2 (node);

    cout << max_dis << "\n";

    for (int i = 0; i <= n; i++) grp[i].clear();
}
 
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        solve();
    }
    
    return 0;
}