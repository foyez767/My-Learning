//Good problem
#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;

int main(){
    int m, tc = 1; 

    while (cin >> m and m != 0) {
        map<int, vector<int>> grp;
        set<int> nodes;

        for (int i = 1; i <= m; i++) {
            int u, v; cin >> u >> v;
            grp[u].push_back(v);
            grp[v].push_back(u);
            nodes.insert(u); nodes.insert(v);
        }

        int src, ttl; 

        while (cin >> src >> ttl and (!(src == 0 and ttl == 0))) {
            map<int, int> dist;
            map<int, bool> vis;

            for (auto it = nodes.begin(); it != nodes.end(); it++) {
                dist[*it] = inf;
            }
            vis [src] = true;
            dist[src] = 0;

            queue<int> q;
            q.push(src);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (auto v : grp[u]) {
                    if (!vis[v]) {
                        dist[v] = dist[u] + 1;
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }

            int cnt = 0;

            for (auto [u, d] : dist) {
                if (d > ttl) {
                    cnt++;
                }
            }

            cout << "Case " << tc++ << ": " << cnt << " nodes not reachable from node " << src << " with TTL = " << ttl << ".\n";
        }
    }

return 0;
}