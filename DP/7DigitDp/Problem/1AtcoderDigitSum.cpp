#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4, modulas = 1e9 + 7;
string k;
int d;
int memo[N][2][100];

int rec(int i, bool last, int mod){
    if(k.length() == i){
        return (mod == 0);
    }
    if(memo[i][last][mod] != -1){
        return memo[i][last][mod];
    }

    int till = (last) ? (k[i] - '0') : 9;
    int ans = 0;
    for(int digits = 0; digits <= till; digits++){
        ans += rec(i + 1, (last && (digits == till)), (mod + digits) % d);
        ans %= modulas;
    }
    memo[i][last][mod] = ans;

return memo[i][last][mod];
}

void solve(){
    memset(memo, -1, sizeof(memo));

    cin >> k >> d;
    cout << (rec(0, true, 0) - 1 + modulas) % modulas << "\n";
 
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