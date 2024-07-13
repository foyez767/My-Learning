#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> grp[N];
int deg[N], vis[N];

void solve(){
    int n, m; cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        grp[u].push_back(v);
        deg[v]++;
    }

    vector<int> ans, zin;

    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            zin.push_back(i);
            vis[i] = 1;
        }
    }

    while (ans.size() < n) {
        if(zin.empty()) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        int u = zin.back();
        zin.pop_back();

        ans.push_back(u);

        for (auto v : grp[u]) {
            deg[v]--;

            if (deg[v] == 0 and !vis[v]) {
                vis[v] = 1;
                zin.push_back(v);
            }
        }
    }

    for (auto a : ans) cout << a << " "; cout << "\n";
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