#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 105;
vector<int> grp[N];
int n, m, start, finish;

void bfs (int src, vector<int> &dist) {
    bool vis [n] {};

    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty()) {
        auto u = q.front(); q.pop();

        for (auto v : grp[u]) {
            if (!vis[v]) {
                vis[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

void solve(){
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }

    cin >> start >> finish;

    vector<int> dist_s (n, 0), dist_e (n, 0);

    bfs (start, dist_s);
    bfs (finish, dist_e);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans = max (ans, dist_s[i] + dist_e[i]);
    }

    cout << ans << "\n";

    for (int i = 0; i < n; i++) {
        grp[i].clear();
    }

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