#include<bits/stdc++.h>
#define int long long
#define pll pair<int,int>
using namespace std;

const int N = 5005, inf = 1e15;
vector<pair<int,int>> grp[N];
int dis[N][2], n, m;


void  Dijkstra (int src) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (dis[u][1] < d) {
            continue;
        } 

        for (auto [v, w]: grp[u]) {
            if (d + w < dis[v][1]) {
                dis[v][1] = d + w;

                if (dis[v][0] == dis[v][1]) {
                    dis[v][1] = inf;
                }
                pq.push({dis[v][1], v});

                sort (dis[v], dis[v] + 2);
            }
        }
    }

}

void reset () {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            dis[i][j] = inf;
        }
        grp[i].clear();
    }
}

void solve(){
    cin >> n >> m;

    reset();
    
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;

        grp[u].push_back({v, w});
        grp[v].push_back({u, w});
    }

    Dijkstra(1);

    cout << dis[n][1] << "\n";
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

/*
It is recommended to solve cses: flight routes first, then it is easy peasy
*/