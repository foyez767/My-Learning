#include<bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e15;

void floyd_warshall (vector<vector<int>> &dis, int n) {

    for (int k = 1; k <= n; k++) {
        //let k is the middle element
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                dis[i][j] = min (dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

}

void solve(){
    int n, m, q; cin >> n >> m >> q;

    vector<vector<int>> dis (n + 1, vector<int> (n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = inf;

            if (i == j) dis[i][j] = 0;
        }
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        dis[u][v] = min (dis[u][v], w);
        dis[v][u] = dis[u][v];
    }
 
    floyd_warshall(dis, n);

    while (q--) {
        int u, v; cin >> u >> v;

        if (dis[u][v] != inf) {
            cout << dis[u][v] << "\n";
        } else if (dis[v][u] != inf) {
            cout << dis[v][u] << "\n";
        } else {
            cout << -1 << "\n";
        }
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