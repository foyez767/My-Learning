#include<bits/stdc++.h>
using namespace std;

const int N = 105;
vector<int> grp[N];
int deg[N], vis[N];

void Clear (int n) {
    for (int i = 1; i <= n; i++) {
        deg[i] = vis[i] = 0;
    }
}

int main(){
    int n, m; 

    while (cin >> n >> m and (!(n == 0 and m == 0))) {
        Clear (n);

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
            if (zin.empty()) {
                break;
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

        for (int i = 1; i <= n; i++) grp[i].clear();
    }


return 0;
}