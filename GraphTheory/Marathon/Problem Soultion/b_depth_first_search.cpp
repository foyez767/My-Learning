#include<bits/stdc++.h>
using namespace std;

const int N = 105;
vector<int> grp[N];
int start[N], finish [N], crnt_time = 1;
int vis[N];

void dfs (int u) {
    vis[u] = 1;
    start[u] = crnt_time++;

    for (int v : grp[u]) {
        if (!vis[v]) {
            dfs (v);
        }
    }

    //this is where the recursion call ends for a vertex
    finish[u] = crnt_time++;
}

void solve(){
    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        start[i] = finish[i] = vis[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        int u, k; cin >> u >> k;

        for (int j = 1; j <= k; j++) {
            int v; cin >> v;
            grp[u].push_back(v);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs (i);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << i << " " << start[i] << " " << finish[i] << "\n";
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

/*
If there are several candidates to visit, the algorithm should visit the vertex with smalles id -->> we no
need to worry about this as the input is given in ascending order 

Remaining work is just normal DFS.

*** the graph is disconnected -> keep in mind
*/