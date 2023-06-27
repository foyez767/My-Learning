#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int P1 = 337, P2 = 277, mod1 = 1e9 + 7, mod2 = 1e9 + 9;

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

class Hash{
    public:
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

} ts, tr;

void solve(){
    precal();
    string s; cin >> s;
    ts.build(s);

    reverse(s.begin(), s.end());
    tr.build(s);

    int n = s.length();
    long long ttl = 0;  //in worst case: ttl can be sum of [1 to N]

    /*1st odd = 1, even = 0
      2nd odd = 3, even = 2
      3rd odd = 5, even = 4
    */

//odd length[1, 3, 5..] ***1 ? when no odd length palindrome is found which length is greater than 1, then [i] itself is a palindrome
    for(int  i = 0; i < n; i++) {
       int lo = 1, hi = min(i + 1, n - i) + 1;
        //how many substrings are palindrome which length is more than 1[3,5, 7...]
        while(hi - lo > 1) {
            int mid = (lo + hi) >> 1, l = i - mid + 1, r = i + mid - 1;

            if(ts.getHash(l, r) == tr.getHash(n - r - 1, n - l - 1)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        ttl += lo;
    }
//even length [0, 2, 4..]
    for(int i = 0; i < n - 1; i++) {
        int lo = 0, hi = min(i + 1, n - i - 1) + 1;
        //how many substring are palindrome which length is more than 0[2,4, 6...] 
        while(hi - lo > 1) {
            int mid = (lo + hi) >> 1, l = i - mid + 1, r = i + mid;
            /*why r = i + mid, not i + mid - 1? it is because in even length palindrome each character appears 
            even times, and [i] == [i + 1]
            */

            if(ts.getHash(l, r) == tr.getHash(n - r - 1, n - l - 1)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        ttl += lo;
    }

    cout << ttl << "\n";

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