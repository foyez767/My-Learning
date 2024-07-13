//Optimisation based on path compression + by size, 
//complexity of findSet function: O(1)
//hence unionSet() time complexity is also : O(1)
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 7;
vector<tuple<int,int,int>> edgeList;
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

int32_t main(){
    int n, e; cin >> n >> e;

    for(int i = 1; i <= e; i++){
        int u, v, w; cin >> u >> v >> w;
        edgeList.push_back({w, u, v});
    }

    make_set(n);

    int ans = 0;

    sort(edgeList.begin(), edgeList.end());

    for (auto [w, u, v] : edgeList) {
        if (findSet(u) != findSet(v)) {
            unionSet(u, v);
            ans += w;
        }
    }

    bool batti = false;

    for (int i = 1; i <= n; i++) {
        batti |= (sz[i] == n);
    }

    (batti) ? cout << ans << "\n" : cout << "IMPOSSIBLE\n";


return 0;
}
