#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2505, inf = 1e15;
int dis[N], par[N], negative_cycle = 0;
vector<int> ans;

void Bellman_Ford (vector<tuple<int,int,int>> &edges, int n, int src) {

    dis[src] = 0;
    par[src] = 0;

    for (int i = 1; i <= n; i++) {
        for (auto [u, v, w] : edges) {
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                par[v] = u;
            }
        }
    }

    //checking for negative cycle
    int respons = 0;

    for (auto [u, v, w] : edges) {
        if (dis[u] + w < dis[v]) {
            negative_cycle = true;
            respons = u;
            break;
        }
    }


    for (int i = 1; i <= n; i++) {
        respons = par[respons];
    }

    int v = respons;

    while (true) {
        ans.push_back(v);
        v = par[v];

        if (v == respons and ans.size() >= 1) {
            break;
        }
    }
    ans.push_back(respons);

    reverse(ans.begin(), ans.end());

}

void solve(){
    int n, m; cin >> n >> m;

    vector<tuple<int,int,int>> edges;

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    for (int i = 1; i <= n; i++) dis[i] = inf;

    Bellman_Ford(edges, n, 1);

    if (negative_cycle) {
        cout << "YES\n";

        for (auto a : ans) cout << a << " "; cout << "\n";

    } else {
        cout << "NO\n";
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