#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
vector<int> grp[N];
int vis[N], dis[N], mx_dis = -1, node = -1;

void dfs (int u) {
    vis[u] = true;

    if (dis[u] > mx_dis) {
        mx_dis = dis[u];
        node = u;
    }

    for (auto v : grp[u]) {
        if (!vis[v]) {
            dis[v] = dis[u] + 1;
            dfs (v);
        }
    }
}

void dfs2 (int u) {
    vis[u] = true;

    mx_dis = max (mx_dis, dis[u]);

    for (auto v : grp[u]) {
        if (!vis[v]) {
            dis[v] = dis[u] + 1;
            dfs2 (v);
        }
    }
}

int main(){
    int n; cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }

    dfs (1);

    for (int i = 1; i <= n; i++) {
        dis[i] = 0; vis[i] = 0;
    }

    dfs2 (node);

    cout << mx_dis << "\n";

return 0;
}