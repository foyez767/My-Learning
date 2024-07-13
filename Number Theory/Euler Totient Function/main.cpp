#include<bits/stdc++.h>
#define int long long
using namespace std;

int count_phi (int n) {
    int ans = n;

    for (int p = 2; p * p <= n; p++) {
        if(n % p == 0) {

            while (n % p == 0) {
                n /= p;
            }

            ans -= (ans / p);
        }
    }

    if (n > 1) ans -= (ans / n);

return ans;
}

int32_t main(){
    int n; 

    while (cin >> n and n != 0) {
        cout << count_phi(n) << "\n";
    }
    

return 0;
}