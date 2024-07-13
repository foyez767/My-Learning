#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 15, inf = 10000;
int dist[N][N], memo[(1 << N)][N], n;

int rec (int mask, int i) {
    if (mask == ((1 << n) - 1)) {   // all node have been visited
        return dist[i][0];   //ending edge : I need to back from ith node to my starting node 0
    }
    if (memo[mask][i] != -1) return memo[mask][i];

    //check if any node is not visited yet!
    //if there are node that is not visited yet, visit it
    int ans = INT_MAX;

    for (int k = 0; k < n; k++) {
        if (!((mask >> k) & 1)) {   // if kth bit is 0, this means kth node is not visited yet // go from ith node to kth node
        //set kth bit
            int update_mask = mask | (1 << k);
            ans = min(ans, rec(update_mask, k) + dist[i][k]);
        }
    }

return memo[mask][i] = ans;
}

void solve(){
    memset(memo, -1, sizeof(memo));
    memset(dist, inf, sizeof(dist));

    int e;
    cin >> n >> e;

    for (int i = 1; i <= e; i++) {
        int u, v, w; cin >> u >> v >> w;
        dist[u][v] = w;
    }

    int ans = rec (1, 0);

    if (ans >= inf) cout << -1 << "\n";     //If there is no path such that by traversing each node exactly once I can return 
                                        //back to my starting node/city
    else cout << ans << "\n";

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
Theory : Given a set of cities and the distance between every pair of cities, the problem is to find the shortest 
         possible route that visits every city exactly once and returns to the starting point
//Time complexity : O(2^n * n)

*/