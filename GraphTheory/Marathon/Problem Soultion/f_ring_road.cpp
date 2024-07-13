#include<bits/stdc++.h>
using namespace std;

const int N = 105;
vector<int> grp[N];
int cost [N][N], vis[N], crnt_cost = 0, last_visited_node = 0;

void dfs (int u) {
    vis[u] = 1;

    for (auto v : grp[u]) {
        if (!vis[v]) {
            last_visited_node = v;
            crnt_cost += cost[u][v];
            dfs (v);
        }
    }
}

void solve(){
    memset(cost, 0, sizeof(cost[0]) * N);

    int n, ttl_cost = 0; cin >> n;

    for (int i = 1; i <= n; i++) {
        int u, v, c; cin >> u >> v >> c;
        grp[u].push_back(v);
        grp[v].push_back(u);
        cost[v][u] = c;
        ttl_cost += c;
    }

    dfs (1);

    crnt_cost += cost[last_visited_node][1];
    
    cout << min (crnt_cost, ttl_cost - crnt_cost) << "\n";
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