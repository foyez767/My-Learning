//there are n coins, determines all sum that can be constructed by using the coins 
//complexity : O(n * m) where n = no of coins, m = maximum total sum
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 103, X = 1e5 + 3;
bool psbl [N][X];

void solve(){
    memset(psbl, false, sizeof(psbl));

    int n; cin >> n;

    int sum = 0;
    int arr[n + 1] {};
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    psbl[0][0] = true;  // if no coin is choosen then we can construct 0

    for(int i = 1; i <= n; i++){
        for(int x = 0; x <= sum; x++){
            if(x - arr[i] >= 0){
                psbl[i][x] |= psbl[i - 1][x - arr[i]];  //if ith coin is taken
            }
            psbl[i][x] |= psbl[i - 1][x];   //if ith coin is not taken
        }
    }

    int cnt = 0;
    vector<int> ans;

    for(int x = 1; x <= sum; x++){
        if(psbl[n][x]){
            ans.push_back(x);
        }
    }
    //no of differet sum that can be produced
    cout << ans.size() << "\n";
    //all sum that can be produced
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