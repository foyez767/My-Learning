#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 7, M = 21;
vector<int> grp[N];
int par[N][M], level[N], travels[N];
vector<pair<int,int>> roads;

//O(v + e)
void dfs (int u, int p) {
    par[u][0] = p;

    for (auto v : grp[u]) {
        if (v != p) {
            dfs (v, u);
        }
    }
}

void dfs2 (int u, int p) {
    level[u] = level[p] + 1;
    for (auto v : grp[u]) {
        if (v != p) {
            dfs2 (v, u);
            travels[u] += travels[v];
        }
    }
}

//NlogN
void fillUpTheSparseTable (int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; (1 << j) <= n; j++) {
            if(par[i][j - 1] != -1)
                par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}

//log(N)
int LCA (int u, int v) {
    if (level[u] < level[v]) swap(u, v);

//taking u and v on the same level
    for (int j = M - 1; j >= 0; j--) {
        if(level[u] - (1 << j) >= level[v]) {
            u = par[u][j];
        }
    }

    if (u == v) return u;
    //now finding the lca
    for (int j = M - 2; j >= 0; j--) {
        if (par[u][j] != -1 && (par[u][j] != par[v][j])) {
            u = par[u][j];
            v = par[v][j];
        }
    }
return par[u][0];       //also par[v][0] is same
}

void takeInput (int n) {
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        grp[u].push_back(v);
        grp[v].push_back(u);
        roads.push_back({u, v});
    }
}

void solve(){
    int n; cin >> n;

    takeInput(n);

    dfs(1, -1); //if one is the root node

    fillUpTheSparseTable(n);

    int m; cin >> m;

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        travels[u]++; travels[v]++;
        int lca = LCA(u, v);
        travels[lca] -= 2;
    }

    dfs2(1, 0);

    for (auto [u, v] : roads) {
        if (level[u] < level[v]) {
            swap (u, v);
        }

        cout << travels[u] << " ";
    }
    cout << "\n";

}
 
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(par, -1, sizeof(par));

    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    
    return 0;
}
