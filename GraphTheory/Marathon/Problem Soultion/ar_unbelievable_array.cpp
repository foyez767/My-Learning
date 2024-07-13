#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 7;
int parent[N], sz[N], a[N];

void make_set (int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int findSet(int i){
    if (parent[i] == i) {
        return i;
    }
return parent[i] = findSet(parent[i]);
}

void unionSet(int x, int y){
    int a = findSet(x);
    int b = findSet(y);

    if (sz[a] < sz[b]) swap(a, b);
    if (a != b) {
        parent[b] = a;
        sz[a] += sz[b];
    }

}

void solve() {
    int n, q; cin >> n >> q;

    for (int i = 1; i <= n; i++) cin >> a[i];

    make_set(n);

    while (q--) {
        int type; cin >> type;

        if (type == 1) {
            int u, v; cin >> u >> v;
            unionSet(u, v);
        } else {
            int idx; cin >> idx;

            cout << findSet(a[idx]) << "\n";
        }
    }

    // reset(n);
 
}
 
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ":\n";
        solve();
    }
    
    return 0;
}