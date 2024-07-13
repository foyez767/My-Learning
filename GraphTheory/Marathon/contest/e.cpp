#include<bits/stdc++.h>
#define ld long double
using namespace std;

long double x = 1.0, y, z;

bool check (long double t) {
    long double right_side = x * t * t - y - t * z;

    if (right_side <= 0) return true;
return false;
}

void solve(){
    string s1, s2, s3; cin >> s1 >> s2 >> s3;

    long double s = stoll(s1.substr(0, s1.find('m'))) * 1.0;
    long double a = stoll(s2.substr(0, s2.find('m'))) * 1.0;
    long double v = stoll(s3.substr(0, s3.find('m'))) * 1.0;

    x = 0.5 * a;
    y = s;
    z = v;

    long double lo = 0.0, hi = 1e18, ans = 0.0;

    int ite = 500;

    while (ite--) {
        long double mid = (lo + hi) / 2.0;

        if (check(mid)) {
            ans = mid;
            lo = mid;
        } else {
            hi = mid;
        }
    }
    
    cout << ans << "\n";
 
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