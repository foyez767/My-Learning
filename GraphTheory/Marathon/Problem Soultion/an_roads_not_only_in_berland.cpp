#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1005;
vector<int> grp[N];
int parent[N], sz[N], vis[N];

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
    vector<pair<int,int>> remove;
    vector<int> add;

    int n; cin >> n;

    make_set(n);

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        grp[u].push_back(v);
        grp[v].push_back(u);
        //checking u and v are same connected component or not. If they are from same component, means they create a cycle
        if (findSet(u) == findSet(v)) {
            remove.push_back({u, v});
        } else {
            unionSet(u, v);
        }
    }

    //unique representives for every component
    for (int i = 1; i <= n; i++) {
        add.push_back(findSet(i));
    }

    sort (add.begin(), add.end());
    add.resize(unique(add.begin(), add.end()) - add.begin());

    int day_cnt = min(add.size() - 1, remove.size());
    
    cout << day_cnt << "\n";

    for (int i = 0; i < day_cnt; i++)  {
        cout << remove[i].first << " " << remove[i].second << " " << add[i] << " " << add[i + 1] << "\n";
    }
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

/*
remove an edge that create cycle
add an edge between two vertex of different connceted components

*/