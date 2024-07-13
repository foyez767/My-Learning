//problem : cses round trip 2
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 7;
vector<int> grp[N];
int col[N], par[N], vis[N], start = -1, finish = -1, cycle = 0;

void dfs (int u) {
    vis[u] = true;
    col[u] = 1;

    for (auto v : grp[u]) {
        if (!vis[v]) {
            par[v] = u;
            dfs (v);
        } else if (col[u] == col[v]) {
            cycle = 1;
            start = u;
            finish = v;
        }   
    }

    col[u] = 2;
}
void solve(){
    int n, m; cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        grp[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs (i);
        }
    }

    if (cycle) {
        vector<int> ans;

        // ans.push_back(start);
        int s = start, f = finish;

        while (f != s) {
            ans.push_back(s);
            s = par[s];
        }
        ans.push_back(s);
        ans.push_back(ans.front());

        reverse(ans.begin(), ans.end());

        cout << ans.size() << "\n";

        for (auto a : ans) cout << a << " "; cout << "\n";

    } else {
        cout << "IMPOSSIBLE\n";
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