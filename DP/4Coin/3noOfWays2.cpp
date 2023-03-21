//given n numbers and x, in how many ways we can represent x as sum of given numbers(0 to n)
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, x; cin >> n >> x;

    vector<int> coins;
    for(int i = 1; i <= n; i++){
        int u; cin >> u;
        coins.push_back(u);
    }

    ll ways[x + 1] {};
    
    ways[0] = 1;

    for(int i = 1; i <= x; i++){
        for(auto c : coins){
            if(i - c >= 0){
                ways[i] += ways[i - c] % mod;
            }
        }
    }

    cout << (ways[x] % mod) << "\n";

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