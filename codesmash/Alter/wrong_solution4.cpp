#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n; cin >> n;

    int cnt = 1, ans = 0;
    bool ok = true;

    if (n % 2 == 0) {
        for (int i = 2; cnt <= n; cnt++, i += 2) {
            cout << 0 << " ";
            ans += i;

            if (i % cnt != 0) {
                ok = false;
            }
        }
        cout << "\n";
    } else {
        for (int i = 5; cnt <= n; i += 5, cnt++) {
            cout << 0 << " ";
            ans += i;

            if (i % cnt != 0) {
                ok = false;
            }
        }
        cout << "\n";
    }
 
    if (ans % n != 0) {
        ok = false;
    }

    // if (!ok) {
    //     cout << "Wrong answer\n";
    // }
}
 
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    
    return 0;
}