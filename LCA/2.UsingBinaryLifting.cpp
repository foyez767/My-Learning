#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1005, M = 20;
vector<int> grp[N], level(N, 0);
int par[N][M];

//O(v + e)
void dfs (int u, int p) {
    level[u] = level[p] + 1;
    par[u][0] = p;

    for (auto v : grp[u]) {
        if (v != p) {
            dfs (v, u);
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
    for (int j = M - 1; j >= 0; j--) {
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
    }
}

void solve(){
    int n; cin >> n;

    takeInput(n);

    dfs(1, 0); //if one is the root node

    fillUpTheSparseTable(n);

    cout << LCA(1, 20) << "\n";     //1
    cout << LCA(11,19) << "\n";     //1
    cout << LCA(10, 8) << "\n";     //1
    cout << LCA(16, 18) << "\n";    //7
    cout << LCA(13, 13) << "\n";    //13
    cout << LCA(4, 20) << "\n";     //1
    cout << LCA(16, 14) << "\n";     //7
    cout << LCA(15, 20) << "\n";    //3
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

/*
20
1 2
1 3
2 4
2 5
4 9
5 10
5 11
3 6
3 7
3 8
8 15
7 12
7 13
7 14
12 16
12 17
14 18
14 19 
14 20
*/