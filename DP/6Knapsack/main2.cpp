//there are n coins, determines all sum that can be constructed by using the coins 
//optimal solution
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int  X = 1e5 + 3;
bool psbl [X];

void solve(){
    memset(psbl, false, sizeof(psbl));

    int n; cin >> n;

    int sum = 0;
    int arr[n + 1] {};
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    psbl[0] = true;

    for(int i = 1; i <= n; i++){
        for(int x = sum - arr[i]; x >= 0; x--){
            if(psbl[x]){
                psbl[x + arr[i]] = true;
            }
        }
    }

    vector<int> ans;
    for(int x = 1; x <= sum; x++){
        if(psbl[x]) ans.push_back(x);
    }

    cout << ans.size() << "\n";
    
    for(auto a : ans) cout << a << " "; cout << "\n";
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