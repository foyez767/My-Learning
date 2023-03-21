//given n numbers and x, in how many ways we can represent x as sum of given numbers(0 to n)
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1e9 + 7, N = 1e6 + 7;
vector<int> coins;
ll ways[N];

ll count(int n){
    if(n < 0) return 0;
    if(n == 0) return 1;

    if(ways[n] != -1){
        return ways[n];
    }
    ll ans = 0;
    for(auto c : coins){
        ans += count(n -c) % mod;
    }
    ways[n] = ans;
return ways[n];
}


void solve(){
    memset(ways, -1 ,sizeof(ways));
    int n, x; cin >> n >> x;

    for(int i = 1; i <= n; i++){
        int u; cin >> u;
        coins.push_back(u);
    }

    cout << (count(x) % mod) << "\n";
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