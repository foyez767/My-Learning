#include<bits/stdc++.h>
#define int long long
#define pll pair<int,int>
using namespace std;

const int N = 3005, inf = 1e18;
vector<pair<int,int>> grp[N];

void solve(){
    int n, e; cin >> n >> e;

    for(int i = 1; i <= e; i++){
        int u, v, w; cin >> u >> v >> w;
        //undirected graph
        grp[u].push_back({v,w});
        // grp[v].push_back({u, w});
    }

    int src; cin >> src;    //source node

//Dijkstra
    vector<int> dis(n + 1, inf);
    priority_queue<pll, vector<pll>, greater<pll>> q;
    dis[src] = 0;
    q.push({0, src});

    while(!q.empty()){
        pair<int,int> p = q.top();
        q.pop();
        int u = p.second;

        int d = p.first;

        if (d > dis[u]) {
            //for undirected graph, this portion is required
            continue;
        }

        for(auto x : grp[u]){
            auto [v, w] = x;

            if(dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                q.push({dis[v],v}); 
            }
        }
    }

    //printing distance
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
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
