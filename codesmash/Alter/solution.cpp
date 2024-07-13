#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n; cin >> n;

    if (n % 2 == 0) {
        for (int i = 2; i <= 2 * n; i += 2) {
            cout << i << " ";
        }
        cout << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << endl;
    }
 
}
 
int32_t main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    
    return 0;
}