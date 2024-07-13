#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n; cin >> n;

    vector<int> a(n + 1, 0), prefx (n + 1, 0), sufx (n + 2, 0);

    set<int> se;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        int x = a[i];

        if (se.find(x) != se.end()) {
            prefx[i] = 0;
        } else {
            prefx[i] = 1;
            se.insert(x);
        }

        prefx[i] += prefx[i - 1];
    }

    se.clear();

    for (int i = n; i >= 1; i--) {
        if (se.find(a[i]) != se.end()) {
            sufx[i] = 0;
        } else {
            sufx[i] = 1;
            se.insert(a[i]);
        }

        sufx[i] += sufx[i + 1];
    }

    reverse(sufx.begin(), sufx.end());


    int q; cin >> q;

    while (q--) {
        int l, r; cin >> l >> r;

         int ll = n - r + 1, rr = n - l + 1;


        if ((prefx[r] == prefx[l]) and (sufx[rr] == sufx[ll])) {
            cout << -1 << " " << -1 << "\n";
        } else if (prefx[r] != prefx[l]) {
            int i = l;
            int j = lower_bound(prefx.begin(), prefx.end(), prefx[l] + 1) - prefx.begin();

            cout << i << " " << j << "\n";
        } else {
        
            int j = r;

            int i = lower_bound(sufx.begin(), sufx.end(), sufx[ll] + 1) - sufx.begin() ;

            i = n - i + 1;

            cout << min (i, j) << " " << max(i, j) << "\n";

        }
    }
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