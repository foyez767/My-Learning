//complexity : O(E log(E))
#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<pair<int,int>> grp[N];
bool vis[N];

int PrimsAlgo (int src) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, src});

    int ans = 0;

    while (!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();

        if (vis[u]) {
            continue;
        }

        ans += weight;
        vis[u] = true;

        for (auto [v, w]: grp[u]) {
            if (!vis[v]) {
                pq.push({w, v});
            }
        } 
    } 

return ans;
}

int main() {
    //taking input
    int n, e; cin >> n >> e;

    for (int i = 1; i <= e; i++) {
        int u, v, w; cin >> u >> v >> w;
        grp[u].push_back({v, w});
        grp[v].push_back({u, w});
    }

    int src; cin >> src;    //source node

    int ans = PrimsAlgo(src);
    
    cout << ans << "\n";


return 0;
}

/*
8 11
1 5 2
1 4 10
1 2 4
2 4 8
2 3 18
3 4 11
4 5 5
4 7 11
4 8 9
6 7 1
6 8 2
1

ans = 34

*/