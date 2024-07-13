#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 5;
int a[N], b[N];

void solve(){
    int n; cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    int left_r = 1, right_r = n, batti = 0, i = 1;

    for (i = 1; i <= n; i++) {
        int x = b[i], batti = 0;

        for (int j = left_r; j <= n; j++) {
            if (x == a[j]) {
                batti = 1;
                left_r = j;
                break;
            }
        }

        if (!batti) {
            break;
        }
    }

    for (int j = n; j >= i; j--) {
        int x = b[j], batti = 0;

        for (int k = right_r; k > left_r; k--) {
            if (x == a[k]) {
                batti = 1;
                right_r = k;
                break;
            }
        }

        if (!batti) {
            break;
        }
    }

    cout << (right_r - left_r + 1) << "\n";






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