#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3e4 + 5;
vector<pair<int,int>> grp[N];
bool vis[N];
int node, mx_dis, dis[N];

void dfs (int u) {
    vis[u] = true;

    if (dis[u] > mx_dis) {
        mx_dis = dis[u];
        node = u;
    }

    for (auto [v, w]: grp[u]) {
        if (!vis[v]) {
            dis[v] = dis[u] + w;
            dfs (v);
        }
    }
}

void bfs (int src, vector<int> &dist) {
    
    memset(vis, false, sizeof(vis));

    queue<int> q;
    q.push(src);
    vis[src] = true;
    dist[src] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (auto [v, w]: grp[u]) {
            if (!vis[v]) {
                dist[v] = dist[u] + w;
                vis[v] = true;
                q.push(v);
            }
        }
    }

}

void reset (int n) {
    node = -1, mx_dis = -1;
    for (int i = 0; i < n; i++) {
        grp[i].clear();
        vis[i] = false;
        dis[i] = 0;
    }
}

void solve(){
    int n; cin >> n;

    reset(n);

    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;

        grp[u].push_back({v, w});
        grp[v].push_back({u, w});
    }

    dfs (0);

    vector<int> dist_one_end (n, 0), dist_other_end (n, 0);

    bfs (node, dist_one_end);

    mx_dis = 0;

    for (int i = 0; i < n; i++) {
        if (dist_one_end[i] > mx_dis) {
            mx_dis = dist_one_end[i];
            node = i;
        }
    }

    bfs (node, dist_other_end);

    for (int i = 0; i < n; i++) {
        cout << max (dist_one_end[i], dist_other_end[i]) << "\n";
    }
 
}
 
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ":\n";
        solve();
    }
    
    return 0;
}