#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int a; cin >> a;

    long double y = 0.2929 * sqrt(2) * a;
    long double x = y / sqrt(2);
    long double u = sqrt(2) * a - y;
    long double area = 0.25 * 3.141567 * (u * u);

    cout << fixed << setprecision(4);
    cout << ((a * a - area - x * x) / 2) << "\n";
 
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