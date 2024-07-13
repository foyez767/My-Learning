#include<bits/stdc++.h>
#define int long long
#define tll tuple<int,int,int>
using namespace std;

const int N = 1e4 + 5, inf = 1e9 + 7;
vector<tuple<int,int,int>> grp[N];
int n, m, k, d, dis[N][12];

void Dijkstra (int src) {

    priority_queue<tll, vector<tll>, greater<tll>> pq;
    pq.push({0, src, 0});

    for (int i = 0; i <= d; i++) {
        dis[0][i] = 0;
    }

    while (!pq.empty()) {
        auto [dd, u, cnt] = pq.top(); pq.pop();

        if (dd > dis[u][cnt]) {
            continue;
        }

        for (auto [v, w, c] : grp[u]) {

            if (cnt + c <= d and dis[u][cnt] + w <= dis[v][cnt + c]) {
                dis[v][cnt + c] = dis[u][cnt] + w;
                pq.push({dis[v][cnt + c], v, cnt + c});
            }
        }

    }

}

void reset () {
    for (int i = 0; i < n; i++) {
        grp[i].clear();
        
        for (int j = 0; j <= d; j++) {
            dis[i][j] = inf;
        }
    }
 }

void solve(){
    cin >> n >> m >> k >> d;

    reset();

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;

        grp[u].push_back({v, w, 0});
    }

    for (int i = 1; i <= k; i++) {
        int u, v, w; cin >> u >> v >> w;

        grp[u].push_back({v, w, 1});
    }

    Dijkstra(0);

    
    int ans = inf;

    for (int i = 0; i <= d; i++) {
        ans = min (ans, dis[n - 1][i]);
    }

    (ans == inf) ? cout << "Impossible\n" : cout << ans << "\n";
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

/*
a good problem

first , take the input technically
-> we will store 3 things, u -> (v, w, cnt)
if it is an existing road, set cnt = 0
if it is a proposed road, set cnt = 1

In dijkstra function :
use a priority queue based on 3 value : weight, node, cnt -> here cnt means number of proposed road we used so far to reach `node` from source

initialize distance for all possible value of cnt (0 to d) for source node to 0.
then as usual dijkstra

*/