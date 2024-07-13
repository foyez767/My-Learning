#include<bits/stdc++.h>
#define int long long
#define pll pair<int,int>
using namespace std;

const int N = 1e5 + 7, inf = 1e15;
vector<pair<int,int>> grp[N];
int dis[N][10], n, m, k;


void  Dijkstra (int src) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (dis[u][k - 1] < d) {
            continue;
        } 

        for (auto [v, w]: grp[u]) {
            if (d + w < dis[v][k - 1]) {
                dis[v][k - 1] = d + w;
                pq.push({dis[v][k - 1], v});
                sort (dis[v], dis[v] + k);
            }
        }
    }

}

void reset () {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            dis[i][j] = inf;
        }
    }
}

int32_t main(){
    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        grp[u].push_back({v, w});
    }

    reset ();

    Dijkstra(1);

    for (int i = 0; i < k; i++) cout << dis[n][i] << " "; cout << "\n";

return 0;
}

//youtube : dardev