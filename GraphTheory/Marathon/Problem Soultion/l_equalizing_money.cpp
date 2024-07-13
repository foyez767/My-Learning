#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1005;
vector<int> grp[N];
bool vis [N];
int money [N], ttl_money, ttl_people;

void dfs (int u) {
    vis[u] = true;
    ttl_money += money[u];
    ttl_people++;

    for (auto v : grp[u]) {
        if (!vis[v]) {
            dfs (v);
        }
    }
}

void Clear (int n) {
    for (int i = 1; i <= n; i++) {
        grp[i].clear();
        money[i] = 0;
        vis[i] = false;
    }
}

void solve(){
    int n, m; cin >> n >> m;

    Clear(n);

    for (int i = 1; i <= n; i++) cin >> money[i];

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }

    map<int, int> cnt;

    bool batti = true;

    int k = 0, avg_money = 0;  //number of connected components

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            k++;
            ttl_money = 0, ttl_people = 0;

            dfs (i);

            if (ttl_money % ttl_people == 0) {  
                avg_money = ttl_money / ttl_people;
                cnt[avg_money]++;
            } else {
                batti = false;
            }
        }
    }

    if (cnt[avg_money] != k) batti = false;

    (batti) ? cout << "Yes\n" : cout << "No\n";
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