#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 7;
vector<pair<int,int>> grp[N];
bool vis[N];
int dog_cnt [N], dog_cnt_init[N], dog_cnt_end[N], node, max_dog;

void dfs (int u) {
    vis[u] = true;

    if (dog_cnt[u] > max_dog) {
        max_dog = dog_cnt[u];
        node = u;
    }

    for (auto [v, w] : grp[u]) {
        if (!vis[v]) {
            dog_cnt[v] = dog_cnt[u] + w;
            dfs (v);
        }
    }
}

void dfs2 (int u) {
    vis[u] = true;

    if (dog_cnt_init[u] > max_dog) {
            max_dog = dog_cnt_init[u];
            node = u;
    }

    for (auto [v, w]: grp[u]) {
        if (!vis[v]) {
            dog_cnt_init[v] = dog_cnt_init[u] + w;
            dfs2 (v);
        }
    }
}

void dfs3 (int u) {
    vis[u] = true;

    for (auto [v, w]: grp[u]) {
        if (!vis[v]) {
            dog_cnt_end[v] = dog_cnt_end[u] + w;
            dfs3 (v);
        }
    }
}

void Clear (int n) {
    for (int i = 1; i <= n; i++) {
        vis[i] = false;
    }
}

void solve(){
    node = -1, max_dog = -1;

    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        dog_cnt[i] = dog_cnt_init[i] = dog_cnt_end[i] = 0;
    }

    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        grp[u].push_back({v, w});
        grp[v].push_back({u, w});
    }

    Clear(n);
    dfs (1);

    Clear (n);
    max_dog = -1;
    dfs2 (node);

    Clear (n);
    dfs3 (node);

    for (int i = 1; i <= n; i++) {
        cout << max (dog_cnt_init[i], dog_cnt_end[i]) << " \n " [i == n];
        grp[i].clear();
    }
    
}
 
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    
    return 0;
}

/*
very good problem

1st dfs finds the one end of the diameter
2nd dfs finds the other end of the diameter along with number of dogs will eagle see if starts from one end of the diameter
3rd dfs finds the number of dogs will eagle see if starts from other end of the diameter

To maximise number of dogs, eagle need to finish his walk at the end of the diameter
*/