#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 7;
vector<int> grp[N];
int node = -1, mx_dis = -1, dis[N], vis[N];

void dfs (int u) {
    vis[u] = true;

    if (dis[u] > mx_dis) {
        mx_dis = dis[u];
        node = u;
    }

    for (auto v : grp[u]) {
        if (!vis[v]) {
            dis[v] = dis[u] + 1;
            dfs (v);
        }
    }
}

void bfs (int src, vector<int> &dis) {
    memset(vis, false, sizeof(vis));
    queue<int> q;
    q.push(src);
    vis[src] = true;
    dis[src] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (auto v : grp[u]) {
            if (!vis[v]) {
                dis[v] = dis[u] + 1;
                vis[v] = true;
                q.push(v);
            }
        }
    }
    
}

void solve(){
    int n; cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }

    memset(vis, false, sizeof(vis));

    dfs (1);

    vector<int> dis_one_end (n + 1, 0), dis_other_end (n + 1, 0);

    bfs (node, dis_one_end);

    int other_end = -1, other_end_dis = -1;

    for (int i = 1; i <= n; i++) {
        if (dis_one_end[i] > other_end_dis) {
            other_end_dis = dis_one_end[i];
            other_end = i;
        }
    }
 
    bfs (other_end, dis_other_end);

    for (int i = 1; i <= n; i++) {
        cout << max (dis_one_end[i], dis_other_end[i]) << " \n " [i == n];
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