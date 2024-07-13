#include<bits/stdc++.h>
using namespace std;

const int N = 105;
vector<int> grp[N];
int dist[N], vis[N];

void bfs (int src) {
    queue<int> q; 
    q.push(src);
    vis[src] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : grp[u]) {
            if (!vis[v]) {
                dist[v] = dist[u] + 1;
                vis[v] = true;
                q.push(v);
            }
        }

    }
}

void solve(){
    int n; cin >> n;
    
    for (int i = 1; i <= n; i++) {
        int u, k; cin >> u >> k;

        for (int j = 1; j <= k; j++) {
            int v; cin >> v;
            grp[u].push_back(v);
        }
    }

    bfs (1);

    cout << 1 << " " << 0 << "\n";

    for (int i = 2; i <= n; i++) {
        int d = (dist[i] == 0) ? -1 : dist[i];

        cout << i << " " << d << "\n";
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