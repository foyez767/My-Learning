#include<bits/stdc++.h>
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

void reset (int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

void solve(){
    int n; cin >> n;

    set<string> se;

    vector<pair<string, string>> edge;

    for (int i = 1; i <= n; i++) {
        string u, v; cin >> u >> v;
        edge.push_back({u, v});
        se.insert(u); se.insert(v);
    }

    map<string, int> id;

    auto it = se.begin(); int k = 1;

    while (it != se.end()) {
        id[*it] = k++;
        it++;
    }

    make_set(k);

    for (int i = 0; i < n; i++) {
        auto [u, v] = edge[i];
        
        unionSet(id[u], id[v]);

        int representive = findSet(id[u]);

        cout << sz[representive] << "\n";
    }

    reset(k);
 
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