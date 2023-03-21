//given n coins and a value x, we need to answer minimum coins required to produce/make x
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6 + 7, inf = 1e9;
int value[N];
vector<int> coins;

ll count(int x){
    if(x < 0) return inf;
    if(x == 0) return 0;

    if(value[x] != -1){
        return value[x];
    }

    ll best = inf;
    for(auto c : coins){
        best = min(best, count(x - c) + 1);
    }

    value[x] = best;
return value[x];
}
void solve(){
    memset(value, -1, sizeof (value));
    int n, x; cin >> n >> x;

    for(int i = 1; i <= n; i++){
        int u; cin >> u;
        coins.push_back(u);
    }

    ll ans = count(x);

    if(ans >= inf) cout << "-1\n"; // Not possible
    else cout << ans << "\n";
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    
    return 0;
}