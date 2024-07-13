#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 7;
vector<int> spf(N, 0);

void smallestPF() {
    for(int i = 1; i < N ; i++) spf[i] = i;
    for(int i = 2; i * i < N; i++){
        if(spf[i] == i) {
            for(int j = i * i ; j < N; j += i)
                spf[j] = i;
        }
    } 
}

int primeFactor(int n) {
    map<int,int> npf;

    while (n != spf[n]) {
        npf[spf[n]]++;
        n = spf[n];
    }

    int cnt = npf.size() % 2;
    int cnt2 = 1;

    for (auto c : npf) {
        cnt2 *= (c.second + 1);
    }

    cnt2 %= 2;

return (cnt == cnt2);
}

// const int N = 1e6 + 7;
int pref[N];

void precal () {
    for (int i = 1; i < N; i++) {
        if(primeFactor(i)) {
            pref[i] = 1;
        }
    }

    for (int i = 1; i < N; i++) {
        pref[i] += pref[i - 1];
    }
}


void solve() {
    int l, r; cin >> l >> r;

    cout << (pref[r] - pref[l - 1]) << "\n";

 
}
 
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    smallestPF();
    precal();

    // cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    
    return 0;
}