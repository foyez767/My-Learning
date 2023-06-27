//you will be given a string, and an integar k,find the length of longest substring that occurs at least
//k times in the given string
//complexity: O(logN * NlogN)
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
//hash of a string
pair<int,int> stringHash(string s){
    int n = s.size();
 
    pair<int,int> hs = {0, 0};
 
    for(int i = 0; i < n; i++){
        hs.first += 1LL * s[i] * pw[i].first % mod1;
        hs.second += 1LL * s[i] * pw[i].second % mod2;
        hs.first %= mod1;
        hs.second %= mod2;
    }
return hs;
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

int n;
//NlogN
int max_ocs(int len){
    map<pair<int,int>, int> mp;
    for(int i = 0; i + len - 1 < n; i++) {
        mp[getHash(i, i + len - 1)]++;
    }

    int ans = 0;
    for(auto m : mp){
        ans = max(ans, m.second);
    }
return ans;
}

int main(){
    string s; cin >> s; //
    int k;  cin >> k;
    precal();
    build(s);

    n = s.size();
    int lo = 1, hi = n, ans = -1;
    
    while(lo <= hi){
        int mid = (lo + hi) >> 1;

        if(max_ocs(mid) >= k) {
            ans = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    } 

    if(ans == -1) cout << "no substrings is available for at least k times";
    else cout << ans << endl;

return 0;
}