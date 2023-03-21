//given n coins and a value x, we need to answer minimum coins required to produce/make x
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1000, inf = 1e9;

void solve(){
    
    int n, x; cin >> n >> x;

    vector<int> coins;
    int value[x + 1] {};

    for(int i = 1; i <= n; i++){
        int u; cin >> u;
        coins.push_back(u);
    }

    value[0] = 0;

    for(int i = 1; i <= x; i++){
        value[i] = inf;
        for(auto c : coins){
            if(i - c >= 0)
                value[i] = min(value[i], value[i - c] + 1);
        }
    }

    ll ans = value[x];
    if(ans >= inf){
        cout << "-1\n";
    }else cout << ans << "\n";
   
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