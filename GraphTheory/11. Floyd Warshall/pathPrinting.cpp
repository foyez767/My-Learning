#include<bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9;

vector<int> floyd_warshall (vector<vector<int>> &dis, int n, int u, int v) {
    vector<vector<int>> next (n + 1, vector<int> (n + 1, 0));

//initially, if we want to go from i to j, which one is next node from i? it is j since we didn't travel any of the
//middle node yet
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            next[i][j] = j;
        }
    }

//
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    //
    vector<int> path;
    path.push_back(u);

    while (u != v) {
        u = next[u][v];
        path.push_back(u);
    }

return path;
}

int32_t main(){
    int n, e; cin >> n >> e;

    vector<vector<int>> dis (n + 1, vector<int> (n + 1, inf));

    for (int i = 1; i <= e; i++) {
        int u, v, w; cin >> u >> v >> w;
        dis[u][v] = w;
    }

    for (int i = 1; i <= n; i++) {
        dis[i][i] = 0;
    }

    int u, v; cin >> u >> v;    //path from u to v

    vector<int> path = floyd_warshall(dis, n, u, v);

    for (auto v : path) cout << v << " "; cout << "\n";



return 0;
}