#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1005;
vector<int> grp[N];
int people[N], visited[N];

void bfs (int src, int n) {
    bool vis [n + 1] {};
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (auto v : grp[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            visited[i]++;
        }
    }
}

void solve(){
    int k, n, m; cin >> k >> n >> m;

    for (int i = 1; i <= k; i++) cin >> people[i];

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        grp[u].push_back(v);
    }

    for (int i = 1; i <= k; i++) {
        bfs (people[i], n);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (visited[i] == k) {
            ans++;
        }
    }

    cout << ans << "\n";

    for (int i = 1; i <= n; i++) {
        grp[i].clear();
        people[i] = visited[i] = 0;
    }

}
 
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        solve();
    }
    
    return 0;
}