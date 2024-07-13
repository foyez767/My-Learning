#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 7;
vector<int> grp[N];
int a[N], ans[N], parity[N];

void solve(){
    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        parity[i] = a[i] % 2;
        int v = i + a[i];

        if (v <= n) grp[v].push_back(i);

        v = i - a[i];

        if (v >= 1) grp[v].push_back(i);
    }

    //odd part
    bool vis[n + 1] {};
    int dis [n + 1] {};
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (parity[i]) {
            q.push(i);
            dis[i] = 0;
            vis[i] = true;
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (auto v : grp[u]) {
            if (!vis[v]) {
                dis[v] = dis[u] + 1;
                q.push(v);
                vis[v] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!parity[i]) {
            ans[i] = dis[i];
        }
        dis[i] = 0; vis[i] = false;
    }

//even part
    for (int i = 1; i <= n; i++) {
        if (parity[i] == 0) {
            q.push(i);
            vis[i] = true;
            dis[i] = 0;
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (auto v : grp[u]) {
            if (!vis[v]) {
                q.push(v);
                vis[v] = true;
                dis[v] = dis[u] + 1; 
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (parity[i]) {
            ans[i] = dis[i];
        }
    }

    //printing answer
    for (int i = 1; i <= n; i++) {
        if (ans[i]) {
            cout << ans[i] << " ";
        } else {
            cout << -1 << " ";
        }
    }
    cout << "\n";
 
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