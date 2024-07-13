#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;

    int grp [n + 1][n + 1] {};

    for (int i = 1; i <= n; i++) {
        int u, k; cin >> u >> k;  // k = number of adjacent element

        for (int j = 1; j <= k; j++) {
            int v; cin >> v;

            grp[u][v] = 1;
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < n; j++) {
            cout << grp[i][j] << " ";
        }
        cout << grp[i][n] << "\n";
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