#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 7;
vector<int> grp[N], cycles;
int par[N], vis[N], start = -1, finish = -1;
bool cycle = false;

void dfs (int u, int p) {
    if (cycle) return;

    vis[u] = true;
    par[u] = p;

    for (auto v : grp[u]) {
        if (cycle) return;
        if (!vis[v]) {
            dfs (v, u); 
        } else if (v != p) {
            cycle = true;
            
            int st = u;
            while (u != v) {
                cycles.push_back(u);
                u = par[u];
            }
            cycles.push_back(v);
            cycles.push_back(st);
            return;
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs (i, 0);

            if (cycle) {
                cout << cycles.size() << "\n";

                for (auto a : cycles) cout << a << " "; cout << "\n";

                return;
            }
        }
    }

    cout << "IMPOSSIBLE\n";

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