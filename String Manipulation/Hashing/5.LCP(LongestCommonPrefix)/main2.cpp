//given a string S, length <= 1e5; and q query <= 1e5, in each query given four integars, l1,r1,l2,r2,
//you need to answer longest common prefix of substring [l1, r1] and [l2, r2]
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
const int P1 = 137, P2 = 277, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
 
int power(long long n,long long k, int mod){
    int ans = 1 % mod; n %= mod; if(n < 0) n += mod;
 
    while(k){
        if(k & 1) ans = (long long) ans * n % mod;
        n = (long long) n * n % mod;
        k >>= 1;
    }
return ans;
}
 
int invp1, invp2;
pair<int,int> pw[N], invpw[N];
 
void precal(){
    pw[0] = {1, 1};
 
    for(int i = 1; i < N; i++){
        pw[i].first  = 1LL * pw[i - 1].first * P1 % mod1;
        pw[i].second = 1LL * pw[i - 1].second * P2 % mod2;
    }
 
    invp1 = power(P1, mod1 - 2, mod1);
    invp2 = power(P2, mod2 - 2, mod2);
 
    invpw[0] = {1, 1};
 
    for(int i = 1; i < N; i++){
        invpw[i].first = 1LL * invpw[i - 1].first * invp1 % mod1;
        invpw[i].second = 1LL * invpw[i - 1].second * invp2 % mod2;
    }
}
 
pair<int,int> pref[N];
 
void build(string s){
    int n = s.size();
 
    for(int i = 0; i < n; i++){
        pref[i].first = 1LL * s[i] * pw[i].first % mod1;
        if(i) pref[i].first = (pref[i].first + pref[i - 1].first) % mod1;
        pref[i].second = 1LL * s[i] * pw[i].second % mod2;
        if(i) pref[i].second = (pref[i].second + pref[i - 1].second) % mod2;
    }
}
 
//substring hash
pair<int,int> getHash(int i, int j){
    assert(i <= j);
    pair<int,int> hs = {0, 0};
 
    hs.first = pref[j].first;
    if(i) hs.first = (hs.first - pref[i - 1].first + mod1) % mod1;
    hs.first = 1LL * hs.first * invpw[i].first % mod1;
 
    hs.second = pref[j].second;
    if(i) hs.second = (hs.second - pref[i -1].second + mod2) % mod2;
    hs.second = 1LL * hs.second * invpw[i].second % mod2;
return hs;
}

int lcp(int i, int j, int x, int y){
    int lo = 1, hi = min(j - i + 1, y - x + 1), ans = 0;

    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        if(getHash(i, i + mid -1) == getHash(x, x + mid - 1)){
            ans = mid;
            lo = mid + 1;
        }else {
            hi = mid - 1;
        }
    }
return ans;
}

int main(){
    precal();
    string s; cin >> s;
    build(s);

    int q; cin >> q;

    while(q--){
        int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;

        cout << lcp(l1, r1, l2, r2) << "\n";
    }

return 0;
}
/*
prefix of acb = a, ac, acb
prefix of abcde = a, ab, abc, abcd ,abcde

input:
ababaabc
3
0 2 5 7
0 2 4 6
1 2 4 6
output:
2
1
0
*/