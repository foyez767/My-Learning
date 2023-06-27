//For a given string, construct all cyclic shifts, sort them lexicographically
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 7;
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

int lcp(int i, int j, int x, int y){
    int lo = 1, hi = min(j - i + 1, y - x + 1), ans = 0;

    while(lo <= hi){
        int mid = (lo + hi) >> 1;

        if(getHash(i, i + mid - 1) == getHash(x, x + mid - 1)){
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
return ans;
}

string st;
int n;

bool cmp(int u, int v){
    int i = u, j = u + n - 1;
    int x = v, y = v + n - 1;

    int lc = lcp(i, j, x, y);

    int len1 = j - i + 1, len2 = y - x + 1;

    if((len1 == len2 and lc == len1)) return true;
    else if(len2 == lc) return false;
    else if(len1 == lc) return true;
    else{
        return (st[i + lc] > st[x + lc]) ? false : true;
    }
}

void solve(){
    precal();
    cin >> st;

    n = st.length();
    int ss = 0, sf = n - 1;
    st += st;
    build(st);

    int arr[n] {};
    arr[0] = 0;

    for(int i =  1; i < n; i++){
        arr[i] = i;
    }

    sort(arr, arr + n, cmp);

    int idx = 1e8, batti = 1;
    string ans = "";

    for(int i = 0; i < n; i++){
        if(arr[i] == 0 and batti == 1){
            idx = i + 1;
            batti = 0;
        }
        ans += st[arr[i] + n - 1];
    }

    cout << idx << "\n";
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