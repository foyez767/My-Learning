#include<bits/stdc++.h>
#define int long long
#define pll pair<int,int>
using namespace std;

const int N = 1e5 + 7, inf = 1e15;
vector<pair<int,int>> grp[N];

void Dijkstra (int src, vector<int> &dis) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    pq.push({0, src});
    dis[src] = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dis[u]) {
            continue;
        }

        for (auto [v, w]: grp[u]) {
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }

}

void reset (int n) {
    for (int i = 1; i <= n; i++) grp[i].clear();
}

void solve(){
    int n, m; cin >> n >> m;

    reset(n);

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        grp[u].push_back({v, w});
        // grp[v].push_back({u, w});
    }

    vector<int> dis (n + 1, inf);

    Dijkstra(1, dis);

    for (int i = 1; i <= n; i++) cout << dis[i] << " "; cout << "\n";
    
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