#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;

    string a, b; cin >> a >> b;

    int i = 0, j = 0, k = 0;

    for (; j < m; j++) {

        if (i >= n) {
            break;
        }

        for (; j < m; j++) {
            if (b[j] == a[i]) {
                k++;
                i++;
                break;
            }
        }
    }

    cout << k << "\n";
 
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