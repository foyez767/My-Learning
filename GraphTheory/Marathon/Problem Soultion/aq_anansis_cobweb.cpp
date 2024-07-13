#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 7;
int parent[N], sz[N];

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

void solve(){
    int n, m; cin >> n >> m;

    vector<pair<int,int>> edges;

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        edges.push_back({u, v});
    }

    int removed [m] {}, q; cin >> q;
    vector<int> queries;

    for (int i = 1; i <= q; i++) {
        int x; cin >> x; x--;
        removed[x] = 1;
        queries.push_back(x);
    }

//building initial graph
    make_set (n);
    int cnt = n;    //initially number of connected component is = n

    for (int i = 0; i < m; i++) {
        if (!removed[i]) {
            auto [u, v] = edges[i];
            
            if (findSet(u) != findSet(v)) { //if u and v are from different connected componenet, adding an edge between them decrease connected component by 1
                cnt--;
            }
            unionSet (u, v);
        }
    }

//process queries
    vector<int> ans;

    for (int i = q - 1; i >= 0; i--) {
        auto [u, v] = edges[queries[i]];

        ans.push_back(cnt);

        if (findSet(u) != findSet(v)) {
            cnt--;
        }
        unionSet(u, v);
    }

    reverse(ans.begin(), ans.end());

    for (auto a : ans) cout << a << " "; cout << "\n";

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