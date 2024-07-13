#include<bits/stdc++.h>
#define int long long
#define pll pair<int,int>
using namespace std;

const int N = 1e5 + 7, inf = 1e15;

void Dijkstra (int src, vector<vector<pair<int,int>>> &grp, vector<int> &dis) {
    
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, src});
    dis[src] = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dis[u]) continue;

        for (auto [v, w]: grp[u]) {
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<pair<int,int>>> grp (n + 1), rev_grp (n + 1);

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;

        grp[u].push_back({v, w});
        rev_grp[v].push_back({u, w});
    }

    vector<int> dis (n + 1, inf), rev_dis (n + 1, inf);

    Dijkstra(1, grp, dis);
    Dijkstra(n, rev_grp, rev_dis);


    int ans = inf;

    for (int u = 1; u <= n; u++) {
        for (auto [v, w] : grp[u]) {
            ans = min (ans, dis[u] + (w / 2) + rev_dis[v]);
        }
    }

    cout << ans << "\n";

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

/*
find shortest path from 1 to a
find shortest path from n to b

use discount coupon for (a - > b)

so answer will be (dis[a] + (a -> b) / 2 + rev_dis [b])
*/