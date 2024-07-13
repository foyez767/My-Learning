#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 7;
int a[N];

void solve(){
    int n; cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];

    if (a[1] != 0) {
        cout << 1 << "\n";
    } else if (a[2] != 1) {
        cout << 2 << "\n";
    } else {
        int next_mex = 2;

        for (int i = 3; i <= n; i++) {
            if (a[i] > next_mex) {
               cout << i << "\n";
               return;
            } else if (a[i] == next_mex) {
                next_mex++;
            }
        }

        cout << -1 << "\n";
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