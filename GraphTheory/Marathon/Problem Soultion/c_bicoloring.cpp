#include<bits/stdc++.h>
using namespace std;

const int N = 205;
vector<int> grp[N];
bool vis [N], col [N], bicolorable;

void dfs (int u) {
    vis[u] = true;

    for (auto v : grp[u]) {
        if (!vis[v]) {
            col[v] = !col[u];
            dfs (v);
        } else if (col[v] == col[u]) {
            bicolorable = false;
        }
    }
}

void Clear (int n) {
    for (int i = 0; i < n; i++) {
        grp[i].clear();
        vis[i] = col[i] = false;
    }
}

int main(){
    int n; 

    while (cin >> n and n != 0) {
        int m; cin >> m;

        for (int i = 1; i <= m; i++) {
            int u, v; cin >> u >> v;
            grp[u].push_back(v);
            grp[v].push_back(u);
        }

        bicolorable = true;

        dfs (0);

        (bicolorable) ? cout << "BICOLORABLE.\n" : cout << "NOT BICOLORABLE.\n"; 

        Clear(n);
    } 

return 0;
}

/*
check a graph is bipartite or not
*/