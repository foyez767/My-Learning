#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    cout << endl;

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

    // reverse(sufx.begin(), sufx.end());

    int q; cin >> q;

    while (q--) {
        int l, r; cin >> l >> r;


        if ((prefx[r] == prefx[l]) and (sufx[r + 1] == sufx[l + 1])) {
            cout << -1 << " " << -1 << "\n";
        } else if (prefx[r] != prefx[l]) {
            int i = l;
            int j = lower_bound(prefx.begin(), prefx.end(), prefx[r]) - prefx.begin();

            cout << i << " " << j << "\n";
        } else {
            int j = r;
            

            cout << i << " " << j << "\n";
        }
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