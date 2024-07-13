#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> grp[N];
int n, m, cat[N], pre_cat[N]; 
bool can_go[N];

void dfs (int u, int p) {

    (cat[u]) ? pre_cat[u] = pre_cat[p] + cat[u] : pre_cat[u] = 0;

    if (pre_cat[u] > m) {
        return;
    }

    bool is_leaf = true;

    for (auto v : grp[u]) {
        if (v != p) {
            dfs (v, u);

            is_leaf = false;
        }
    }

    if (is_leaf) {
        can_go [u] = true;
    }

}

void Clear () {
    for (int i = 1; i <= n; i++) {
        can_go[i] = false;
        cat[i] = pre_cat[i] = 0;
    }
} 

void solve(){
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> cat[i];

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }

    dfs (1, 0);

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (can_go[i]) {
            ans++;
        }
    }

    cout << ans << "\n";

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