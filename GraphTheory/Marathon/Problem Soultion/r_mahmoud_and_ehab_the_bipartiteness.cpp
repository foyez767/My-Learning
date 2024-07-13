#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 7;
vector<int> grp[N];
int col[N], vis[N];

void dfs (int u) {
    vis[u] = 1;

    for (auto v : grp[u]) {
        if (!vis[v]) {
            col[v] = !col[u];
            dfs (v);
        }
    }
}

void solve(){
    int n; cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }
    
    dfs (1);

    int red = 0, blue = 0;

    for (int i = 1; i <= n; i++) {
        (col[i]) ? red++ : blue++;
    }

    cout << ((red * blue) - (n - 1)) << "\n";

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